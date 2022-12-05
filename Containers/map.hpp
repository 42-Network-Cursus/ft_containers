#ifndef MAP_HPP
# define MAP_HPP

# include "Utility/iterator/Bidirectional_iterator.hpp"
# include "Utility/iterator/reverse_iterator.hpp"
# include "Utility/Rbtree/Red_black_tree.hpp"
# include "Utility/utils/Utility_functions.hpp"
# include "Utility/utils/pair.hpp"

namespace ft 
{
	template<	typename Key, 
				typename T, 
				typename Compare = std::less<Key>, 
				typename Alloc = std::allocator<ft::pair<const Key, T> > 
			>
	class map 
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef	Red_black_tree<Key, value_type, Compare, Alloc>		RBTree;

			typedef	Compare										key_compare;
			typedef Alloc										allocator_type;

			typedef	value_type&									reference;
			typedef const value_type&							const_reference;
			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;
			
			typedef ft::Bidirectional_iterator<Key, value_type>			iterator;
			typedef ft::Bidirectional_iterator<Key, value_type, true>	const_iterator;

			typedef ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;	

			typedef ptrdiff_t									difference_type;
			typedef size_t 										size_type;

			class value_compare
			{   
				public:
					friend class map<key_type, mapped_type, key_compare, allocator_type>;

					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
				
					bool operator() (const value_type& x, const value_type& y) const 
					{ 
						return comp(x.first, y.first); 
					}

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
			}; 
			
		// CONSTRUCTORS ---------------------------------------------------------------------------------------------------------------------
explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc) {}
			
			template <class InputIt>  
			map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc)
			{
				for (; first != last; first++)
					_tree.insert(*first);
			}
			
			map(const map& x) 
			{
				const_iterator it = x.begin();
				const_iterator ite = x.end();

				for (; it != ite; it++)
					_tree.insert(*it);
			}
		// DESTRUCTOR -----------------------------------------------------------------------------------------------------------------------
			~map() 
			{ 
				clear();
			}
		// ASSIGNMENT OPERATOR --------------------------------------------------------------------------------------------------------------
			map& operator= (const map& rhs)
			{
				clear();
				const_iterator it = rhs.begin();
				const_iterator ite = rhs.end();

				for (; it != ite; it++)
					_tree.insert(*it);
				return *this;
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// ITERATORS ------------------------------------------------------------------------------------------------------------------------
			iterator				begin()				{ return _tree.begin(); }
			const_iterator			begin()		const	{ return _tree.begin(); }

			iterator 				end() 				{ return _tree.end(); } // { return iterator(_tree.end()); }
			const_iterator 			end() 		const 	{ return _tree.end(); } //const_iterator(_tree.end());

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
		// ELEMENT ACCESS -------------------------------------------------------------------------------------------------------------------
			mapped_type& operator[] (const key_type& k)
			{
				pair<iterator,bool> p = insert(ft::make_pair(k, mapped_type()));
				return (*(p.first)).second;
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// MODIFIERS ------------------------------------------------------------------------------------------------------------------------
		// ---------- INSERTION -------------------------------------------------------------------------------------------------------------
			ft::pair<iterator, bool> insert (const value_type& val) 
			{ 
				return _tree.insert(val); 
			}

			iterator insert (iterator position, const value_type& val) 
			{
				return _tree.insertHint(position, val);
			}

			template <class InputIt>  
			void insert (InputIt first, InputIt last) 
			{
				for (; first != last; first++)
					_tree.insert(*first);
			}
		// ---------- DELETION --------------------------------------------------------------------------------------------------------------
			void erase (iterator position) 
			{
				_tree.erase(position);
			}

			size_type erase (const key_type& k) 
			{
				size_type prev_size = size();
				iterator it = find(k);

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
			void swap (map& x)
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
				return value_compare(key_compare());
				// return value_compare(_tree.key_comp());
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// OPERATIONS -----------------------------------------------------------------------------------------------------------------------
			iterator		find (const key_type& k)			{ return _tree.find(k); }
			const_iterator	find (const key_type& k)	const	{ return _tree.find(k); }

			iterator		lower_bound (const key_type& k)			{ return _tree.lower_bound(k); }
			const_iterator	lower_bound (const key_type& k)	const	{ return _tree.lower_bound(k); }

			iterator		upper_bound (const key_type& k) 		{ return _tree.upper_bound(k); }
			const_iterator	upper_bound (const key_type& k)	const	{ return _tree.upper_bound(k); }
			
			size_type count (const key_type& k) const
			{
				if (find(k) == end())
					return 0;
				return 1;
			}

			ft::pair<iterator, iterator>             equal_range (const key_type& k) 
			{ 
				return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)); 
			}

			ft::pair<const_iterator, const_iterator> equal_range (const key_type& k)	const 
			{ 
				return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)); 
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// RELATIONAL OPERATORS -------------------------------------------------------------------------------------------------------------  
			friend bool operator== ( const map& lhs, const map& rhs )
			{
				if (lhs.size() == rhs.size())
					return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				return (false);
			}
			
			friend bool operator<  ( const map& lhs, const map& rhs )
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); 
			}
  
			friend bool operator!= ( const map& lhs, const map& rhs ) { return (!(lhs == rhs)); }
			friend bool operator<= ( const map& lhs, const map& rhs ) { return (!(rhs < lhs)); }
			friend bool operator>  ( const map& lhs, const map& rhs ) { return (rhs < lhs); }
			friend bool operator>= ( const map& lhs, const map& rhs ) { return (!(lhs < rhs)); }
		// ----------------------------------------------------------------------------------------------------------------------------------
		private:
			RBTree				_tree;

			Compare				_comp;

			Alloc				_alloc;

	}; // END class map

	template <class Key, class T, class Compare, class Alloc>  
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

} // END namespace ft

#endif // MAP_HPP