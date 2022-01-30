#include <iostream>
#include <ctime>

int main()
{
	clock_t ini;
	clock_t fin;
	double elapsed_time;

	ini = clock();
	std::cout << "Hello World!" << std::endl;
	fin = clock();
	elapsed_time = 1000 * ((double) fin - (double) ini) / (double) (CLOCKS_PER_SEC);
	std::cout << "Elapsed time: " << elapsed_time << "ms" << std::endl;

}

