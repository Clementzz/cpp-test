#include <iostream>
#include <fstream>
#include <cmath>
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
	std::ofstream outFile;
	outFile.open("expmac.txt"); // create or open a text file
	if (!outFile) // check if this text file could be created and open
	{
		std::cout << "Could not open file for writing" << std::endl;
		return 1; // if it cannot be opened, return error code 1
	}
	for (int i = -100; i <= 100; i++) // Loop 200 times
	{
		double x = i * 0.01; // define the increment
		outFile.width(15); outFile << x; // output x
		outFile.width(15); outFile << exp(x); 
		// output exp(x) evaluated by the standard library function
		outFile.width(15); outFile << ExpSeries(x, 1);
		//output the two-term Maclaurin series approximation to exp(x)
		outFile.width(15); outFile << ExpSeries(x, 2); 
		//output the three-term Maclaurin series approximation to exp(x)
		outFile.width(15); outFile << ExpSeries(x, 3)<<std::endl;
		//output the four-term Maclaurin series approximation to exp(x)
	}
	outFile.close(); //close the file
	return 0;
}