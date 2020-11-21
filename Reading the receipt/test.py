import cv2
import pytesseract

try:
    img = cv2.imread('chek.jpg', cv2.COLOR_BGR2RGB)
    print(pytesseract.image_to_string(img, config=r'--oem 3 --psm 6'))
except:
    print("Ошибка")
