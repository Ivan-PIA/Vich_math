#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int k = 0;
int i, j, n = 4, l;
double xmas[25],p[25], p1[25], p2[25], x, t, y[100], h = 1;

double func(double t) {
	t = pow(t,3)+2;
	return t;
}

void Etken(double x)
{
	for (k = 0; k < n - 1; ++k) {
		l = k + 1;
		p[k] = ((y[k] * (x - xmas[l]) - y[l] * (x - xmas[k])) / (xmas[k] - xmas[l]));
	}


	for (k = 0; k < n - 2; ++k) {
		l = k + 2;
		p1[k] = ((p[k] * (x - xmas[l]) - p[k + 1] * (x - xmas[k])) / (xmas[k] - xmas[l]));
	}

	for (k = 0; k < n - 3; ++k) {
		l = k + 3;
		p2[k] = ((p1[k] * (x - xmas[l]) - p1[k + 1] * (x - xmas[k])) / (xmas[k] - xmas[l]));
	}
}


int main(int argc, char** argv)
{
	cout << "Input first X" << endl;
	
	cin >> xmas[0];

	for (i = 0; i < n; i++) 
	{
		xmas[i+1] = xmas[i] + h;
		y[i] = func(xmas[i]);
		cout << xmas[i] << "\t" << y[i] << endl;
		
		
	}
	
	

	cout << "\nInput X" << endl;
	cin >> x;

	
	

	Etken(x);
	
	for (i = 0; i < n - 1; ++i) 
	{
		cout << "\n" << p[i];
	}
	cout << "\n" << "\n______________";

	for (i = 0; i < n - 2; ++i) 
	{
		cout << "\n"<<p1[i];
	}

	cout << "\n" << "\n______________";

	for (i = 0; i < n - 3; ++i) 
	{
		cout << "\n" << p2[i];
	}

	return 0;
}