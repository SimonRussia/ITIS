#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

// declaration block ~~~~~~~~~~~~~~~~~~~~~~~~
void binary(std::vector<std::vector<double> > & xt);
void true_foo(std::vector<std::vector<double> > & xt, std::vector<double> & yt);
void print_y(std::vector<std::vector<double> > const & xt, std::vector<double> const & yt);
void print_test(std::vector<double> const & yt);
double net_foo(std::vector<double> const & xt, std::vector<double> const & wt);
double log_foo(double net);
void fil_foo(double net, double & _y);
double err_foo(double tr_y, double y);
void cor_foo(double del, std::vector<double> & xt, std::vector<double> & wt);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



int flag = 0;

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
}

void print_test(std::vector<double> const & yt)
{
	std::cout <<"Vector Y:	";
	for (int i = 0; i < 16; i++)
	{
		std::cout << yt[i] << " ";
	}

	std::cout << "\n" << std::endl;
}

double tumb = 1;

double net_foo(std::vector<double> const & xt, std::vector<double> const & wt)
{
	double net = 0;
	for (int i = 0; i < 4; i++)
	{
		net += ( xt[i] * wt[i] );
	}
	net += ( 1 * wt[4] );

	if( tumb == 1 )
	{
		return log_foo(net);
	}
	else
	{
		return net;
	}
}

double out;
double dFoo = 1;

double log_foo(double net)
{
	out = 0;

	out = ( 1 / ( 1 + exp(-net) ) );

	dFoo = ( out * (1 - out) );

	return out;
}


void fil_foo(double net, double & _y)
{
	if (net >= 0.5) 
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

// Функция коррекции весов
void cor_foo(double del, std::vector<double> & xt, std::vector<double> & wt)
{
	wt[4] += ( nu * del * 1 * dFoo);
	for (int i = 0; i < 4; i++)
	{
		wt[i] += ( nu * del * xt[i] * dFoo );
	}
}
