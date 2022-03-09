
#ifndef NODE_HPP
# define NODE_HPP

template <typename T>
struct rbt_node
{
	rbt_node(T* val = NULL): parent(NULL), left(NULL), right(NULL), color(RED), value(val) {};
	
	rbt_node<T> operator=(rbt_node<T> const & rhs)
	{
		if (*this != rhs)
		{
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			color = rhs.color;
			value = rhs.value;
		};
		return (*this);
	};

	typedef enum {RED, BLACK}	COLORS;
	rbt_node<T>	*parent;
	rbt_node<T>	*left;
	rbt_node<T>	*right;
	COLORS		color;
	T*			value;

};
#endif
