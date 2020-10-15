#include <iostream>
#include <fstream>

using namespace std;

void binary_search(int array[], int len, int element) {
    int low = 0;
    int high = len;

    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = array[mid];
        if (guess == element) {
            cout << "Element found under index:: " << mid << endl;
            return;
        }
        if (guess > element)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "Mistake!" << endl;
    return;
}

int main() {

    ifstream fin("test.txt");
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n"; 
    else{
        int array[6];
        for (size_t i = 0; i < 6; i++)
           fin >> array[i];
        binary_search(array, 6, 5);
    }
    return 0;
}
