#ifndef SET_HPP
# define SET_HPP

# include "Utility/Rbtree/Red_black_tree.hpp"
# include "Utility/iterator/Bidirectional_iterator.hpp"
# include "Utility/iterator/reverse_iterator.hpp"
# include "Utility/utils/Utility_functions.hpp"

namespace ft 
{
	template<	typename T,
				typename Compare = std::less<T>,
				typename Alloc = std::allocator<T>
			>
	class set
	{
		public:

			typedef T				key_type;
			typedef T				value_type;
			typedef ft::pair<T, T>	value_pair;

			typedef	Compare		key_compare;
			typedef Compare		value_compare;
			
			typedef Alloc	allocator_type;
			typedef	Red_black_tree<T, value_type, Compare, Alloc>		RBTree;

			typedef	value_type&									reference;
			typedef const value_type&							const_reference;

			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;

			typedef ft::Bidirectional_iterator<T, value_type>			iterator;
			typedef ft::Bidirectional_iterator<T, value_type, true>	const_iterator;

			typedef ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;	

			typedef ptrdiff_t									difference_type;
			typedef size_t 										size_type;

		// CONSTRUCTORS
explicit 	set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
			: _comp(comp), _alloc(alloc)
			{}
			
			template <class InputIt>  
			set (InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc)
			{
				for (; first != last; first++)
					_tree.insert(ft::make_pair(*first, *first));
			}
			
			set (const set& x)
			{
				const_iterator it = x.begin();
				const_iterator ite = x.end();

				for (; it != ite; it++)
					_tree.insert(*it);
			}
		// DESTRUCTOR --------------------------------------------------------
			~set()
			{
				clear();
			}
		// ASSIGMNEMT OPERATOR
			set& operator= (const set& rhs)
			{
				_tree = rhs._tree;
				return *this;
			}
		// -------------------------------------------------------------------

		// ----------------------------------------------------------------------------------------------------------------------------------
		// ITERATORS ------------------------------------------------------------------------------------------------------------------------
			iterator				begin()				{ return iterator((*_tree.begin()).first); }
			const_iterator			begin()		const	{ return const_iterator((*_tree.begin()).first); }

			iterator 				end() 				{ return iterator((*_tree.end()).first); }
			const_iterator 			end() 		const 	{ return const_iterator((*_tree.end()).first); }

			reverse_iterator		rbegin() 			{ return reverse_iterator(end()); }
			const_reverse_iterator	rbegin()	const	{ return const_reverse_iterator( end()); }

			reverse_iterator 		rend() 				{ return reverse_iterator( begin()); }
			const_reverse_iterator 	rend() 		const 	{ return const_reverse_iterator( begin()); }
		// ----------------------------------------------------------------------------------------------------------------------------------
		// CAPACITY -------------------------------------------------------------------------------------------------------------------------
			bool 			empty()			const	{ return (_tree.empty() ); } 
			size_type 		size()			const	{ return (_tree.size() ); }
			size_type 		max_size()		const	{ return (_tree.max_size() ); }
			allocator_type	get_allocator()	const	{ return (_tree.get_allocator() ); }
		// ----------------------------------------------------------------------------------------------------------------------------------
		// MODIFIERS ------------------------------------------------------------------------------------------------------------------------
		// ---------- INSERTION -------------------------------------------------------------------------------------------------------------

			pair<iterator,bool> insert (const value_type& val)
			{
				return _tree.insert(ft::make_pair(val, val));
			}

			iterator insert (iterator position, const value_type& val)
			{
				return _tree.insertHint(position, ft::make_pair(val, val));
			}

			template <class InputIt>  
			void insert (InputIt first, InputIt last)
			{
				for (; first != last; first++)
					_tree.insert(ft::make_pair(*first, *first));
			}
		// ---------- DELETION --------------------------------------------------------------------------------------------------------------
			void erase (iterator position)
			{
				_tree.erase(position);
			}

			size_type erase (const value_type& val)
			{
				size_type prev_size = size();
				iterator it = find(val);

				if (it != end())
					_tree.erase(it);
				return prev_size - size();
			}

			void erase (iterator first, iterator last)
			{
				iterator tmp = first;

				while (tmp != last)
				{	
					first++;
					_tree.erase(tmp);
					tmp = first;
				}
			}

			void clear()
			{
				_tree.clear();
			}
		// ---------- SWAP ------------------------------------------------------------------------------------------------------------------
			void swap (set& x)
			{
				_tree.swap(x._tree);
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// OBSERVERS ------------------------------------------------------------------------------------------------------------------------
			key_compare		key_comp()	const
			{
				return _tree.key_comp();
			}

			value_compare	value_comp() const
			{
				return value_compare(_tree.key_comp());
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// OPERATIONS -----------------------------------------------------------------------------------------------------------------------
			iterator find (const value_type& val) const { return _tree.find(val); }
			
			iterator lower_bound (const value_type& val) const { return _tree.lower_bound(val); }

			iterator upper_bound (const value_type& val) const { return _tree.upper_bound(val); }

			size_type count (const value_type& val) const
			{
				if (find(val) == end())
					return 0;
				return 1;
			}


			pair<iterator,iterator> equal_range (const value_type& val) const
			{ 
				return ft::make_pair<iterator, iterator>(lower_bound(val), upper_bound(val)); 
			}


		// RELATIONAL OPERATORS -------------------------------------------------------------------------------------------------------------  
			friend bool operator== ( const set& lhs, const set& rhs )
			{
				if (lhs.size() == rhs.size())
					return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				return (false);
			}
			
			friend bool operator<  ( const set& lhs, const set& rhs )
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); 
			}
  
			friend bool operator!= ( const set& lhs, const set& rhs ) { return (!(lhs == rhs)); }
			friend bool operator<= ( const set& lhs, const set& rhs ) { return (!(rhs < lhs)); }
			friend bool operator>  ( const set& lhs, const set& rhs ) { return (rhs < lhs); }
			friend bool operator>= ( const set& lhs, const set& rhs ) { return (!(lhs < rhs)); }
		// ----------------------------------------------------------------------------------------------------------------------------------

		private:
			RBTree	_tree;

			Compare	_comp;
			Alloc	_alloc;

	}; // END class set

	// -------------------------------------------------------------------------------------------
	template <class T, class Compare, class Alloc>  
	void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

} // END namespace ft

#endif // SET_HPP