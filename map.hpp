#ifndef MAP_HPP
# define MAP_HPP

# include "utils/map_utils/pair.hpp"
# include "utils/map_utils/Red_black_tree.hpp"
# include "utils/map_utils/Bidirectional_iterator.hpp"
# include "utils/iterator_utils/reverse_iterator.hpp"

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
			typedef	Red_black_tree<Key, T, Compare, Alloc>		RBTree;

			typedef	Compare										key_compare;
			typedef Alloc										allocator_type;

			typedef	value_type&									reference;
			typedef const value_type&							const_reference;
			typedef value_type*									pointer;
			typedef const value_type*							const_pointer;
			
			typedef ft::Bidirectional_iterator<Key, T>			iterator;
			typedef ft::Bidirectional_iterator<Key, T, true>	const_iterator;

			typedef ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;	

			typedef ptrdiff_t									difference_type;
			typedef size_t 										size_type;

			class value_compare
			{   
				public:
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
explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
			
			template <class InputIt>  
			map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
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
				_tree = rhs._tree;
				return *this;
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// ITERATORS ------------------------------------------------------------------------------------------------------------------------
			iterator				begin()				{ return iterator(_tree.begin()); }
			const_iterator			begin()		const	{ return const_iterator(_tree.begin()); }

			iterator 				end() 				{ return iterator(_tree.end()); }
			const_iterator 			end() 		const 	{ return const_iterator(_tree.end()); }

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
				pair<iterator,bool> p = insert(make_pair(k, mapped_type()));
				return (*(p.first)).second;
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// MODIFIERS ------------------------------------------------------------------------------------------------------------------------
		// ---------- INSERTION -------------------------------------------------------------------------------------------------------------
			pair<iterator,bool> insert (const value_type& val) 
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
				return value_compare(_tree.key_comp());
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		// OPERATIONS -----------------------------------------------------------------------------------------------------------------------
			iterator		find (const key_type& k)			{ return _tree.find(k); }
			const_iterator	find (const key_type& k)	const	{ return _tree.find(k); }

			size_type count (const key_type& k) const
			{
				if (find(k) == end())
					return 0;
				return 1;
			}

			iterator		lower_bound (const key_type& k)			{ return _tree.lower_bound(k); }
			const_iterator	lower_bound (const key_type& k)	const	{ return _tree.lower_bound(k); }

			iterator		upper_bound (const key_type& k) 		{ return _tree.upper_bound(k); }
			const_iterator	upper_bound (const key_type& k)	const	{ return _tree.upper_bound(k); }

			pair<iterator,iterator>             equal_range (const key_type& k) 
			{ 
				return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)); 
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k)	const 
			{ 
				return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)); 
			}
		// ----------------------------------------------------------------------------------------------------------------------------------
		private:
			RBTree				_tree;

	}; // END class map

} // END namespace ft

#endif // MAP_HPP