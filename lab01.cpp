#include <iostream>
#include <vector>
#include <bitset>

// Функция составления двоичных комбинаций 2^4
void binary(std::vector<std::vector<double> > & xt);

// Функция построения таблицы истинности.
void true_foo(std::vector<std::vector<double> > & xt, std::vector<double> & yt);

void print_y(std::vector<std::vector<double> > const & xt, std::vector<double> const & yt);


int main(int argc, char const *argv[])
{

	double delta = 0;
	double nu = 0.3;
	double dFoo = 1;
	
	// вектор комбинаций x1 x2 x3 x4 (двумерный вектор) (16) (x0 = 1) (x[@][i] = Xi)
	std::vector<std::vector<double> > x (16);
	binary(x);


	// вектор истинных значений y (двумерный вектор) (16)
	std::vector<double> true_y;
	true_foo(x, true_y);

	print_y(x, true_y);

	// вектор весовых коэффициентов (5) W0 = w[4]
	std::vector<double> w (5, 0);

	// Выходной вектор функциии (2^4)
	std::vector<double> y;

	// std::cout << "> > > main - Ok!" << std::endl;


	return 0;
}

// Функция составления двоичных комбинаций 2^4
void binary(std::vector<std::vector<double> > & xt)
{
	for (int i = 0; i < 16; i++)
	{
		std::bitset<4> bin(i);

		for (int j = 0; j < 4; j++)
		{
			xt[i].push_back( bin[j] );
		}
	}

	// std::cout << "> > > binary_foo - Ok!" << std::endl;
}

// Функция построения таблицы истинности.
void true_foo(std::vector<std::vector<double> > & xt, std::vector<double> & yt)
{
	for (int i = 0; i < 16; i++)
	{
		if ( (xt[i][3]==0) && ( ( (xt[i][0]==0) && (xt[i][1]==0) ) || (xt[i][2]==0) ) ) {
			yt.push_back(1);
		}
		else
		{
			yt.push_back (0);
		}
	}

	// std::cout << "> > > true_foo - Ok!" << std::endl;
}

void print_y(std::vector<std::vector<double> > const & xt, std::vector<double> const & yt)
{
	std::cout << std::endl << "X4 X3 X2 X1 | Y" << std::endl;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			std::cout << " " << xt[i][j] << " ";
		}
		std::cout << "| " << yt[i] << std::endl;
	}

	std::cout << std::endl;

	// std::cout << "> > > print_y - Ok!" << std::endl;
}