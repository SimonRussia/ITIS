// #include "merge.hpp"
// #include "message.hpp"
// #include <random>
// #include <iterator>

#include <bitset>
#include <iostream>
#include <vector>




// функция составления двоичных комбинаций 2^4
void binary(std::vector<std::vector<double> > & xt)
{
	for (int i = 0; i < 16; i++)
	{
		std::bitset<4> bin(i);

		// for (int j = 3; j >= 0; j--)
		// {
		// 	std::cout << bin[j] << " ";
		// 	xt[i].push_back( bin[j] );
		// }

		for (int j = 0; j < 4; j++)
		{
			std::cout << bin[j] << " ";
			xt[i].push_back( bin[j] );
		}

		std::cout << std::endl;
	}
}

// расчет функции y 
void true_foo(std::vector<std::vector<double> > & xt, std::vector<double> & yt;)
{
	ddd
}


int main(int argc, char const *argv[])
{
	
	// вектор комбинаций x1 x2 x3 x4 (двумерный вектор) (16) (x0 = 1) (x[@][i] = Xi)
	std::vector<std::vector<double> > x (16);
	binary(x);
	// std::cout << std::endl << x[14][3] << " " << x[14][2] << " " << x[14][1] << " " << x[14][0] << " " << std::endl;

	// вектор истинных значений y (двумерный вектор) (16)
	std::vector<double> true_y;

	// вектор весовых коэффициентов (5)
	std::vector<double> w;

	// Выходной вектор функциии (2^4)
	std::vector<double> y;

	std::cout << "******* OK *******" << std::endl;


	return 0;
}




/*
void add (int n, std::vector<int>& vec){
    vec.push_back(n);
}

std::vector <int> myVec;
add(5, myVec);
*/
