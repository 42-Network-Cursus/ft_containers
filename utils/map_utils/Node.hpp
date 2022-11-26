#ifndef NODE_HPP
# define NODE_HPP

# include <iostream> // TO DEL

# include "pair.hpp"

namespace ft
{
	enum NodeColour { RED, BLACK };

	template<	typename Key,
				typename T
			>
	class Node
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;

		// MEMBER VARIABLES --------------------------------------------------------
			NodeColour	colour;	
			value_type	value;

			Node		*parent;
			Node		*l_child;
			Node		*r_child;
		// --------------------------------------------------------------------------
		// CONSTRUCTORS --------------------------------------------------------------
			Node () 
			: colour(RED), parent(NULL), l_child(NULL), r_child(NULL), value(value_type()) 
			{}

			Node (const value_type& val) 
			: colour(RED), value(val), parent(NULL), l_child(NULL), r_child(NULL) 
			{}

			Node (const Node& rhs) 
			: colour(rhs.colour), value(rhs.value), parent(rhs.parent), l_child(rhs.l_child), r_child(rhs.r_child) 
			{}
		// ----------------------------------------------------------------------------
			Node& operator= (const Node& rhs) 
			{
				// value = value_type(rhs.value);
				colour		= rhs.colour;
				parent		= rhs.parent;
				l_child	= rhs.l_child;
				r_child	= rhs.r_child;
				return (*this);
			}

			const key_type&	getKey () const { return value.first; }

			Node	*getMin()
			{
				Node	*tmp = this;
				while (tmp->l_child)
					tmp = tmp->l_child;
				return tmp;
			}

			Node	*getMax()
			{
				Node	*tmp = this;
				while (tmp->r_child)
					tmp = tmp->r_child;
				return tmp;
			}

			Node	*next () // Maybe implement in iterator directly
			{
				Node	*tmp = this;

				if (tmp->r_child)
				{
					tmp = tmp->r_child;
					while (tmp->l_child)
						tmp = tmp->l_child;
				}
				else
				{
					Node *tmp_parent = tmp->parent;
					while (tmp == tmp_parent->r_child)
					{
						tmp = tmp_parent;
						tmp_parent = tmp_parent->parent;
					}
					if (tmp->r_child != tmp_parent)
						tmp = tmp_parent;
				}
				return tmp;
			}

			Node	*prev() // Maybe implement in iterator directly
			{
				Node *tmp = this;
				// case 1 if tmp == header, r_child of header is MAX_VAL of tree
				if (tmp->colour == RED && (tmp->parent->parent == tmp) )
					tmp = tmp->r_child;
				// case 2
				else if (tmp->l_child)
				{
					tmp = tmp->l_child;
					while (tmp->r_child)
						tmp = tmp->r_child;
				}
				// case 3
				else
				{
					Node *tmp_parent = tmp->parent;
					while (tmp == tmp_parent->l_child)
					{
						tmp = tmp_parent;
						tmp_parent = tmp_parent->parent;
					}
					tmp = tmp_parent;
				}
				return tmp;
			}
		// -----------------------------------------------------------------------------------
		
	}; // END class Node

} // END namespace ft

#endif // NODE_HPP