//Финальное задание - метод стрельбы
//тут вводим n(кол-во разбиений) с консоли
//тест отрабатывает при n = 11
#include <iostream> 
#include <cmath>
#include <vector> 
#include <gtest/gtest.h>

#include "shoot.cpp"

std::vector<double> res;


TEST(shootTests,values)
{
	std::vector<double> testVec = 
	{
		{2.0}, {2.03669}, {2.07105}, {2.10111}, {2.12478}, {2.13979}, {2.14374}, {2.13416}, {2.10856}, {2.06457}, {2.0} 
	};
	
	for(int i = 0; i < 11; i++)
	{
		ASSERT_LT(abs(res[i] - testVec[i]), 1e-2);
	}
}


int main (int argc, char* argv[])
{
	if (argc < 5)
	{
		std::cout << "No arguments" << "\n";
		return 1;
	}
	
	int n;
	double m, left, right;

	try
	{
		n = std :: stod(argv[1]);
		m = std :: stod(argv[2]);
		left = std :: stod(argv[3]);
		right = std :: stod(argv[4]);

	}
	catch(...)
	{
		std::cout << "Not able to parse arguments" << "\n";
		return 1;
	}
	
	
	//int n = 11;
	double h = 1.0/(n-1);
	
	std::vector<double> y(n);
	std::vector<double> z(n);
	
	double ksi = 10.0;
	double min = 10.0;
	for (double i = left; i < right; i += m)
	{
		double k = fabs(shoot(i, h, n, y, z));
		if (k < min)
		{
			min = k;
			ksi = i;
		}
	}
	
	std::cout << "ksi = " << ksi << "\n";
	
	double temp = shoot(ksi, h, n, y, z);
	std::cout << "shoot = " << temp << "\n";

	if (fabs(temp) > 1.0) 
	{
		std::cout << "Bad boundaries or step" << "\n";
		return -1;
	}
	else
	{
		for (int i = 0; i != n - 1; i++)
		{
			std::cout << "x[" << i + 1 << "]= " << (i+1)*h << " y[" << i + 1 << "]= " << y[i+1] << "\n";
			res = y;
			::testing::InitGoogleTest();
		} 
	}
	
	return RUN_ALL_TESTS();
	
}
