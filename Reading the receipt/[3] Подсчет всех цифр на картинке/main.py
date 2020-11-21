import cv2
import pytesseract

try:
    img = cv2.imread('[0-9].jpg', cv2.COLOR_BGR2RGB)
    list_num = []
    text = pytesseract.image_to_string(img, config=r'--oem 3 --psm 6')
    print("Всё что считалось: ")
    print(text)
    for i in text:
        try:
            num = int(i)
            list_num.append(num)
        except ValueError:
            continue
    print("Вывод найденых на каринке цифр")
    print(list_num)
    sum = 0
    for i in list_num:
        sum += i
    print("Сумма всех найденых цифр: " + str(sum))
    sum = 1     #ну и тут чтобы ответ не был равен 0
    for i in list_num:
        if i == 0:
            continue
        sum *= i
    print("Произведение всех найденых цифр: " + str(sum))
    # тут ответ будет "0", но я исключил 0, чтобы получился поблее менее красивый ответ
except:
    print("Ошибка")

