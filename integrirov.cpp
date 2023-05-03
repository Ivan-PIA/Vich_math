
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

typedef double(*pointFunc)(double);



double f(double x) {
  return (10 - x);
}
double rectangle_integral(pointFunc f, double a, double b, int n) {
  double x, h;
  double sum = 0.0;
  double fx;
  h = (b - a) / n;  
  
  for (int i = 0; i < n; i++) {
    x = a + i*h;
    fx = f(x);
    sum += fx;
  }
  return (sum * h); 
                    
}
int main(){
  double a, b, eps;
  double s1, s;
  int n = 1; 
  
  cout << "Введите левую границу интегрирования a = ";
  cin >> a;
  cout << "\nВведите правую границу интегрирования b = ";
  cin >> b;
  cout << "\nВведите требуемую точность eps = ";
  cin >> eps;
  s1 = rectangle_integral(f, a, b, n);
  do {
    s = s1;    
    n = 2 * n;  
   
    s1 = rectangle_integral(f, a, b, n);
  }
  while (fabs(s1 - s) > eps);  
  cout << "\nИнтеграл = " << s1 << endl;
}