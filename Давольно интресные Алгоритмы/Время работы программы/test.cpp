// Как найти время работы фрагмента кода?
 
// заголовочный файл с прототипом функции clock()
    #include <ctime>

  unsigned int start_time =  clock(); // начальное время
//         ...
//      сам код
//         ...
  unsigned int end_time = clock(); // конечное время
  unsigned int search_time = end_time - start_time; // искомое время
