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
		
		// CONSTRUCTORS
			Node () : colour(RED), parent(NULL), leftChild(NULL), rightChild(NULL) 
			{
				data.first	= key_type();
				data.second	= mapped_type();
			}

			Node (const value_type& val) 
			: colour(RED), data(val), parent(NULL), leftChild(NULL), rightChild(NULL) 
			{}
		// ----------------------------------------------------------------------------
			Node& operator= (const Node& rhs) 
			{
				// data = value_type(rhs.data);
				colour		= rhs.colour;
				parent		= rhs.parent;
				leftChild	= rhs.leftChild;
				rightChild	= rhs.rightChild;
				return (*this);
			}

		// private:
			NodeColour	colour;	
			value_type	data;

			Node		*parent;
			Node		*leftChild;
			Node		*rightChild;
	
	}; // END class Node

} // END namespace ft

#endif // NODE_HPP