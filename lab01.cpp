#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

// Функция составления двоичных комбинаций 2^4
void binary(std::vector<std::vector<double> > & xt);

// Функция построения таблицы истинности.
void true_foo(std::vector<std::vector<double> > & xt, std::vector<double> & yt);

void print_y(std::vector<std::vector<double> > const & xt, std::vector<double> const & yt);

double net_foo(std::vector<double> const & xt, std::vector<double> const & wt);
double err_foo(double tr_y, double y);

int flag = 0;
void cor_foo(double del, std::vector<double> & xt, std::vector<double> & wt);
void fil_foo(double net, double & _y);

void print_test(std::vector<double> const & yt);


int main(int argc, char const *argv[])
{

	
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
	std::vector<double> y (16, 0);



	// double delta = 0;
	int count = 0;
	double _net = 0;
	double _delta = 0;

	do
	{
		count++;
		flag = 0;
		double gErr = 0;

		for (int i = 0; i < 16; i++)
		{
			_net = net_foo(x[i], w);

			fil_foo(_net, y[i]);

			_delta = err_foo(true_y[i], y[i]);

			gErr += abs(_delta);

			cor_foo(_delta, x[i], w);
		}

		std::cout << "\nERA: " << count << "		Error Sum: " << gErr << std::endl;
		std::cout << "		w0	w1	w2	w3	w4" << std::endl;
		std::cout <<"Vector W:	" << w[4] << "	" << w[0] << "	" << w[1] << "	" << w[2] << "	" << w[3] << std::endl;
		print_test(y);

	} while (flag);

	std::cout << std::endl << "Number of era:" << count << std::endl;

	// print_y(x, y);


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

void print_test(std::vector<double> const & yt)
{
	std::cout <<"Vector Y:	";
	for (int i = 0; i < 16; i++)
	{
		std::cout << yt[i] << " ";
	}

	std::cout << "\n" << std::endl;

	// std::cout << "> > > print_y - Ok!" << std::endl;
}

double net_foo(std::vector<double> const & xt, std::vector<double> const & wt)
{
	double net = 0;
	for (int i = 0; i < 4; i++)
	{
		net += ( xt[i] * wt[i] );
	}
	net += ( 1 * wt[4] );

	return net;
}

void fil_foo(double net, double & _y)
{
	if (net > 0) 
	{
		_y = 1;
	}
	else
	{
		_y = 0;
	}
}

// Функция вычисления ошибки delta tr_y - учитель, y - тестовое значение.
double err_foo(double tr_y, double y)
{
	
	double delta = tr_y - y;
	if (delta != 0) {
		flag = 1;
	}

	return delta;
}

double nu = 0.3;
double dFoo = 1;
// Функция коррекции весов
void cor_foo(double del, std::vector<double> & xt, std::vector<double> & wt)
{
	wt[4] += ( nu * del * 1 * dFoo);
	for (int i = 0; i < 4; i++)
	{
		wt[i] += ( nu * del * xt[i] * dFoo );
	}
}

// void era_foo()
// {
// 	dddd
// }