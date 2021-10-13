#include <iostream>
double ExpSeries(double x, int N)
{
	double t = 1; //define the first term in Maclaurin series for exp(x) 
	double sum = 1; //define the result of this power series
	for (int i = 1; i <= N; i++)
	{
		t = (t * x) / i; // define the nth term using recurrence relation
		sum = sum + t; // add the nth term into the sum
	}
	return sum; // this function returns the sum 
}
int main()
{
	std::cout << ExpSeries(1.0, 2) << std::endl;
	// display the value of approximation with x = 1.0, N = 2 
	return 0;
}