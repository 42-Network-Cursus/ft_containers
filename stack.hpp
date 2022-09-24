#ifndef STACK_HPP
# define STACK_HPP

#include <algorithm>
#include <vector> // Delete and replace by ft::vector

namespace ft {

	template <	typename T,
				typename Container = std::vector<T> // must use ft::vector<T> as default
			 >
	class stack {

		public:
			
			// First template parameter
			typedef T			value_type;

			// Second template parameter
			typedef Container	container_type;

			typedef size_t		size_type;

		protected:

			container_type	_c;

		public:

			//Constructor

			// explicit : 
			explicit stack( const container_type& ctnr = container_type() ) : _c(ctnr) {}
		
			// Member Functions

			bool 				empty() const {
				return ( _c.empty() );
			}

			size_type 			size() const {
				return ( _c.size() );
			}

			value_type& 		top() {
				return ( _c.back() );
			}

			const value_type& 	top() const {
				std::cout << "const top" << std::endl;
				return ( _c.back() );
			}

			void 				push (const value_type& val) {
				_c.push_back( val );
			}

			void 				pop() {
				_c.pop_back();
			}

			/***************************** RELATIONAL OPERATORS *****************************/
			
			// Friend keyword: grants operators access to private/protected underlying container
			template <class Tx, class Containerx>
			friend  bool operator== (const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs);

			template <class Tx, class Containerx>
			friend  bool operator!= (const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs);

			template <class Tx, class Containerx>
			friend  bool operator<  (const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs);

			template <class Tx, class Containerx>
			friend  bool operator<= (const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs);
			
			template <class Tx, class Containerx>
			friend  bool operator>  (const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs);

			template <class Tx, class Containerx>
			friend  bool operator>= (const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs);
			
	}; // END class stack

	// Non-member RELATIONAL OPERATORS
	// Calls the relational operator between the underlying containers

	template <class T, class Container>  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs._c == rhs._c)
			return true;
		return false;
	}
	
	template <class T, class Container>  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs._c != rhs._c)
			return true;
		return false;
	}

	template <class T, class Container>  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs._c < rhs._c)
			return true;
		return false;
	}

	template <class T, class Container>  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs._c <= rhs._c)
			return true;
		return false;
	}
	
	template <class T, class Container>  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs._c > rhs._c)
			return true;
		return false;
	}

	template <class T, class Container>  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		if (lhs._c >= rhs._c)
			return true;
		return false;
	}

}  // END namespace ft

#endif // STACK_HPP