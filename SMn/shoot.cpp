#include <iostream> 
#include <cmath>
#include <vector> 

double shoot(double ksi, double h, int n, std::vector<double>& y, std::vector<double>& z)
{
	z[0] = ksi;
	y[0] = 2.0;
	
	for (int i = 0; i != n - 1; i++)
	{
		double y_1 = y[i] + 0.5*h*z[i];
		double z_1 = z[i] + 0.5*h*(-sqrt(i*h)*z[i] - (i*h)*(i*h)*y[i] - i*h);
		y[i+1] = y[i] + h*z_1;
		z[i+1] = z[i] + h*(-sqrt(i*h + 0.5*h)*z_1 - (i*h + 0.5*h)*(i*h + 0.5*h)*y_1 - (i*h + 0.5*h));
	}
	
	std::cout << "\n";
	
	return y[n-1] - 2.0;
}
