#include "lab01_p3.hpp"

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

	int count = 0;
	double out = 0;
	double _delta = 0;

	do
	{
		count++;
		flag = 0;
		double gErr = 0;

		for (int i = 0; i < 16; i++)
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
		print_test(y);

	} while (flag);

	std::cout << std::endl << "Number of era:" << count << std::endl;

	return 0;
}
