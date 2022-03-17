/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:32:59 by pcunha            #+#    #+#             */
/*   Updated: 2022/03/17 04:45:54 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <typeinfo>
#include <map>
#include "utils.hpp"
#include "node.hpp"
#ifndef nullptr
	#define nullptr NULL
#endif
#if V // ft
	#include "vector.hpp"
	#include "random_access_iterator.hpp"
	#include "reverse_iterator.hpp"
	#include "pairs.hpp"
	#include "map.hpp"
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

	std::cout << "ft::vector<int> second_vector(my_vector);\n";
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

	ft::vector<int>::iterator itb;
	ft::vector<int>::iterator ite;

	std::cout << "ITERATORS: \n";
	itb = my_vector.begin();
	ite = my_vector.end();

	--ite;
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "begin       element: " << *itb << std::endl;
	std::cout << "  end       element: " << *(ite) << std::endl;
	std::cout << "begin pos 1 element: " << *(itb++) << " : " << *itb << std::endl;
	std::cout << "  end       element: " << *(ite) << std::endl;
	std::cout << "begin pre 1 element: " << *(++itb) << std::endl;
	std::cout << "  end       element: " << *(ite) << std::endl;

	std::cout << "Arithmetics: \n";
	ft::vector<int>::iterator it;
	itb = my_vector.begin();
	it = itb;
	std::cout << "it = itb + n: \n";
	std::cout << "begin       element: " << *itb << std::endl;
	it = itb + 1; std::cout << "begin + 1: " << *(it) << std::endl;
	it = itb + 2; std::cout << "begin + 2: " << *(it) << std::endl;
	it = itb + 3; std::cout << "begin + 3: " << *(it) << std::endl;
	std::cout << "it += n";
	std::cout << "begin       element: " << *itb << std::endl;
	it = itb; it+=1; std::cout << "begin += 1: " << *(it) << std::endl;
	std::cout << "it - begin: " << (it - itb) << std::endl;
	it = itb; it+=2; std::cout << "begin += 2: " << *(it) << std::endl;
	std::cout << "it - begin: " << (it - itb) << std::endl;
	it = itb; it+=3; std::cout << "begin += 3: " << *(it) << std::endl;
	std::cout << "it - begin: " << (it - itb) << std::endl;
	std::cout << "begin       element: " << *itb << std::endl;
	std::cout << "begin[1]: " << (itb[1]) << std::endl;
	std::cout << "begin[2]: " << (itb[2]) << std::endl;
	std::cout << "begin[3]: " << (itb[3]) << std::endl;
	std::cout << "Relational: \n";
	std::cout << "itb = begin   ite = end: \n";
	std::cout << "begin == end ? " << (itb == ite) << std::endl;
	std::cout << "begin != end ? " << (itb != ite) << std::endl;
	std::cout << "begin <  end ? " << (itb <  ite) << std::endl;
	std::cout << "begin >  end ? " << (itb >  ite) << std::endl;
	std::cout << "begin <= end ? " << (itb <= ite) << std::endl;
	std::cout << "begin >= end ? " << (itb >= ite) << std::endl;
	std::cout << "itb = begin   ite = begin: \n";
	ite = itb;
	std::cout << "begin == end ? " << (itb == ite) << std::endl;
	std::cout << "begin != end ? " << (itb != ite) << std::endl;
	std::cout << "begin <  end ? " << (itb <  ite) << std::endl;
	std::cout << "begin >  end ? " << (itb >  ite) << std::endl;
	std::cout << "begin <= end ? " << (itb <= ite) << std::endl;
	std::cout << "begin >= end ? " << (itb >= ite) << std::endl;

	std::cout << "Reverse Iterators: \n";
	ft::vector<int>::reverse_iterator rit, ritb, rite;
	ritb = my_vector.rbegin();
	rite = my_vector.rend();
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Reversed: \n";
	for (rit = ritb; rit != rite; rit++)
		std::cout << *rit << "|";
	std::cout << std::endl;

	std::cout << "Front and Back: \n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Front: " << my_vector.front() << " back: " << my_vector.back() << std::endl;
	std::cout << "Sec  Vector:\n"; print_vector(second_vector);
	std::cout << "Front: " << second_vector.front() << "\t\tback: " << second_vector.back() << std::endl;

	std::cout << "Assign menor que capacity: \n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	my_vector.assign(3, 13);
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "Assign maior que capacity: \n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	my_vector.assign(35, 13);
	std::cout << "My Vector:\n"; print_vector(my_vector);

	std::cout << "Fill Constructor: \n";
	ft::vector<int> fill_vector(5, 100);
	std::cout << "Fill  Vector (5 100):\n"; print_vector(fill_vector);


	// assign range
	std::cout << "ASSIGN RANGE: \n";
	my_vector.clear();
	N = 10;
	int j;
	for (j = 1; j < N; j++) my_vector.push_back(j * 10);
	std::cout << "My Vector:\n"; print_vector(my_vector);
	ft::vector<int> from_my_vector;
	from_my_vector.assign((my_vector.begin() + 2), (my_vector.end() - 2));
	std::cout << "From My Vector (+2 -2): \n"; print_vector(from_my_vector);

	// Constructor  range
	std::cout << "CONSTRUCTTOR RANGE: \n";
	my_vector.clear();
	N = 10;
	for (j = 1; j < N; j++) my_vector.push_back(j * 13);
	std::cout << "My Vector:\n"; print_vector(my_vector);
	ft::vector<int> range_con_vector((my_vector.begin() + 2), (my_vector.end() - 2));
	std::cout << "Range_Con_Vector (+2 -2): \n"; print_vector(range_con_vector);


	std::cout << "Erase position: \n";
	my_vector.clear();
	N = 10;
	for (j = 1; j < N; j++) my_vector.push_back(j * 10);
	std::cout << "My Vector:\n"; print_vector(my_vector);
	ft::vector<int>::iterator it_erase, aux;
	it_erase = my_vector.begin();
	it_erase += 3;
	aux = my_vector.erase(it_erase);
	std::cout << "My Vector erased:\n"; print_vector(my_vector);
	std::cout << "Position :" << *aux << std::endl;

	std::cout << "Erase range: \n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	ft::vector<int>::iterator it_erase_end;
	it_erase = my_vector.begin();
	it_erase += 3;
	it_erase_end = it_erase;
	it_erase_end += 4;
	std::cout << "first: " << *it_erase << " last: " << *it_erase_end << std::endl;
	aux = my_vector.erase(it_erase, it_erase_end);
	std::cout << "My Vector erased range :\n"; print_vector(my_vector);
	std::cout << "Position :" << *aux << std::endl;

	std::cout << "Insert position: \n";
	ft::vector<int>::iterator it_insert_position;
	it_insert_position = my_vector.begin();
	it_insert_position += 3;
	std::cout << "My Vector:\n"; print_vector(my_vector);
	my_vector.insert(it_insert_position, 111);
	std::cout << "My Vector insert 3:\n"; print_vector(my_vector);
	std::cout << "Insert fill : \n";
	my_vector.insert(it_insert_position, 3, 333);
	std::cout << "My Vector insert 3, 3, 333:\n"; print_vector(my_vector);
	std::cout << "Insert range : \n";
	ft::vector<int> to_insert_range;
	to_insert_range.push_back(1000);
	to_insert_range.push_back(2000);
	to_insert_range.push_back(3000);
	std::cout << "to_insert_range"; print_vector(to_insert_range);
	std::cout << "My Vector :\n"; print_vector(my_vector);
	my_vector.insert((my_vector.begin() + 3), to_insert_range.begin(), to_insert_range.end());
	std::cout << "Insert do vetor acima na pos 3 :\n"; print_vector(my_vector);

	std::cout << "Teste do equal :\n";
	ft::vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2 = v1;
	std::cout << "v1:\n"; print_vector(v1);
	std::cout << "v2:\n"; print_vector(v2);
	std::cout << "v1 == v2 ? : " << (v1 == v2) << std::endl;
	v1.push_back(4);
	std::cout << "v1:\n"; print_vector(v1);
	std::cout << "v2:\n"; print_vector(v2);
	std::cout << "v1 == v2 ? : " << (v1 == v2) << std::endl;
	std::cout << "v1 != v2 ? : " << (v1 != v2) << std::endl;

	std::cout << "Non Members overloads: \n";
	v1.pop_back();
	std::cout << "v1:\n"; print_vector(v1);
	std::cout << "v2:\n"; print_vector(v2);
	std::cout << "v1 <  v2 ? : " << (v1 < v2) << std::endl;
	std::cout << "v1 <= v2 ? : " << (v1 <= v2) << std::endl;
	std::cout << "v1 >  v2 ? : " << (v1 > v2) << std::endl;
	std::cout << "v1 >= v2 ? : " << (v1 >= v2) << std::endl;
	v1.push_back(5);
	std::cout << "v1:\n"; print_vector(v1);
	std::cout << "v2:\n"; print_vector(v2);
	std::cout << "v1 <  v2 ? : " << (v1 < v2) << std::endl;
	std::cout << "v1 <= v2 ? : " << (v1 <= v2) << std::endl;
	std::cout << "v1 >  v2 ? : " << (v1 > v2) << std::endl;
	std::cout << "v1 >= v2 ? : " << (v1 >= v2) << std::endl;

	//Pair:
	ft::pair<int, char>	par1(12, 'a');
	ft::pair<int, std::string> par2(0, "Paulo");
	std::cout << "pairs: \n";
	print_pair(par1);
	print_pair(par2);
	ft::pair<int, int> par3, par4;
	par3 = ft::make_pair(10,100);
	par4 = ft::make_pair(10,100);
	std::cout << "10 100 | 10 100\n";
	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
	par3 = ft::make_pair(10,100);
	par4 = ft::make_pair(10,200);
	std::cout << "10 100 | 10 200\n";
	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
	par3 = ft::make_pair(1,100);
	par4 = ft::make_pair(10,100);
	std::cout << "1 100 | 10 100\n";
	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
	par3 = ft::make_pair(20,100);
	par4 = ft::make_pair(10,100);
	std::cout << "20 100 | 10 100\n";
	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;


	// Make_pair
	ft::pair<char, std::string> par;
	std::cout << "make_pair: \n";
	par = ft::make_pair('o', "paulo");
	print_pair(par);


	// debug node
		ft::pair<int, std::string> par_0(0, "Paulo");
		ft::pair<int, std::string> par_1(1, "Roberto");
		ft::pair<int, std::string> par_2(2, "Cunha");
			print_pair(par_0);
			print_pair(par_1);
			print_pair(par_2);

		typedef rbt_node<ft::pair<int, std::string> >  node;
		node no_0(&par_0);
		node no_1(&par_1);
		node no_2(&par_2);

		std::cout << "node: \n";
		print_node(no_0);
		print_node(no_1);
		print_node(no_2);
	
	// simple map
	std::map<int, int> mapa;
	mapa[70] = 70;
	mapa[50] = 50;
	mapa[20] = 20;
	mapa[10] = 10;
	mapa[80] = 80;
	mapa[40] = 40;
	mapa[60] = 60;
	mapa[30] = 30;
	std::map<int, int>::iterator itm;

	itm = mapa.begin();
	while (itm != mapa.end())
	{
		std::cout << itm->first << std::endl;
		itm++;
	}

	// Teste primeiro insert
	std::cout << "Teste primeiro insert\n";
	ft::map<int, int>	mapa0;
	ft::pair<int, int>	par_a;

	par_a = ft::make_pair(10,100);
	print_pair(par_a);

	std::cout << "Teste begin e end\n";
	mapa0.insert(par_a);
	par_a = ft::make_pair(20,100);
	mapa0.insert(par_a);
	mapa0.insert(ft::make_pair(5,100));
	ft::map<int, int>::iterator it_mapa0;
	it_mapa0 = mapa0.begin();
	std::cout << "begin(): \n";
	std::cout << it_mapa0->first << std::endl;
	it_mapa0 = mapa0.end();
	std::cout << "end(): \n";
	std::cout << it_mapa0->first << std::endl;

	std::cout << "Testa is_left/right_child \n";



	// ==========================================
	fin = clock();
	elapsed_time = 1000 * ((double) fin - (double) ini) / (double) (CLOCKS_PER_SEC);
	std::cout << "Elapsed time: " << elapsed_time << "ms" << std::endl;

};
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

