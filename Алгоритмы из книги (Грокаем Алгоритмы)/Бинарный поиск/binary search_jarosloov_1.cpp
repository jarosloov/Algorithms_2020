#include <iostream>

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

    int array[] = { 1,2,3,4,5,6,7,8,9,10,100 };
    int len = sizeof(array) / sizeof(int);
    binary_search(array, len, 5);


    return 0;
}