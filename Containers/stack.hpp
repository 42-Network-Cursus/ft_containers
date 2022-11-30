#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft 
{
	template <	typename T,
				typename Container = ft::vector<T>
			 >
	class stack 
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		// CONSTRUCTOR --------------------------------------------------------------------------------------------------------------
			// explicit keyword : cannot be used for implicit conversions and copy-initialization. 
			// More info https://en.cppreference.com/w/cpp/language/explicit
explicit	stack (const container_type& ctnr = container_type() ) : _c(ctnr) {}
		// ---------------------------------------------------------------------------------------------------------------------------
		// MEMBER FUNCTIONS ----------------------------------------------------------------------------------------------------------
			bool 				empty ()	const				{ return (_c.empty() ); }
			size_type 			size ()		const				{ return (_c.size() ); }

			value_type& 		top ()							{ return (_c.back() ); }
			const value_type& 	top ()		const 				{ return (_c.back() ); }

			void 				push (const value_type& val)	{ _c.push_back(val); }
			void 				pop () 							{ _c.pop_back(); }
		// ---------------------------------------------------------------------------------------------------------------------------
		// RELATIONAL OPERATORS ------------------------------------------------------------------------------------------------------
			// Friend keyword: grants operator overloads access to private/protected members of underlying container
			friend  bool operator== (const stack& lhs, const stack& rhs) { return (lhs._c == rhs._c); }
			friend  bool operator!= (const stack& lhs, const stack& rhs) { return (lhs._c != rhs._c); }
			friend  bool operator<  (const stack& lhs, const stack& rhs) { return (lhs._c < rhs._c); }
			friend  bool operator<= (const stack& lhs, const stack& rhs) { return (lhs._c <= rhs._c); }
			friend  bool operator>  (const stack& lhs, const stack& rhs) { return (lhs._c > rhs._c); }
			friend  bool operator>= (const stack& lhs, const stack& rhs) { return (lhs._c >= rhs._c); }
		// ---------------------------------------------------------------------------------------------------------------------------
		protected:
			container_type	_c;

	}; // END class stack
}  // END namespace ft

#endif // STACK_HPP