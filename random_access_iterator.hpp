#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{

	template <class C>
	class random_access_iterator
	{
		public:
		// Types
		typedef typename C::pointer				pointer;
		typedef typename C::reference			reference;
		typedef typename C::size_type			size_type;
		typedef typename C::difference_type		difference_type;

		// Methods
		random_access_iterator ()									{};
		random_access_iterator (pointer const p): _ptr(p)			{};
		random_access_iterator (random_access_iterator const & src) {*this = src;};

		~random_access_iterator () {};

		random_access_iterator & operator=(random_access_iterator const & rhs)
		{
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		};

		// Dereferences
		reference operator *()	const		{ return *_ptr; };
		pointer operator ->()	const		{ return  _ptr; };
		reference operator[](size_type i)	{ return _ptr[i]; };

		// Increments / decrements
		random_access_iterator & operator++ ()
		{
			this->_ptr++;
			return *this;
		}
		random_access_iterator & operator-- ()
		{
			_ptr--;
			return *this;
		}
		random_access_iterator operator++(int)
		{
			random_access_iterator tmp;

			tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		random_access_iterator operator--(int)
		{
			random_access_iterator tmp;

			tmp = *this;
			this->_ptr--;
			return (tmp);
		}

		// Arithmetics:
		random_access_iterator operator+(size_type n) const
		{
			random_access_iterator tmp;
			tmp._ptr = _ptr + n;
			return (tmp);
		}
		random_access_iterator operator-(size_type n) const
		{
			random_access_iterator tmp;
			tmp._ptr = _ptr - n;
			return (tmp);
		}
		random_access_iterator operator+=(size_type n)
		{
			_ptr = _ptr + n;
			return (*this);
		}
		random_access_iterator operator-=(size_type n)
		{
			_ptr = _ptr - n;
			return (*this);
		}
		difference_type	operator-(random_access_iterator const & x) const
		{
			return (_ptr - x._ptr);
		}

		//Relational
		bool operator==(random_access_iterator const & x) const
		{
			return (_ptr == x._ptr);
		}
		bool operator!=(random_access_iterator const & x) const
		{
			return (_ptr != x._ptr);
		}
		bool operator>(random_access_iterator const & x) const
		{
			return (_ptr > x._ptr);
		}
		bool operator>=(random_access_iterator const & x) const
		{
			return (_ptr >= x._ptr);
		}
		bool operator<(random_access_iterator const & x) const
		{
			return (_ptr < x._ptr);
		}
		bool operator<=(random_access_iterator const & x) const
		{
			return (_ptr <= x._ptr);
		}
			
		// Atributes
		protected:
		pointer _ptr;

	};

}
#endif
