/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:32:59 by pcunha            #+#    #+#             */
/*   Updated: 2022/04/12 23:24:47 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CYAN			"\e[0;36m"
#define C_RED			"\e[0;31m"
#define RESET			"\e[0m"
#define BOLD			"\e[1m"
#ifndef nullptr
	#define nullptr NULL
#endif

#include <iostream>
#include <ctime>
#include <typeinfo>
#include <map>

#include "node.hpp"
#if V // ft
	#include "vector.hpp"
	#include "random_access_iterator.hpp"
	#include "reverse_iterator.hpp"
	#include "pairs.hpp"
	#include "map.hpp"
#else // stl
	#include <vector>
	#include <map>
	namespace ft = std;
#endif
#include "utils.hpp"

void line() { std::cout << "-----------------------------------------\n"; };

int main()
{
	clock_t ini;
	clock_t fin;
	double elapsed_time;
	int N;
	(void) N;
	

	// HEADER
	if (V == 1)
		std::cout << "VERSION:  FT" << std::endl;
	else
		std::cout << "VERSION: STL" << std::endl;
	ini = clock();
	
	std::cout << " =========================================\n";
	std::cout << "				VECTOR TESTS				\n";
	std::cout << " =========================================\n";

	line(); std::cout << "1.0 Default constructor:\n";line();
		ft::vector<int> vector_1;
		std::cout << "Vector constructed with default constructor\n";
		print_vector(vector_1);

	line(); std::cout << "2.0 Fill constructor:\n";line();
		ft::vector<int> vector_2(5,10);
		std::cout << "Vector_2(5,10) (fill constructror)\n";
		print_vector(vector_2);

	line(); std::cout << "3.0 Range  constructor:\n";line();
		ft::vector<int> vector_3;
		for (int i = 2; i <= 32; i*=2)
			vector_3.push_back(i);
		print_vector(vector_3);
	
	line(); std::cout << "4.0 Iterators\n";line();
		ft::vector<int>::iterator it1;
		std::cout << "iterating on vector_2: \n";
		print_vector(vector_2);
		for (it1 = vector_2.begin(); it1 != vector_2.end(); it1++)
			std::cout << *it1 << " , ";
		std::cout << std::endl;

	line(); std::cout << "5.0 Reverse Iterators\n"; line();
		ft::vector<int>::reverse_iterator it2;
		std::cout << "iterating on vector_3: \n";
		print_vector(vector_3);
		for (it2 = vector_3.rbegin(); it2 != vector_3.rend(); it2++)
			std::cout << *it2 << " , ";
		std::cout << std::endl;

	line(); std::cout << "6.0 Size, max_size & Capacity\n";line();
		print_vector(vector_3);
		std::cout << "Vector_3 size: " << vector_3.size() << std::endl;
		std::cout << "Vector_3 max_size: " << vector_3.max_size() << std::endl;
		std::cout << "Vector_3 capacity: " << vector_3.capacity() << std::endl;

	line(); std::cout << "7.0 Resize\n"; line();
		std::cout << "Vector_3: resize(10,3)\n";
		vector_3.resize(10,3);
		print_vector(vector_3);
		print_vector(vector_3);
		std::cout << "Vector_3: resize(4,11)\n";
		vector_3.resize(4,11);
		print_vector(vector_3);

	line(); std::cout << "8.0 Reserve\n";line();
		std::cout << "vector_2:\n";
		print_vector(vector_2);
		std::cout << "Reserve 20:\n";
		vector_2.reserve(20);
		print_vector(vector_2);

	line(); std::cout << "9.0 Empty\n:"; line();
		std::cout << "is vector_2 empty ?\n";
		std::cout << vector_2.empty() << std::endl;
		std::cout << "is vector_1 empty ?\n";
		std::cout << vector_1.empty() << std::endl;

	line(); std::cout << "10.0 Operator []\n";line();
		print_vector(vector_3);
		std::cout << "vector_3[2]: " << vector_3[2] << std::endl;
		std::cout << "vector_3[3]: " << vector_3[3] << std::endl;
		std::cout << "vector_3[1]: " << vector_3[1] << std::endl;

	line(); std::cout << "11.0 at\n";line();
		print_vector(vector_3);
		std::cout << "vector_3.at(2): " << vector_3.at(2) << std::endl;
		std::cout << "vector_3.at(3): " << vector_3.at(3) << std::endl;
		std::cout << "vector_3.at(1): " << vector_3.at(1) << std::endl;

	line(); std::cout << "12.0 front & back\n";line();
		print_vector(vector_3);
		std::cout << "Vector_3 front: " << vector_3.front() << std::endl;
		std::cout << "Vector_3 back : " << vector_3.back() << std::endl;

	line(); std::cout << "13.0 Assign\n";line();
		vector_3.push_back(10);
		vector_3.push_back(20);
		vector_3.push_back(30);
		vector_3.push_back(40);
		vector_3.push_back(50);
		ft::vector<int>::iterator it3, it4;
		it3 = vector_3.begin();
		it3++;
		it3++;
		it4 = vector_3.end();
		it4--;
		it4--;
		ft::vector<int> vector_4;
		vector_4.assign(it3, it4);
		print_vector(vector_3);
		std::cout << "assign from it3: " << *it3 << " to it4: " << *it4 << std::endl;
		print_vector(vector_4);

	line(); std::cout << "14.0 push_back\n"; line();
		std::cout << "push_back(1):\n"; vector_4.push_back(1); print_vector(vector_4);;
		std::cout << "push_back(2):\n"; vector_4.push_back(2); print_vector(vector_4);;
		std::cout << "push_back(3):\n"; vector_4.push_back(3); print_vector(vector_4);;

	line(); std::cout << "15.0 pop_back\n";line();
		std::cout << "pop_back !\n"; vector_4.pop_back(); print_vector(vector_4);
		std::cout << "pop_back !\n"; vector_4.pop_back(); print_vector(vector_4);
		std::cout << "pop_back !\n"; vector_4.pop_back(); print_vector(vector_4);

	line(); std::cout << "16.0 insert_single\n"; line();
		std::cout << "Insert 2,15\n";
		it3 = vector_4.begin();
		it3++; it3++;
		vector_4.insert(it3,15);
		print_vector(vector_4);

	line(); std::cout << "17.0 insert fill\n";line();
		std::cout << "Insert 2, 3, 33:\n";
		vector_4.insert(it3, 3, 33);
		print_vector(vector_4);

	line(); std::cout << "18.0 insert range\n";line();
		ft::vector<int>::iterator it5 = vector_4.begin();
		ft::vector<int>::iterator it6 = vector_3.begin();
		ft::vector<int>::iterator it7 = vector_3.end();
		it7--;
		print_vector(vector_3);
		print_vector(vector_4);
		std::cout << "starting from it5: " << *it5;
		std::cout << " insert from it6: " << *it6 << " to it7: " << *it7 << std::endl;
		vector_4.insert(it5 + 2, it6, it7);

	line(); std::cout << "19.0 erase position\n";line();
	line(); std::cout << "20.0 erase first/last\n";line();
	line(); std::cout << "21.0 swap\n";line();
	line(); std::cout << "22.0 clear\n";line();
	line(); std::cout << "23.0 Non-Member Functions\n"; line();
	
	
	
	std::cout << " =========================================\n";
	std::cout << "					MAP TESTS				\n";
	std::cout << " =========================================\n";
	
	line(); std::cout << "1.0 Empty constructor:\n"; line();
	line(); std::cout << "2.0 Range constructor:\n"; line();
	line(); std::cout << "3.0 Copy  constructor:\n"; line();
	
	line(); std::cout << "4.0 Iterators\n"; line();
	line(); std::cout << "5.0 Reverse Iterators\n"; line();

	line(); std::cout << "6.0 Size, max_size & Empty\n"; line();

	line(); std::cout << "7.0 Operator []\n"; line();
	line(); std::cout << "8.0 at\n"; line();

	line(); std::cout << "9.0 insert_single\n"; line();
	line(); std::cout << "10.0 insert hint\n"; line();
	line(); std::cout << "11.0 insert range\n"; line();
	line(); std::cout << "12.0 erase key\n"; line();
	line(); std::cout << "13.0 erase position\n"; line();
	line(); std::cout << "14.0 erase range\n"; line();
	line(); std::cout << "15.0 swap\n"; line();
	line(); std::cout << "16.0 clear\n"; line();
	
	line(); std::cout << "17.0 find\n"; line();
	line(); std::cout << "18.0 count\n"; line();
	line(); std::cout << "19.0 lower bound\n"; line();
	line(); std::cout << "20.0 upper bound\n"; line();
	line(); std::cout << "21.0 equal range\n"; line();
	line(); std::cout << "22.0 Non-Member Functions\n"; line();
	
return 0;	
	
/*
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

	std::cout << "Teste swap: \n";
	N = 5;
	for (i = 0; i < N; i++)
	{
		my_vector.push_back(i * 10);
	}
	ft::vector<int>::iterator first_va, first_vb;
	first_va = my_vector.begin();
	first_va++;
	std::cout << "My Vector:\n";
	print_vector(my_vector);
	std::cout << "first_va: " << *first_va << std::endl;
	ft::vector<int>::const_iterator const_va;
	const_va = my_vector.begin();
	const_va++;
	std::cout << "const_va: " << *const_va << std::endl;
	std::cout << "iguais ?: " << (first_va == const_va) << std::endl;

	
	ft::vector<int> other_vector;
	N = 17;
	for (i = 0; i < N; i++)
	{
		other_vector.push_back(i * (-10));
	}
	first_vb = other_vector.begin();
	std::cout << "Other Vector:\n";
	print_vector(other_vector);
	std::cout << "first_vb: " << *first_vb << std::endl;
	my_vector.swap(other_vector);
	std::cout << "After swap !!\n";
	std::cout << "My Vector:\n"; print_vector(my_vector);
	std::cout << "first_va: " << *first_va << std::endl;
	std::cout << "first_va++: " << *(++first_va) << std::endl;
	std::cout << "Other Vector:\n"; print_vector(other_vector);
	std::cout << "first_vb: " << *first_vb << std::endl;
	std::cout << "first_vb++: " << *(++first_vb) << std::endl;




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

	// =======================================
	// TESTES DO MAP
	// =======================================

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
	std::cout << (--it_mapa0)->first << std::endl;

	// Cria map para testes
	std::cout << "Mapa para testes: \n";
	ft::map<int, int> mapa1;
	// 80 40 20 10 30 60 50 70 120 100 140 90 89 110 111 134 150 130 135 125
	mapa1.insert(ft::make_pair(80,800));
	mapa1.insert(ft::make_pair(40,400));
	mapa1.insert(ft::make_pair(20,200));
	mapa1.insert(ft::make_pair(10,1000));
	mapa1.insert(ft::make_pair(30,300));
	mapa1.insert(ft::make_pair(60,600));
	mapa1.insert(ft::make_pair(50,500));
	mapa1.insert(ft::make_pair(70,700));
	mapa1.insert(ft::make_pair(120,1200));
	mapa1.insert(ft::make_pair(100,1000));
	mapa1.insert(ft::make_pair(140,1400));
	mapa1.insert(ft::make_pair(90,900));
	mapa1.insert(ft::make_pair(89,890));
	mapa1.insert(ft::make_pair(110,1100));
	mapa1.insert(ft::make_pair(111,1110));
	mapa1.insert(ft::make_pair(134,1340));
	mapa1.insert(ft::make_pair(150,1500));
	mapa1.insert(ft::make_pair(130,1300));
	mapa1.insert(ft::make_pair(135,1350));
	mapa1.insert(ft::make_pair(125,1250));
	ft::map<int, int>::iterator itm1;

	// Teste find
	std::cout << "Teste find: \n";
	int x;
	x = 90;
	itm1 = mapa1.find(x);
	if (itm1 != mapa1.end())
	std::cout << "find(" << x << "): " << itm1->second << std::endl;
	x = 110;
	itm1 = mapa1.find(x);
	if (itm1 != mapa1.end())
	std::cout << "find(" << x << "): " << itm1->second << std::endl;
	x = 13;
	itm1 = mapa1.find(x);
	if (itm1 != mapa1.end())
		std::cout << "find(" << x << "): " << itm1->second << std::endl;

	// Teste operator ++
	std::cout << "Teste operator ++it:\n";
	std::cout << "Tem filho direito:\n";
	itm1 = mapa1.find(40);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "++itm1: " << (++itm1)->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(30);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "++itm1: " << (++itm1)->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(111);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "++itm1: " << (++itm1)->first << std::endl;

	std::cout << "Teste operator it++:\n";
	std::cout << "Tem filho direito:\n";
	itm1 = mapa1.find(40);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "itm1++: " << (itm1++)->first << std::endl;
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(30);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "itm1++: " << (itm1++)->first << std::endl;
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(111);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "itm1++: " << (itm1++)->first << std::endl;
	std::cout << "itm1:   " << itm1->first << std::endl;

	std::cout << "Teste operator --it:\n";
	std::cout << "Tem filho direito:\n";
	itm1 = mapa1.find(50);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "--itm1: " << (--itm1)->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(40);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "--itm1: " << (--itm1)->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(120);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "--itm1: " << (--itm1)->first << std::endl;

	std::cout << "Teste operator it--:\n";
	std::cout << "Tem filho direito:\n";
	itm1 = mapa1.find(40);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "itm1--: " << (itm1--)->first << std::endl;
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(30);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "itm1--: " << (itm1--)->first << std::endl;
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "Nao Tem filho direito:\n";
	itm1 = mapa1.find(111);
	std::cout << "itm1:   " << itm1->first << std::endl;
	std::cout << "itm1--: " << (itm1--)->first << std::endl;
	std::cout << "itm1:   " << itm1->first << std::endl;

	std::cout << "Teste count:\n";
	std::cout << "30: " << mapa1.count(30) << std::endl;
	std::cout << "31: " << mapa1.count(31) << std::endl;


	std::cout << "Teste iterators, ++ e --\n";
	ft::map<int, int>::iterator aux_end;
	aux_end = mapa1.end();
	aux_end--;
	for (itm1 = mapa1.begin(); itm1 != mapa1.end(); itm1++)
	{
		std::cout << "itm: " << itm1->first;
		if (itm1 != mapa1.begin())
		{
			std::cout << " a: " << (--itm1)->first; ++itm1;
		};
		if (itm1 != aux_end)
		{
			std::cout << " p: " << (++itm1)->first; --itm1;
		};
		std::cout << std::endl;
	};

	std::cout << "Teste reverse iterator: \n";

	ft::map<int, int>::reverse_iterator itm1_r;
	itm1_r = mapa1.rbegin();
	std::cout << itm1_r->first << std::endl;
	itm1_r = mapa1.rend();
	itm1_r--;
	std::cout << itm1_r->first << std::endl;
	for (itm1_r = mapa1.rbegin(); itm1_r != mapa1.rend(); itm1_r++)
		std::cout << itm1_r->first << " | ";
	std::cout << std::endl;

	std::cout << "Teste delete_node: \n";
	std::cout << "Deleting 80 (two children)\n";
		print_map(mapa1); mapa1.erase(80); print_map(mapa1);
	std::cout << "Deleting 89 (two children)\n";
		print_map(mapa1); mapa1.erase(89); print_map(mapa1);
	std::cout << "Deleting 70 (no child)\n";
		print_map(mapa1); mapa1.erase(70); print_map(mapa1);
	std::cout << "Deleting 90 (one child)\n";
		print_map(mapa1); mapa1.erase(90); print_map(mapa1);
	std::cout << "Deleting 110 (one child)\n";
		print_map(mapa1); mapa1.erase(110); print_map(mapa1);
	std::cout << "Deleting 40 (two children)\n";
		print_map(mapa1); mapa1.erase(40); print_map(mapa1);



	std::cout << "Teste do Erase (position) 120\n";
	ft::map<int, int>::iterator i_pos;

	i_pos = mapa1.find(120);
	mapa1.erase(i_pos);
	std::cout << "Teste do Erase (key) 100 \n";
	mapa1.erase(100);

	std::cout << "Teste do Erase (first, last)\n";
	ft::map<int, int>::iterator i_f, i_l;
		print_map(mapa1);
	i_f = mapa1.find(10);
	i_l = mapa1.find(30);
	mapa1.erase(i_f, i_l);
		print_map(mapa1);

	std::cout << "Teste do clear \n";
	print_map(mapa1);
	mapa1.clear();
	print_map(mapa1);


	std::cout << "//////////////////////////////////////////////\n";
	std::cout << "/// Inicializando mapa2 ///";
	ft::map<int, int> mapa2;
	// 80 40 20 10 30 60 50 70 120 100 140 90 89 110 111 134 150 130 135 125
	mapa2.insert(ft::make_pair(80,800));
	mapa2.insert(ft::make_pair(40,400));
	mapa2.insert(ft::make_pair(20,200));
	mapa2.insert(ft::make_pair(10,1000));
	mapa2.insert(ft::make_pair(30,300));
	mapa2.insert(ft::make_pair(60,600));
	mapa2.insert(ft::make_pair(50,500));
	mapa2.insert(ft::make_pair(70,700));
	mapa2.insert(ft::make_pair(120,1200));
	mapa2.insert(ft::make_pair(100,1000));
	mapa2.insert(ft::make_pair(140,1400));
	mapa2.insert(ft::make_pair(90,900));
	mapa2.insert(ft::make_pair(89,890));
	mapa2.insert(ft::make_pair(110,1100));
	mapa2.insert(ft::make_pair(111,1110));
	mapa2.insert(ft::make_pair(134,1340));
	mapa2.insert(ft::make_pair(150,1500));
	mapa2.insert(ft::make_pair(130,1300));
	mapa2.insert(ft::make_pair(135,1350));
	mapa2.insert(ft::make_pair(125,1250));


	std::cout << "Teste lower_bound & upper_bound\n";
	int numero;

	ft::map<int, int>::iterator itm_bound;
	numero = 5;
	itm_bound = mapa2.lower_bound(numero);
	std::cout << "lb: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;
	numero = 45;
	itm_bound = mapa2.lower_bound(numero);
	std::cout << "lb: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;
	numero = 50;
	itm_bound = mapa2.lower_bound(numero);
	std::cout << "lb: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;
	numero = 200;
	itm_bound = mapa2.lower_bound(numero);
	std::cout << "lb: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;
	numero = 5;
	itm_bound = mapa2.upper_bound(numero);
	std::cout << "ub: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;
	numero = 45;
	itm_bound = mapa2.upper_bound(numero);
	std::cout << "ub: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;
	numero = 50;
	itm_bound = mapa2.upper_bound(numero);
	std::cout << "ub: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;
	numero = 200;
	itm_bound = mapa2.upper_bound(numero);
	std::cout << "ub: " << numero <<  "---> ";
	if (itm_bound == mapa2.end()) std::cout << "end !\n";
	else
		 std::cout << itm_bound->first << std::endl;


//		mapa2.print_tree_level();
//	std::cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n";
//	std::cout << "DEBUG FIX REMOVE\n";
//	std::cout << "Inicial: \n"; mapa2.print_tree_level();
//	int dd;
//	(void) dd;
//	// 80 40 20 10 30 60 50 70 120 100 140 90 89 110 111 134 150 130 135 125
//	dd = 80; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 40; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 20; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 10; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 30; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 60; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 50; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 70; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 120; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 100; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 140; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 90; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 89; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 110; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 111; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 134; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 150; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 130; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 135; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
//	dd = 125; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();


	
	std::cout << " Teste do insert fill\n";
	ft::map<int, int> mapa3;
	ft::map<int, int>::iterator it3_i, it3_l;

	it3_i = mapa2.find(50);
	it3_l = mapa2.find(100);
	mapa3.insert(it3_i, it3_l);
	print_map(mapa3);

	std::cout << "Teste do insert hint\n";
	std::cout << "Inserindo com hint antes da posicao (75 com hint 60)\n";
	it3_i = mapa3.find(60);
	mapa3.insert(it3_i, ft::make_pair(75,750));
	print_map(mapa3);
	std::cout << "Inserindo com hint depois da posicao (85 com hint 90)\n";
	it3_i = mapa3.find(90);
	mapa3.insert(it3_i, ft::make_pair(85,850));
	print_map(mapa3);

	std::cout << "Teste operador []\n";
	std::cout << "Key ja existe (60):\n";
	std::cout << mapa3[60] << std::endl;
	std::cout << "Key nao existe (61):\n";
	mapa[61] = 610;
	std::cout << mapa3[61] << std::endl;
	print_map(mapa3);

	std::cout << "Teste Range Constructor\n";
	it3_i = mapa2.find(50);
	it3_l = mapa2.find(100);
	ft::map<int, int> mapa4(it3_i, it3_l);
	print_map(mapa4);

	std::cout << "Teste Copy Constructor\n";
	ft::map<int, int> mapa5(mapa4);
	std::cout << "Mapa5: \n";
	print_map(mapa5);

	
	std::cout << "Teste swap:\n";

	ft::map<int,int> mapa_a(mapa0), mapa_b(mapa2);
	ft::map<int,int>::iterator first_a, first_b;
	first_a = mapa_a.begin();
	first_b = mapa_b.begin();
	std::cout << "mapa_a: \n"; print_map(mapa_a);
	std::cout << "first_a: " << first_a->first << std::endl;
	std::cout << "mapa_b: \n"; print_map(mapa_b);
	std::cout << "first_b: " << first_b->first << std::endl;
	mapa_a.swap(mapa_b);
	std::cout << "Apos Swap: \n";
	std::cout << "mapa_a: \n"; print_map(mapa_a);
	std::cout << "first_a: " << first_a->first << std::endl;
	std::cout << "first_a++: " << (++first_a)->first << std::endl;
	std::cout << "mapa_b: \n"; print_map(mapa_b);
	std::cout << "first_b: " << first_b->first << std::endl;
	std::cout << "first_b++: " << (++first_b)->first << std::endl;

	std::cout << "Teste const iterator\n";
	ft::map<int, int>::iterator it_normal = mapa_a.begin();
	ft::map<int, int>::const_iterator it_const = mapa_a.begin();
	std::cout << "it_normal: " << it_normal->first << std::endl;
	std::cout << "it_const: " << it_const->first << std::endl;
	std::cout << "Iguais ? " << (it_normal == it_const) << std::endl;

*/


	






	// ==========================================
	fin = clock();
	elapsed_time = 1000 * ((double) fin - (double) ini) / (double) (CLOCKS_PER_SEC);
	std::cout << "Elapsed time: " << elapsed_time << "ms" << std::endl;

};
