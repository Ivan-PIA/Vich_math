#include <iostream>
using namespace std;

struct Data { double x, y; };

double u_cal (double u, int n) {
 double temp = u;
 for (int i = 1; i < n; i++) 
       temp *= (u - i);
 return temp;
}

double fact(int n) {
 double f = 1;
 for (int i = 2; i <= n; i++) f *= i;
 return f;
}

int main() {
 //Количество исходных точек:
 const int n = 4;
 //Исходные значения (x,y):
 Data f[n] = { 
  { 1, 0.4 },
  { 2, 3.2 },
  { 3, 10.8},
  { 4, 25.6 } 
 }; 
 //Таблица конечных разностей (вперёд)
 double y[n][n];
 for (int i = 0; i < n; i++) y[i][0]=f[i].y;
 for (int i = 1; i < n; i++) {
  for (int j = 0; j < n - i; j++) y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
 }
 //Вывод таблицы значений от x1 до x2 с шагом dx:
 double x1 = 1,
        x2 = 2.5,
        dx = 0.5;
 cout.width(20); cout << "X"; cout.width(20); cout << "Y" << endl;
 for (double x = x1; x <= x2; x += dx) {
  double sum = y[0][0];
  double u = (x - f[0].x) / (f[1].x - f[0].x);
  for (int i = 1; i < n; i++) {
   sum += (u_cal(u, i) * y[0][i]) / fact(i);
  }
  cout.width(20); cout.precision(5); cout << x;
  cout.width(20); cout.precision(3); cout << sum << endl;
 }

 
 return 0;
}