				//-- Задача номер два --//

/*
	RU: Найдите сумму всех четных элементов ряда Фибоначчи, 
			которые не превышают четыре миллиона.
*/

#include <iostream>

using namespace std;

int main() {
	size_t  sum = 0, first = 1, second = 2 ;
	while (second <= 4000000) {      // чтобы последнее число было не больше 4 лимонов 
		size_t temporary;
		if (first % 2 == 0)           // если число делится на 2 без отстатка, 
			sum = first;               // то закинуть его в копилку sum
		temporary = first + second;   // находим третье число Фибоначи
		first = second;               // первому числу присваевымаем второе
		second = temporary;           // втророму числу присваевымаем третье
	}
	cout << "sum = " << sum;		   // " sum = 832040 "
}

// Jarosloov //