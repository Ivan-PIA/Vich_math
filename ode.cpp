#include <iostream>
using namespace std;

float equation(float x, float y) {

   return (x + y);
}

void solveEquationEulers(float x0, float y, float h, float x) {

   float temp = 0.0;

   while (x0 < x) {
      temp = y;
      y = y + h * equation(x0, y);
      x0 = x0 + h;
   }
   cout<<"The solution of the differential equation at x = "<< x <<" is f(x, y) = "<<y;
}

int main()
{
   float x0 = 0;
   float y0 = 1;
   float h = 0.1;
   float x = 0.5;
   solveEquationEulers(x0, y0, h, x);
   return 0;
}