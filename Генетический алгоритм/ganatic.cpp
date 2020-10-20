#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double func(double x)
{
    return sin(M_PI * x / 180) - 1 / x;
}
double mutation(double x0, double x1)  // мутация: генерация случайной величины
{
    const int NUM = 100000000;
    return fabs((double)((rand() * NUM) % (int)((x1 - x0) * NUM) + 1) / NUM) + x0;
}
double inversion(double x, double eps)  // инверсия: поиск в окрестностях точки
{
    static int sign = 0;
    sign++;
    sign %= 2;
    if (sign == 0) return x - eps;
    else return x + eps;
}
void crossover(double* x, double eps, double x0, double x1)  // кроссовер: среднее арифметическое
{
    int k = 99;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++){
            x[k] = (x[i] + x[j]) / 2;
            k--;
        }
    }
        
    for (int i = 0; i < 8; i++)
    {
        x[k] = inversion(x[i], eps); 
        k--;
        x[k] = inversion(x[i], eps); 
        k--;
    }
    for (int i = 8; i < k; i++)
        x[i] = mutation(x0, x1);
}
void sort(double* x, double* y)  // сортировка
{
    for (int i = 0; i < 100; i++)
        for (int j = i + 1; j < 100; j++)
            if (fabs(y[j]) < fabs(y[i])) {
                double temp = y[i];
                y[i] = y[j];
                y[j] = temp;
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
}
double genetic(double x0, double x1, double eps)  // поиск решения с использованием Генетического Алгоритма
{
    double population[100];
    double f[100];
    int iter = 0;
    for (int i = 0; i < 100; i++)   // Формирование начальной популяции
    {
        population[i] = mutation(x0, x1);
        f[i] = func(population[i]);
    }
    sort(population, f);
    do {
        iter++;
        crossover(population, eps, x0, x1);
        for (int i = 0; i < 100; i++)
            f[i] = func(population[i]);
        sort(population, f);
    } while (fabs(f[0]) > eps && iter < 20000);
    cout << iter << " iterations" << endl;
    return population[0];
}
int main()
{
    srand(time(NULL));
    cout << genetic(1.0, 20.0, 0.000001);
    cin.get();
    return 0;
}
