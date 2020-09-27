#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
 
	double speed, corner, t, x, y, n, p, z;
 
	const double G = 9.80665;
	cin >>speed>>corner>>t;
        corner = (corner*3.1415)/180;
        cout << "Получаем координаты:" << endl;
        z=t/45;
        p=t;
        t=z;
 
        while(t<=p){
        x=speed*t*cos(corner);
        y=(speed*t*sin(corner))-((G*pow(t, 2))/2);	
	if(y>0){
       cout<<" X="<<x<<" "<<" Y="<<y<<"\n";
        }
        else {
         x = pow(speed, 2)*sin(2*corner)/G;
         cout<<" X="<<x<<" "<<" Y=0"<<"\n";	
        }
        t=t+z;
      } 
	return 0;
}