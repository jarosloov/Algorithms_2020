// Если выписать все натуральные числа меньше 10, кратные 3 или 5,
// то получим 3, 5, 6 и 9. Сумма этих чисел равна 23.

//Найдите сумму всех чисел меньше 1000, кратных 3 или 5.

// https://projecteuler.net/problem=1

#include <iostream>

using namespace std;

int main()
{
	size_t sum = 0;
	for (size_t i = 1; i < 1000; ++i)
		if ((i % 3 == 0) || (i % 5 == 0))
			sum += i;
	cout << sum;
	return 0;
}