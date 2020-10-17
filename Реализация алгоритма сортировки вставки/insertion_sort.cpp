/// Реализация алгоритма сортировки вставки ///

#include <iostream>
using namespace std;

void insertion_sort(int array[], int n){
  for(int i = 0; i < n; i++){
    int j = i;
    while((j > 0) && (array[j] < array[j-1])){
        swap(array[j] ,array[j-1]);
        j-=i; 
    }
  }
}

int main() {
  //////////////ТЕСТ//////////////
  int array[] = {1,2,5,4,6,7,15,0,8,13};
  int len = sizeof(array) / sizeof(int);
  cout << "Элементы массива:"<< '\t';
  for(int i = 1; i < len; ++i){
    cout << array[i]<< ' ';
  }
  cout << endl << endl;
  insertion_sort(array, len);
  cout << "Новые элементы массива :"<< '\t';
  for(int i = 1; i < len; ++i){
    cout << array[i]<< ' ';
  }
  cout << endl;
}

//jarosloov//
