using UnityEngine;
using UnityEngine.UI;

public class Scroll : MonoBehaviour
{
    [Range(1, 50)]                  // бегунок  от 1 до 50
    [Header("Controllers")]         // жирный заголовок
    public int panCount;            // количество понелек 
    [Range(0, 500)]
    public int panOffset;           // растояние между понельками
    [Range(0f, 20f)]
    public float snapSpeed;         // время перехода от одной панельки к другой
    [Range(0f, 10f)]
    public float scaleOffset;       // на сколько уменьшить следуюший и предыдущий квадратик
    [Range(1f, 20f)]
    public float scaleSpeed;        // скорость изменения рамера
    [Header("Other Objects")]
    public GameObject panPrefab;    // префаб табличке 
    public ScrollRect scrollRect;   // подключение волны ( инерция) 

    private GameObject[] instPans;  // мосив понелек
    private Vector2[] pansPos;       // мосив где хранятся координты понелек
    private Vector2[] pansScale;        // храним размеры панелек

    private RectTransform contentRect; // для простотра центра
    private Vector2 contentVector;     // для отптимизации 

    private int selectedPanID; // ID понельки (для переключения сцен)
    private bool isScrolling;  // а мы скролим?

    private void Start()
    {
        contentRect = GetComponent<RectTransform>();    // просто берем компанет
        instPans = new GameObject[panCount];            // задем размер масиву 
        pansPos = new Vector2[panCount];                // задем размер масиву 
        pansScale = new Vector2[panCount];

        for (int i = 0; i < panCount; i++)              // создание объектов 
        {
            instPans[i] = Instantiate(panPrefab, transform, false);     // содаём объект
            if (i == 0) continue;
            instPans[i].transform.localPosition = new Vector2(instPans[i - 1].transform.localPosition.x + panPrefab.GetComponent<RectTransform>().sizeDelta.x + panOffset,
                instPans[i].transform.localPosition.y);             // меняем позицию новой понельки 
            pansPos[i] = -instPans[i].transform.localPosition;      //ЗАПИСЫВАЕМ КООРДИНАТЫ
        }
    }

    private void FixedUpdate()  // ОБНОВЛЯЕТСЯ КАКЖДЫЙ КАДР (Ф П С)
    {
        // Проверка чтобы не улетало в ЕБЕНЯЯЯ!!!
        if (contentRect.anchoredPosition.x >= pansPos[0].x && !isScrolling || contentRect.anchoredPosition.x <= pansPos[pansPos.Length - 1].x && !isScrolling)
            scrollRect.inertia = false;
        float nearestPos = float.MaxValue;      //ближайшая позицая, сначала берем как МАХ 
        for (int i = 0; i < panCount; i++)      // перебираем панельки 
        {
            float distance = Mathf.Abs(contentRect.anchoredPosition.x - pansPos[i].x); // смотри что в центре
            if (distance < nearestPos) // проверяем что дистанция меньшь большой дистанции
            {
                nearestPos = distance;
                selectedPanID = i;   // присваевам ID
            }

            // изменяем размер
            float scale = Mathf.Clamp(1 / (distance / panOffset) * scaleOffset, 0.5f, 1f);
            pansScale[i].x = Mathf.SmoothStep(instPans[i].transform.localScale.x, scale + 0.3f, scaleSpeed * Time.fixedDeltaTime);      // изменяем размеры по Х
            pansScale[i].y = Mathf.SmoothStep(instPans[i].transform.localScale.y, scale + 0.3f, scaleSpeed * Time.fixedDeltaTime);      // изменяем размеры по У    
            instPans[i].transform.localScale = pansScale[i];
        }

        // отключение инерции 
        float scrollVelocity = Mathf.Abs(scrollRect.velocity.x);
        if (scrollVelocity < 400 && !isScrolling) scrollRect.inertia = false;
        if (isScrolling || scrollVelocity > 400) return;
        contentVector.x = Mathf.SmoothStep(contentRect.anchoredPosition.x, pansPos[selectedPanID].x, snapSpeed * Time.fixedDeltaTime);
        contentRect.anchoredPosition = contentVector;
    }

    public void Scrolling(bool scroll)  // проверяем с кролим мы или нет
    {
        isScrolling = scroll;
        if (scroll) scrollRect.inertia = true;
    }
}

