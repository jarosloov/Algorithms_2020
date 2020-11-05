#include <iostream>
#include <ctime>
using namespace std;



size_t randd(){
    time_t now = time(0);
    now *=now;                  // можно и без этого.
    return now;
}

size_t randd_standart(){
    size_t a = rand();
    return a;
}

int main()
{
    size_t test = 0;
    unsigned int start_time =  clock();
    cout<< randd_standart()%100 <<endl;
    unsigned int end_time = clock();
    cout<< " Стандарт. Время работы: " << end_time - start_time <<endl <<endl <<endl;
    
    

    start_time =  clock();
    cout<< randd()%100 <<endl;
    end_time = clock();
    cout<< "Моя. Время работы: " << end_time - start_time <<endl <<endl <<endl;
    return 0;
}

