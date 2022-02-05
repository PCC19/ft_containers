#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP


namespace ft
{

	template <class C>
	class random_access_iterator
	{
		public:
		typedef typename C::pointer				pointer;
		typedef typename C::reference			reference;


		// Methods
		random_access_iterator () {};
		random_access_iterator (pointer const p): _ptr(p) {};
		random_access_iterator (random_access_iterator const & src) {*this = src;};

		~random_access_iterator () {};

		random_access_iterator & operator=(random_access_iterator const & rhs)
		{
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		};

		reference operator *()	const { return *_ptr; };
		pointer operator ->()	const { return  _ptr; };

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
			
		protected:
		pointer _ptr;

	};



}
#endif
