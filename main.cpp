#include <iostream>
#include <ctime>
#include "utils.hpp"
#ifndef nullptr
	#define nullptr NULL
#endif
#if V // ft
	#include "vector.hpp"
	#include "random_access_iterator.hpp"
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

	std::cout << "at 2\n";
	std::cout << my_vector.at(2) << std::endl;
//	std::cout << "at 200\n";
//	std::cout << my_vector.at(200) << std::endl;

//	my_vector.clear();
//	std::cout << "Clear !\n";
//	print_vector(my_vector);

	N = 5;
	for (i = 0; i < N; i++)
	{
		my_vector.push_back(i * 10);
	}
	std::cout << "My Vector:\n";
	print_vector(my_vector);
	
	ft::vector<int> other_vector;
	N = 17;
	for (i = 0; i < N; i++)
	{
		other_vector.push_back(i * (-10));
	}
	std::cout << "Other Vector:\n";
	print_vector(other_vector);
	my_vector.swap(other_vector);
	std::cout << "After swap !!\n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Other Vector:\n"; print_vector(other_vector);

	ft::vector<int> second_vector(my_vector);
	my_vector.push_back(99);
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Sec Vector:\n"; print_vector(second_vector);
	my_vector.push_back(1);
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Sec Vector:\n"; print_vector(second_vector);

	ft::vector<int>::iterator	it_1;
	ft::vector<int>*			p;
	p = &my_vector;
	std::cout << "           my_vector: " << &my_vector << std::endl;
	std::cout << "pointer to my_vector: " << p << std::endl;
//	ft::vector<int>::iterator  it_2(p);

	my_vector = second_vector; // assign para menor
	std::cout << "my_vector = second_vector\n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Sec Vector:\n"; print_vector(second_vector);

	my_vector = other_vector; // assign para maior
	std::cout << "my_vector = other_vector\n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Other Vector:\n"; print_vector(other_vector);

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

