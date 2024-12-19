#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>

using namespace std;

double fun(double x)
{
	return (0.5 * log(x));
}

double Sn0(double x, int n)
{
	
	return pow(-1, n - 1) * pow(x - 1, n)/n;
}

double Se0(double x, double e)
{
	double sum = 0.0;
	double term = 0.0;
	int n = 1;

	do
	{
		term = Sn0(x, n);
		sum += term;
		n++;
	}	while (fabs(term) > e);
	return 0.5 * sum;
}

int main()
{
	double a = 0.2;
	double b = 1.0;
	int k = 10;
	double e = 0.0001;
	double step = (b - a) / k;

	cout << fixed << setprecision(10);
	for (double x = a; x <= b; x += step)
	{
		double sn = 0.0;
		double f = fun(x);
		double se = Se0(x, e);
		for (int n = 1; n <= 10; ++n)
		{
			sn += Sn0(x, n);
		}
		cout << " x: " << x << " y: " << f << " Sn: " << sn*0.5 << " Se: " << se << endl;
	}
	return 0;
}