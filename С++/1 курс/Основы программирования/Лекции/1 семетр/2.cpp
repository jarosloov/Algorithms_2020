#include <iostream>
#include <cmath>
using namespace std;

void coordinates(double totalTime, double clone_totalTime, double speed, double corner)
{
        const double G = 9.80665;       // постоянная 
        double x = 0;
        double y = 0;
        double zero_time = 0;
        cout << "Получаем координаты:" << endl;
        while(zero_time <= clone_totalTime)
        {
                x = speed * zero_time * cos(corner);
                y = (speed * zero_time * sin(corner)) - (( G * pow(zero_time, 2)) / 2);	
	        if(y > 0)
                {
                        cout<<" X=" << x << " " << " Y=" << y << endl;
                }
                        else {
                                x = pow(speed, 2) * sin(2 * corner) / G;
                                cout << " X=" << x << " " << " Y=0" << endl;	
                        }
                zero_time += totalTime;
      } 
}


int main() 
{
 
	double speed, corner, totalTime, n, clone_totalTime, zero_time;
        int time;
 
	cin >> speed;                           // вводим скорость
        cin >> corner;                          // вводим угол под которм брошено тело
        cin >> totalTime;                       // вводим время полёта
        corner = (corner * 3.1415) / 180;       // переводим градусы в радианы, потому что sin и cos считают в радианах

        clone_totalTime = totalTime;

        cout << "Введите число, на сколько промежутков вы хотите разделить время" << endl;
        cin >> time;
        totalTime = totalTime / time;
        coordinates(totalTime,  clone_totalTime,  speed, corner);

	return 0;
}