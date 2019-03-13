#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>


// declaration block ~~~~~~~~~~~~~~~~~~~~~~~~
void teach(std::vector<std::vector<double> > & x, std::vector<double> & w, std::vector<double> & y, std::vector<double> & true_y);
double check(std::vector<std::vector<double> > & x, std::vector<double> & w, std::vector<double> & y, std::vector<double> & true_y);
void binary(std::vector<std::vector<double> > & xt);
void true_foo(std::vector<std::vector<double> > & xt, std::vector<double> & yt);
void print_y(std::vector<std::vector<double> > const & xt, std::vector<double> const & yt);
void print_test(std::vector<double> const & yt);
double net_foo(std::vector<double> const & xt, std::vector<double> const & wt);
void fil_foo(double net, double & _y);
double err_foo(double tr_y, double y);
double check_foo(double tr_y, double y);
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

	std::cout << std::endl;
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

double check_err(double tr_y, double y)
{
	double delta = tr_y - y;
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

// teach function
void teach(std::vector<std::vector<double> > & x, std::vector<double> & w, std::vector<double> & y, std::vector<double> & true_y)
{
	int count = 0;
	double out = 0;
	double _delta = 0;
	double _detX = 0;
	double gErr = 0;
	double prob = 0;
	double loop = 1;
	do
	{
		loop++;
		count = 0;

		std::vector<double> test(5, 0);
		w = test;

		do
		{
			count++;
			flag = 0;
			gErr = 0;

			for (int i = 0; i < loop; i++)
			{
				out = net_foo(x[i], w);

				fil_foo(out, y[i]);

				_delta = err_foo(true_y[i], y[i]);

				gErr += abs(_delta);

				cor_foo(_delta, x[i], w);
			}

			std::cout << "\nERA: " << count << "		Error Sum: " << gErr << std::endl;
			std::cout << "		w0	w1	w2	w3	w4" << std::endl;
			std::cout <<"Vector W:	" << w[4] << "	" << w[0] << "	" << w[1] << "	" << w[2] << "	" << w[3] << std::endl;

		} while (flag);

		prob = check(x, w, y, true_y);

	} while (prob != 0);

	std::cout << "\nRESUME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	std::cout << "Enough " << loop << " variable(s) & " << count << " ERAs for theach =)" << std::endl;
}

double check(std::vector<std::vector<double> > & x, std::vector<double> & w, std::vector<double> & y, std::vector<double> & true_y)
{
	int count = 0;
	double out = 0;
	double _delta = 0;
	double gErr = 0;
	double prob = 0;
	
	for (int i = 0; i < 16; i++)
	{
		out = net_foo(x[i], w);

		fil_foo(out, y[i]);

		_delta = check_err(true_y[i], y[i]);

		gErr += abs(_delta);
	}

	std::cout << "\nTESTING NN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	print_test(y);
	std::cout << "Error Sum: " << gErr << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	return gErr;
}
