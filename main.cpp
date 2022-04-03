/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:32:59 by pcunha            #+#    #+#             */
/*   Updated: 2022/04/03 22:11:36 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <typeinfo>
#include <map>

#define CYAN			"\e[0;36m"
#define C_RED			"\e[0;31m"
#define RESET			"\e[0m"
#define BOLD			"\e[1m"

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
	#include <map>
	namespace ft = std;
#endif
#include "utils.hpp"



int main()
{
	clock_t ini;
	clock_t fin;
	double elapsed_time;
	int N;
	int i;

	(void) N;
	(void) i;
	

	if (V == 1)
		std::cout << "VERSION:  FT" << std::endl;
	else
		std::cout << "VERSION: STL" << std::endl;
	ini = clock();
	// Main program =============================
//	std::cout << "Hello World!" << std::endl;
//
//	ft::vector<int> my_vector;
//	print_vector(my_vector);
//	std::cout << "Is empty ? " << my_vector.empty() << std::endl;
//	std::cout << "Max size: " << my_vector.max_size() << std::endl;
//	std::cout << "Reserve 3\n";
//	my_vector.reserve(3);
//	print_vector(my_vector);
//
//	N = 5;
//	for (i = 0; i < N; i++)
//	{
//		my_vector.push_back(i * 10);
//		print_vector(my_vector);
//	}
//	print_vector(my_vector);
//
//	std::cout << "resize para menor!\n";
//	my_vector.resize(3,300);
//	print_vector(my_vector);
//	std::cout << "resize para maior!\n";
//	my_vector.resize(8,800);
//	print_vector(my_vector);
//
//	std::cout << "Is empty ? " << my_vector.empty() << std::endl;
//	
//	my_vector.pop_back();
//	std::cout << "pop_back !\n";
//	print_vector(my_vector);
//
//	std::cout << "at 2\n";
//	std::cout << my_vector.at(2) << std::endl;
////	std::cout << "at 200\n";
////	std::cout << my_vector.at(200) << std::endl;
//
////	my_vector.clear();
////	std::cout << "Clear !\n";
////	print_vector(my_vector);
//
//	N = 5;
//	for (i = 0; i < N; i++)
//	{
//		my_vector.push_back(i * 10);
//	}
//	std::cout << "My Vector:\n";
//	print_vector(my_vector);
//	
//	ft::vector<int> other_vector;
//	N = 17;
//	for (i = 0; i < N; i++)
//	{
//		other_vector.push_back(i * (-10));
//	}
//	std::cout << "Other Vector:\n";
//	print_vector(other_vector);
//	my_vector.swap(other_vector);
//	std::cout << "After swap !!\n";
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Other Vector:\n"; print_vector(other_vector);
//
//	std::cout << "ft::vector<int> second_vector(my_vector);\n";
//	ft::vector<int> second_vector(my_vector);
//	my_vector.push_back(99);
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Sec Vector:\n"; print_vector(second_vector);
//	my_vector.push_back(1);
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Sec Vector:\n"; print_vector(second_vector);
//
//	ft::vector<int>::iterator	it_1;
//	ft::vector<int>*			p;
//	p = &my_vector;
//	std::cout << "           my_vector: " << &my_vector << std::endl;
//	std::cout << "pointer to my_vector: " << p << std::endl;
////	ft::vector<int>::iterator  it_2(p);
//
//	my_vector = second_vector; // assign para menor
//	std::cout << "my_vector = second_vector\n";
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Sec Vector:\n"; print_vector(second_vector);
//
//	my_vector = other_vector; // assign para maior
//	std::cout << "my_vector = other_vector\n";
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Other Vector:\n"; print_vector(other_vector);
//
//	ft::vector<int>::iterator itb;
//	ft::vector<int>::iterator ite;
//
//	std::cout << "ITERATORS: \n";
//	itb = my_vector.begin();
//	ite = my_vector.end();
//
//	--ite;
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "begin       element: " << *itb << std::endl;
//	std::cout << "  end       element: " << *(ite) << std::endl;
//	std::cout << "begin pos 1 element: " << *(itb++) << " : " << *itb << std::endl;
//	std::cout << "  end       element: " << *(ite) << std::endl;
//	std::cout << "begin pre 1 element: " << *(++itb) << std::endl;
//	std::cout << "  end       element: " << *(ite) << std::endl;
//
//	std::cout << "Arithmetics: \n";
//	ft::vector<int>::iterator it;
//	itb = my_vector.begin();
//	it = itb;
//	std::cout << "it = itb + n: \n";
//	std::cout << "begin       element: " << *itb << std::endl;
//	it = itb + 1; std::cout << "begin + 1: " << *(it) << std::endl;
//	it = itb + 2; std::cout << "begin + 2: " << *(it) << std::endl;
//	it = itb + 3; std::cout << "begin + 3: " << *(it) << std::endl;
//	std::cout << "it += n";
//	std::cout << "begin       element: " << *itb << std::endl;
//	it = itb; it+=1; std::cout << "begin += 1: " << *(it) << std::endl;
//	std::cout << "it - begin: " << (it - itb) << std::endl;
//	it = itb; it+=2; std::cout << "begin += 2: " << *(it) << std::endl;
//	std::cout << "it - begin: " << (it - itb) << std::endl;
//	it = itb; it+=3; std::cout << "begin += 3: " << *(it) << std::endl;
//	std::cout << "it - begin: " << (it - itb) << std::endl;
//	std::cout << "begin       element: " << *itb << std::endl;
//	std::cout << "begin[1]: " << (itb[1]) << std::endl;
//	std::cout << "begin[2]: " << (itb[2]) << std::endl;
//	std::cout << "begin[3]: " << (itb[3]) << std::endl;
//	std::cout << "Relational: \n";
//	std::cout << "itb = begin   ite = end: \n";
//	std::cout << "begin == end ? " << (itb == ite) << std::endl;
//	std::cout << "begin != end ? " << (itb != ite) << std::endl;
//	std::cout << "begin <  end ? " << (itb <  ite) << std::endl;
//	std::cout << "begin >  end ? " << (itb >  ite) << std::endl;
//	std::cout << "begin <= end ? " << (itb <= ite) << std::endl;
//	std::cout << "begin >= end ? " << (itb >= ite) << std::endl;
//	std::cout << "itb = begin   ite = begin: \n";
//	ite = itb;
//	std::cout << "begin == end ? " << (itb == ite) << std::endl;
//	std::cout << "begin != end ? " << (itb != ite) << std::endl;
//	std::cout << "begin <  end ? " << (itb <  ite) << std::endl;
//	std::cout << "begin >  end ? " << (itb >  ite) << std::endl;
//	std::cout << "begin <= end ? " << (itb <= ite) << std::endl;
//	std::cout << "begin >= end ? " << (itb >= ite) << std::endl;
//
//	std::cout << "Reverse Iterators: \n";
//	ft::vector<int>::reverse_iterator rit, ritb, rite;
//	ritb = my_vector.rbegin();
//	rite = my_vector.rend();
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Reversed: \n";
//	for (rit = ritb; rit != rite; rit++)
//		std::cout << *rit << "|";
//	std::cout << std::endl;
//
//	std::cout << "Front and Back: \n";
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Front: " << my_vector.front() << " back: " << my_vector.back() << std::endl;
//	std::cout << "Sec  Vector:\n"; print_vector(second_vector);
//	std::cout << "Front: " << second_vector.front() << "\t\tback: " << second_vector.back() << std::endl;
//
//	std::cout << "Assign menor que capacity: \n";
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	my_vector.assign(3, 13);
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	std::cout << "Assign maior que capacity: \n";
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	my_vector.assign(35, 13);
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//
//	std::cout << "Fill Constructor: \n";
//	ft::vector<int> fill_vector(5, 100);
//	std::cout << "Fill  Vector (5 100):\n"; print_vector(fill_vector);
//
//
//	// assign range
//	std::cout << "ASSIGN RANGE: \n";
//	my_vector.clear();
//	N = 10;
//	int j;
//	for (j = 1; j < N; j++) my_vector.push_back(j * 10);
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	ft::vector<int> from_my_vector;
//	from_my_vector.assign((my_vector.begin() + 2), (my_vector.end() - 2));
//	std::cout << "From My Vector (+2 -2): \n"; print_vector(from_my_vector);
//
//	// Constructor  range
//	std::cout << "CONSTRUCTTOR RANGE: \n";
//	my_vector.clear();
//	N = 10;
//	for (j = 1; j < N; j++) my_vector.push_back(j * 13);
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	ft::vector<int> range_con_vector((my_vector.begin() + 2), (my_vector.end() - 2));
//	std::cout << "Range_Con_Vector (+2 -2): \n"; print_vector(range_con_vector);
//
//
//	std::cout << "Erase position: \n";
//	my_vector.clear();
//	N = 10;
//	for (j = 1; j < N; j++) my_vector.push_back(j * 10);
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	ft::vector<int>::iterator it_erase, aux;
//	it_erase = my_vector.begin();
//	it_erase += 3;
//	aux = my_vector.erase(it_erase);
//	std::cout << "My Vector erased:\n"; print_vector(my_vector);
//	std::cout << "Position :" << *aux << std::endl;
//
//	std::cout << "Erase range: \n";
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	ft::vector<int>::iterator it_erase_end;
//	it_erase = my_vector.begin();
//	it_erase += 3;
//	it_erase_end = it_erase;
//	it_erase_end += 4;
//	std::cout << "first: " << *it_erase << " last: " << *it_erase_end << std::endl;
//	aux = my_vector.erase(it_erase, it_erase_end);
//	std::cout << "My Vector erased range :\n"; print_vector(my_vector);
//	std::cout << "Position :" << *aux << std::endl;
//
//	std::cout << "Insert position: \n";
//	ft::vector<int>::iterator it_insert_position;
//	it_insert_position = my_vector.begin();
//	it_insert_position += 3;
//	std::cout << "My Vector:\n"; print_vector(my_vector);
//	my_vector.insert(it_insert_position, 111);
//	std::cout << "My Vector insert 3:\n"; print_vector(my_vector);
//	std::cout << "Insert fill : \n";
//	my_vector.insert(it_insert_position, 3, 333);
//	std::cout << "My Vector insert 3, 3, 333:\n"; print_vector(my_vector);
//	std::cout << "Insert range : \n";
//	ft::vector<int> to_insert_range;
//	to_insert_range.push_back(1000);
//	to_insert_range.push_back(2000);
//	to_insert_range.push_back(3000);
//	std::cout << "to_insert_range"; print_vector(to_insert_range);
//	std::cout << "My Vector :\n"; print_vector(my_vector);
//	my_vector.insert((my_vector.begin() + 3), to_insert_range.begin(), to_insert_range.end());
//	std::cout << "Insert do vetor acima na pos 3 :\n"; print_vector(my_vector);
//
//	std::cout << "Teste do equal :\n";
//	ft::vector<int> v1, v2;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v2 = v1;
//	std::cout << "v1:\n"; print_vector(v1);
//	std::cout << "v2:\n"; print_vector(v2);
//	std::cout << "v1 == v2 ? : " << (v1 == v2) << std::endl;
//	v1.push_back(4);
//	std::cout << "v1:\n"; print_vector(v1);
//	std::cout << "v2:\n"; print_vector(v2);
//	std::cout << "v1 == v2 ? : " << (v1 == v2) << std::endl;
//	std::cout << "v1 != v2 ? : " << (v1 != v2) << std::endl;
//
//	std::cout << "Non Members overloads: \n";
//	v1.pop_back();
//	std::cout << "v1:\n"; print_vector(v1);
//	std::cout << "v2:\n"; print_vector(v2);
//	std::cout << "v1 <  v2 ? : " << (v1 < v2) << std::endl;
//	std::cout << "v1 <= v2 ? : " << (v1 <= v2) << std::endl;
//	std::cout << "v1 >  v2 ? : " << (v1 > v2) << std::endl;
//	std::cout << "v1 >= v2 ? : " << (v1 >= v2) << std::endl;
//	v1.push_back(5);
//	std::cout << "v1:\n"; print_vector(v1);
//	std::cout << "v2:\n"; print_vector(v2);
//	std::cout << "v1 <  v2 ? : " << (v1 < v2) << std::endl;
//	std::cout << "v1 <= v2 ? : " << (v1 <= v2) << std::endl;
//	std::cout << "v1 >  v2 ? : " << (v1 > v2) << std::endl;
//	std::cout << "v1 >= v2 ? : " << (v1 >= v2) << std::endl;
//
//	//Pair:
//	ft::pair<int, char>	par1(12, 'a');
//	ft::pair<int, std::string> par2(0, "Paulo");
//	std::cout << "pairs: \n";
//	print_pair(par1);
//	print_pair(par2);
//	ft::pair<int, int> par3, par4;
//	par3 = ft::make_pair(10,100);
//	par4 = ft::make_pair(10,100);
//	std::cout << "10 100 | 10 100\n";
//	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
//	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
//	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
//	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
//	par3 = ft::make_pair(10,100);
//	par4 = ft::make_pair(10,200);
//	std::cout << "10 100 | 10 200\n";
//	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
//	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
//	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
//	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
//	par3 = ft::make_pair(1,100);
//	par4 = ft::make_pair(10,100);
//	std::cout << "1 100 | 10 100\n";
//	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
//	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
//	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
//	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
//	par3 = ft::make_pair(20,100);
//	par4 = ft::make_pair(10,100);
//	std::cout << "20 100 | 10 100\n";
//	std::cout << "par3 < par4: " << (par3 < par4) << std::endl;
//	std::cout << "par3 > par4: " << (par3 > par4) << std::endl;
//	std::cout << "par3 == par4: " << (par3 == par4) << std::endl;
//	std::cout << "par3 != par4: " << (par3 != par4) << std::endl;
//
//
//	// Make_pair
//	ft::pair<char, std::string> par;
//	std::cout << "make_pair: \n";
//	par = ft::make_pair('o', "paulo");
//	print_pair(par);
//
//
//	// debug node
//		ft::pair<int, std::string> par_0(0, "Paulo");
//		ft::pair<int, std::string> par_1(1, "Roberto");
//		ft::pair<int, std::string> par_2(2, "Cunha");
//			print_pair(par_0);
//			print_pair(par_1);
//			print_pair(par_2);
//
//		typedef rbt_node<ft::pair<int, std::string> >  node;
//		node no_0(&par_0);
//		node no_1(&par_1);
//		node no_2(&par_2);
//
//		std::cout << "node: \n";
//		print_node(no_0);
//		print_node(no_1);
//		print_node(no_2);
//	
//	// simple map
//	std::map<int, int> mapa;
//	mapa[70] = 70;
//	mapa[50] = 50;
//	mapa[20] = 20;
//	mapa[10] = 10;
//	mapa[80] = 80;
//	mapa[40] = 40;
//	mapa[60] = 60;
//	mapa[30] = 30;
//	std::map<int, int>::iterator itm;
//
//	itm = mapa.begin();
//	while (itm != mapa.end())
//	{
//		std::cout << itm->first << std::endl;
//		itm++;
//	}
//
//	// Teste primeiro insert
//	std::cout << "Teste primeiro insert\n";
//	ft::map<int, int>	mapa0;
//	ft::pair<int, int>	par_a;
//
//	par_a = ft::make_pair(10,100);
//	print_pair(par_a);
//
//	std::cout << "Teste begin e end\n";
//	mapa0.insert(par_a);
//	par_a = ft::make_pair(20,100);
//	mapa0.insert(par_a);
//	mapa0.insert(ft::make_pair(5,100));
//	ft::map<int, int>::iterator it_mapa0;
//	it_mapa0 = mapa0.begin();
//	std::cout << "begin(): \n";
//	std::cout << it_mapa0->first << std::endl;
//	it_mapa0 = mapa0.end();
//	std::cout << "end(): \n";
//	std::cout << (--it_mapa0)->first << std::endl;
//
//
//
//	// Cria map para testes
//	std::cout << "Mapa para testes: \n";
//	ft::map<int, int> mapa1;
//	// 80 40 20 10 30 60 50 70 120 100 140 90 89 110 111 134 150 130 135 125
//	mapa1.insert(ft::make_pair(80,800));
//	mapa1.insert(ft::make_pair(40,400));
//	mapa1.insert(ft::make_pair(20,200));
//	mapa1.insert(ft::make_pair(10,1000));
//	mapa1.insert(ft::make_pair(30,300));
//	mapa1.insert(ft::make_pair(60,600));
//	mapa1.insert(ft::make_pair(50,500));
//	mapa1.insert(ft::make_pair(70,700));
//	mapa1.insert(ft::make_pair(120,1200));
//	mapa1.insert(ft::make_pair(100,1000));
//	mapa1.insert(ft::make_pair(140,1400));
//	mapa1.insert(ft::make_pair(90,900));
//	mapa1.insert(ft::make_pair(89,890));
//	mapa1.insert(ft::make_pair(110,1100));
//	mapa1.insert(ft::make_pair(111,1110));
//	mapa1.insert(ft::make_pair(134,1340));
//	mapa1.insert(ft::make_pair(150,1500));
//	mapa1.insert(ft::make_pair(130,1300));
//	mapa1.insert(ft::make_pair(135,1350));
//	mapa1.insert(ft::make_pair(125,1250));
//	ft::map<int, int>::iterator itm1;
//
//	// Teste find
//	std::cout << "Teste find: \n";
//	int x;
//	x = 90;
//	itm1 = mapa1.find(x);
//	if (itm1 != mapa1.end())
//	std::cout << "find(" << x << "): " << itm1->second << std::endl;
//	x = 110;
//	itm1 = mapa1.find(x);
//	if (itm1 != mapa1.end())
//	std::cout << "find(" << x << "): " << itm1->second << std::endl;
//	x = 13;
//	itm1 = mapa1.find(x);
//	if (itm1 != mapa1.end())
//		std::cout << "find(" << x << "): " << itm1->second << std::endl;
//	#if (V)
////		mapa1.print_tree_level();
//	#endif
//
//	// Teste operator ++
//	std::cout << "Teste operator ++it:\n";
//	std::cout << "Tem filho direito:\n";
//	itm1 = mapa1.find(40);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "++itm1: " << (++itm1)->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(30);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "++itm1: " << (++itm1)->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(111);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "++itm1: " << (++itm1)->first << std::endl;
//
//	std::cout << "Teste operator it++:\n";
//	std::cout << "Tem filho direito:\n";
//	itm1 = mapa1.find(40);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "itm1++: " << (itm1++)->first << std::endl;
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(30);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "itm1++: " << (itm1++)->first << std::endl;
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(111);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "itm1++: " << (itm1++)->first << std::endl;
//	std::cout << "itm1:   " << itm1->first << std::endl;
//
//	std::cout << "Teste operator --it:\n";
//	std::cout << "Tem filho direito:\n";
//	itm1 = mapa1.find(50);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "--itm1: " << (--itm1)->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(40);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "--itm1: " << (--itm1)->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(120);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "--itm1: " << (--itm1)->first << std::endl;
//
//	std::cout << "Teste operator it--:\n";
//	std::cout << "Tem filho direito:\n";
//	itm1 = mapa1.find(40);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "itm1--: " << (itm1--)->first << std::endl;
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(30);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "itm1--: " << (itm1--)->first << std::endl;
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "Nao Tem filho direito:\n";
//	itm1 = mapa1.find(111);
//	std::cout << "itm1:   " << itm1->first << std::endl;
//	std::cout << "itm1--: " << (itm1--)->first << std::endl;
//	std::cout << "itm1:   " << itm1->first << std::endl;
//
//	std::cout << "Teste count:\n";
//	std::cout << "30: " << mapa1.count(30) << std::endl;
//	std::cout << "31: " << mapa1.count(31) << std::endl;
//
//
//	std::cout << "Teste iterators, ++ e --\n";
//	ft::map<int, int>::iterator aux_end;
//	aux_end = mapa1.end();
//	aux_end--;
//	for (itm1 = mapa1.begin(); itm1 != mapa1.end(); itm1++)
//	{
//		std::cout << "itm: " << itm1->first;
//		if (itm1 != mapa1.begin())
//		{
//			std::cout << " a: " << (--itm1)->first; ++itm1;
//		};
//		if (itm1 != aux_end)
//		{
//			std::cout << " p: " << (++itm1)->first; --itm1;
//		};
//		std::cout << std::endl;
//	};
//	std::cout << "Teste reverse iterator: \n";
//
//	ft::map<int, int>::reverse_iterator itm1_r;
//	itm1_r = mapa1.rbegin();
//	std::cout << itm1_r->first << std::endl;
//	itm1_r = mapa1.rend();
//	itm1_r--;
//	std::cout << itm1_r->first << std::endl;
//	for (itm1_r = mapa1.rbegin(); itm1_r != mapa1.rend(); itm1_r++)
//		std::cout << itm1_r->first << " | ";
//	std::cout << std::endl;
//
//	std::cout << "Teste delete_node: \n";
//	std::cout << "Deleting 80 (two children)\n";
//		print_map(mapa1); mapa1.erase(80); print_map(mapa1);
//	std::cout << "Deleting 89 (two children)\n";
//		print_map(mapa1); mapa1.erase(89); print_map(mapa1);
//	std::cout << "Deleting 70 (no child)\n";
//		print_map(mapa1); mapa1.erase(70); print_map(mapa1);
//	std::cout << "Deleting 90 (one child)\n";
//		print_map(mapa1); mapa1.erase(90); print_map(mapa1);
//	std::cout << "Deleting 110 (one child)\n";
//		print_map(mapa1); mapa1.erase(110); print_map(mapa1);
//	std::cout << "Deleting 40 (two children)\n";
//		print_map(mapa1); mapa1.erase(40); print_map(mapa1);
//
//
//
//	std::cout << "Teste do Erase (position) 120\n";
//	ft::map<int, int>::iterator i_pos;
//
//	i_pos = mapa1.find(120);
//	mapa1.erase(i_pos);
////	mapa1.print_tree_level();
////	std::cout << "Teste do Erase (key) 100 \n";
////	mapa1.erase(100);
////	mapa1.print_tree_level();
//
//
//
////	std::cout << "Teste do Erase (first, last)\n";
////	ft::map<int, int>::iterator i_f, i_l;
//////	mapa1.print_tree_level();
////	i_f = mapa1.find(10);
////	i_l = mapa1.find(30);
////	mapa1.erase(i_f, i_l);
//////	mapa1.print_tree_level();
//
//	std::cout << "Teste do clear \n";
//	print_map(mapa1);
//	mapa1.clear();


	std::cout << "//////////////////////////////////////////////\n";
	std::cout << "Teste do rotate left: \n";
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


//		mapa2.print_tree_level();

	std::cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n";
	std::cout << "DEBUG FIX REMOVE\n";
	std::cout << "Inicial: \n"; mapa2.print_tree_level();
	int dd;
	(void) dd;
	// 80 40 20 10 30 60 50 70 120 100 140 90 89 110 111 134 150 130 135 125
	dd = 80; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 40; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 20; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 10; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 30; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 60; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 50; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 70; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 120; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 100; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 140; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 90; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 89; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 110; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 111; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 134; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 150; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 130; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 135; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	dd = 125; std::cout << "Deleting: " << dd << "\n"; mapa2.print_tree_level(); mapa2.erase(dd); mapa2.print_tree_level();
	return 0;

	int numero;
	numero = 80;
	std::cout << "rotate right:" << numero << std::endl;
//		mapa2.teste_rotate_right(numero);
//		mapa2.print_tree_level();
//	numero = 20;
//	std::cout << "rotate left :" << numero << std::endl;
//	mapa2.teste_rotate_left(numero);
//	mapa2.print_tree_level();
//	numero = 30;
//	std::cout << "rotate left :" << numero << std::endl;
//	mapa2.teste_rotate_left(numero);
//	mapa2.print_tree_level();
//	numero = 40;
//	std::cout << "rotate left :" << numero << std::endl;
//	mapa2.teste_rotate_left(numero);
//	mapa2.print_tree_level();
//	numero = 80;
//	std::cout << "rotate left :" << numero << std::endl;
//	mapa2.teste_rotate_left(numero);
//	mapa2.print_tree_level();
//	numero = 120;
//	std::cout << "rotate left :" << numero << std::endl;
//	mapa2.teste_rotate_left(numero);
//	mapa2.print_tree_level();
//	numero = 150;
//	std::cout << "rotate left :" << numero << std::endl;
//	mapa2.teste_rotate_left(numero);
//	mapa2.print_tree_level();

	

	std::cout << "Teste lower_bound & upper_bound\n";

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

	
//	std::cout << "Teste swap:\n";
//
//	ft::map<int,int> mapa_a(mapa0), mapa_b(mapa2);
//	std::cout << "mapa_a: \n"; print_map(mapa_a);
//	std::cout << "mapa_b: \n"; print_map(mapa_b);
//	std::cout << "Apos Swap: \n";
//	std::cout << "mapa_a: \n"; print_map(mapa_a);
//	std::cout << "mapa_b: \n"; print_map(mapa_b);



	






	// ==========================================
	fin = clock();
	elapsed_time = 1000 * ((double) fin - (double) ini) / (double) (CLOCKS_PER_SEC);
	std::cout << "Elapsed time: " << elapsed_time << "ms" << std::endl;

};
