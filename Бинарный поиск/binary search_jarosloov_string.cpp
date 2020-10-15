#include <iostream>

using namespace std;

void binary_search(string array[], int len, string element) {
    int low = 0;
    int high = len;

    while (low <= high) {
        int mid = (low + high) / 2;
        string guess = array[mid];
        if (guess == element) {
            cout << "Element found under index: " << mid << endl;
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

    string array[] = { "Arik", "Marik", "Zarik"};
    int len = sizeof(array)/sizeof(array);
    binary_search(array, len, "Marik");


    return 0;
}