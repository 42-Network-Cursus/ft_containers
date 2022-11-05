#ifndef NODE_HPP
# define NODE_HPP

# include <iostream> // TO DEL

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
			: colour(RED), parent(NULL), leftChild(NULL), rightChild(NULL), value(value_type()) 
			{}

			Node (const value_type& val) 
			: colour(RED), value(val), parent(NULL), leftChild(NULL), rightChild(NULL) 
			{}
		// ----------------------------------------------------------------------------
			Node& operator= (const Node& rhs) 
			{
				// value = value_type(rhs.value);
				colour		= rhs.colour;
				parent		= rhs.parent;
				leftChild	= rhs.leftChild;
				rightChild	= rhs.rightChild;
				return (*this);
			}


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

		//
		Node	*next () // Maybe implement in iterator directly
		{
			Node	*tmp = this;

			//case 1
			if (tmp->r_child)
			{
				tmp = tmp->r_child;
				while (tmp->l_child)
					tmp = tmp->l_child;
			}

			//case 2
			else
			{
				Node *tmp_parent = tmp->parent;
				while (tmp == tmp_parent->r_child)
				{
					tmp = tmp_parent;
					tmp_parent = tmp_parent->parent;
				}
				//case 3
				if (tmp->r_child != tmp_parent)
					tmp = tmp_parent;
			}
		}

		Node	*prev () // Maybe implement in iterator directly
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
		}
		// -----------------------------------------------------------------------------------
		
	}; // END class Node

} // END namespace ft

#endif // NODE_HPP