
#ifndef PAIRS_HPP
# define PAIRS_HPP

namespace ft 
{
	template <typename T1, typename T2>
	struct pair
	{
	// types
			typedef		T1		first_type;
			typedef		T2		second_type;

	// atributes
			first_type		first;
			second_type		second;

	// methods
		public:
			//constructors
			pair(): first(T1()), second(T2()) {};
			
			template<typename X, typename Y>
			pair(const pair<X, Y> &input_pair)
				:first(input_pair.first), second(input_pair.second) {};
			
			pair(const first_type &f, const second_type &s)
				:first(f), second(s) {};

			pair& operator=(const pair &other)
			{
				first = other.first;
				second = other.second;
				return (*this);
			};


	};
};

#endif

