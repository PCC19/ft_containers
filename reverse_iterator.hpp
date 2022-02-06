#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{

	template <class C>
	class reverse_iterator
	{
		public:
		// Types
		typedef typename C::pointer				pointer;
		typedef typename C::reference			reference;
		typedef typename C::size_type			size_type;
		typedef typename C::difference_type		difference_type;
		typedef typename C::iterator_category	iterator_category;

		// Methods
		reverse_iterator ()									{};
		reverse_iterator (pointer const p): _ptr(p)			{};
		reverse_iterator (reverse_iterator const & src) {*this = src;};

		~reverse_iterator () {};

		reverse_iterator & operator=(reverse_iterator const & rhs)
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
		reverse_iterator & operator++ ()
		{
			this->_ptr--;
			return *this;
		}
		reverse_iterator & operator-- ()
		{
			_ptr++;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp;

			tmp = *this;
			this->_ptr--;
			return (tmp);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp;

			tmp = *this;
			this->_ptr++;
			return (tmp);
		}

		// Arithmetics:
		reverse_iterator operator+(size_type n) const
		{
			reverse_iterator tmp;
			tmp._ptr = _ptr - n;
			return (tmp);
		}
		reverse_iterator operator-(size_type n) const
		{
			reverse_iterator tmp;
			tmp._ptr = _ptr + n;
			return (tmp);
		}
		reverse_iterator operator+=(size_type n)
		{
			_ptr = _ptr - n;
			return (*this);
		}
		reverse_iterator operator-=(size_type n)
		{
			_ptr = _ptr + n;
			return (*this);
		}
		difference_type	operator-(reverse_iterator const & x) const
		{
			return (_ptr + x._ptr);
		}

		//Relational
		bool operator==(reverse_iterator const & x) const
		{
			return (_ptr == x._ptr);
		}
		bool operator!=(reverse_iterator const & x) const
		{
			return (_ptr != x._ptr);
		}
		bool operator>(reverse_iterator const & x) const
		{
			return (_ptr < x._ptr);
		}
		bool operator>=(reverse_iterator const & x) const
		{
			return (_ptr <= x._ptr);
		}
		bool operator<(reverse_iterator const & x) const
		{
			return (_ptr > x._ptr);
		}
		bool operator<=(reverse_iterator const & x) const
		{
			return (_ptr >= x._ptr);
		}
			
		// Atributes
		protected:
		pointer _ptr;

	};

}
#endif
