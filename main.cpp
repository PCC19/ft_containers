#include <iostream>
#include <ctime>
#include "utils.hpp"
#ifndef nullptr
	#define nullptr NULL
#endif
#if V // ft
	#include "vector.hpp"
#else // stl
	#include <vector>
	namespace ft = std;
#endif

int main()
{
	clock_t ini;
	clock_t fin;
	double elapsed_time;
	int N;
	int i;

	if (V == 1)
		std::cout << "VERSION:  FT" << std::endl;
	else
		std::cout << "VERSION: STL" << std::endl;
	ini = clock();
	// Main program =============================
	std::cout << "Hello World!" << std::endl;

	ft::vector<int> my_vector;
	print_vector(my_vector);
	std::cout << "Is empty ? " << my_vector.empty() << std::endl;
	std::cout << "Max size: " << my_vector.max_size() << std::endl;
	std::cout << "Reserve 3\n";
	my_vector.reserve(3);
	print_vector(my_vector);

	N = 5;
	for (i = 0; i < N; i++)
	{
		my_vector.push_back(i * 10);
		print_vector(my_vector);
	}
	print_vector(my_vector);

	
	std::cout << "resize para menor!\n";
	my_vector.resize(3,300);
	print_vector(my_vector);
	std::cout << "resize para maior!\n";
	my_vector.resize(8,800);
	print_vector(my_vector);


	std::cout << "Is empty ? " << my_vector.empty() << std::endl;
	
	my_vector.pop_back();
	std::cout << "pop_back !\n";
	print_vector(my_vector);

	my_vector.clear();
	std::cout << "Clear !\n";
	print_vector(my_vector);


	// ==========================================
	fin = clock();
	elapsed_time = 1000 * ((double) fin - (double) ini) / (double) (CLOCKS_PER_SEC);
	std::cout << "Elapsed time: " << elapsed_time << "ms" << std::endl;

}
/*

TESTS
Constructors
	Default Constructor
	Fill Constructor
	Range Constructor
	Copy Constructor
	Assign Overload
Iterators
	Assign elements with iterator (from beginn e from end)
	Assign and read elements with iterator (from beginn e from end)
Capacity
	Max size
	Empty
	Resize to more
	Resize to less
	Reserve
Element access
	At
	Out of Range
	Front
	Back
Modifiers
	push_back
	pop_back
	assign fill
	assign range
	insert single
	insert fill
	insert range
	erase single
	erase range
	swap
	clear

util:
ok	print_vector




*/

