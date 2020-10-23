# Бинарный поиск
def binary_search(array, target):
    low = 0
    high = len(array) - 1

    while low <= high:
        middle_element = (low + high) // 2
        guess = array[middle_element]

        if guess < target:
            low = middle_element + 1
        elif guess > target:
            high = middle_element - 1
        else:
            return middle_element

    return None        

    # Проверка
my_list = [1,3,5,7,9]

print (binary_search(my_list, 3))
print (binary_search(my_list, -1))