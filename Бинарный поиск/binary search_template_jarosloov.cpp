#include <iostream>
#include <string>

using namespace std;

template <typename T>
size_t binary_search(T array[], size_t len, T element) {
    size_t low = 0;
    size_t high = len;
    
    while (low <= high) {
        size_t mid = (low + high) / 2;
        T guess = array[mid];
        if (guess == element)       
            return mid;
        if (guess > element)         
            high = mid - 1;         
        else
            low = mid + 1;          
    }
    cout << "Mistake!" << endl;
    return -1;
	
}

int main() {

    int array_1[] = { 1,2,3,4,5 };
    int len_1 = sizeof(array_1) / sizeof(int);

    double array_2[] = { 0.1, 0.2, 5.5, 6.6, 7.4 };
    int len_2 = sizeof(array_2) / sizeof(double);

    string array_3[] = { "Arik", "Marik", "Zarik" };
    int len_3 = sizeof(array_3) / sizeof(string);
    cout << "Element found under index: " << binary_search(array_1, len_1, 5) << endl;
    cout << "Element found under index: " << binary_search(array_2, len_2, 5.5) << endl;
    cout << "Element found under index: " << binary_search(array_3, len_3, string("Marik")) << endl; // Правильный вариант!!!
}
