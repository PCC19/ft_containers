
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

	// OVERLOADS
	template <class T1, class T2>
	bool operator==(const pair<T1,T2> &lhs, const pair<T1, T2> &rhs)
	{
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return true;
		else
			return false;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2> &lhs, const pair<T1, T2> &rhs)
	{
		if (lhs.first < rhs.first)		return (true);
		if (lhs.first > rhs.first)		return (false);
		if (lhs.second < rhs.second)	return (true);
		return (false);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2> &lhs, const pair<T1, T2> &rhs)
	{
		if (lhs < rhs || lhs == rhs) return (true);
		return (false);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2> &lhs, const pair<T1, T2> &rhs)
	{
		if (lhs > rhs || lhs == rhs) return (true);
		return (false);
	}

	template<typename T1, typename T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x,y));
	};

};

#endif

