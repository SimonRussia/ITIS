#include "lab01_p4.hpp"

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

	teach(x, w, y, true_y);

	return 0;
}
