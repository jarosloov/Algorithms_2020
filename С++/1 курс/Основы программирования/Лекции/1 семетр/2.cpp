#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
 
	double v,a,t,x,y,n,p,z;
 
	const double G = 9.80665;
	cin >>v>>a>>t;
        a = (a*3.1415)/180;
        cout<<"Получаем координаты:"<<endl;
        z=t/45;
        p=t;
        t=z;
 
        while(t<=p){
        x=v*t*cos(a);
        y=(v*t*sin(a))-((G*pow(t, 2))/2);	
	if(y>0){
       cout<<" X="<<x<<" "<<" Y="<<y<<"\n";
        }
        else {
         x=pow(v, 2)*sin(2*a)/G;
         cout<<" X="<<x<<" "<<" Y=0"<<"\n";	
        }
        t=t+z;
      } 
	return 0;
}