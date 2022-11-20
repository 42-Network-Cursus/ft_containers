#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft 
{
	template <typename T1, typename T2> 
	struct pair 
	{
		typedef T1	first_type;
		typedef T2	second_type;

	//Member variables
		first_type	first;
		second_type	second;
		
	// CONSTRUCTORS
		pair () : first(first_type() ), second(second_type() ) {}
		pair (const first_type &a, const second_type &b) : first(a), second(b) {}
	
		template<typename U, typename V> 
		pair (const pair<U,V> &pr) : first(pr.first), second(pr.second) {}
	// -----------------------------------------------------------------------------

	// ASSIGMENT OPERATOR
	// implicitly declared ?
		// pair &operator= (const pair &pr) 
		// {
		// 	first	= pr.first;
		// 	second	= pr.second;
		// 	return (*this);
		// }
	// -----------------------------------------------------------------------------
	// RELATIONAL OPERATORS 
		template <class X, class Y>  
		friend bool operator== (const pair<X,Y> &lhs, const pair<X,Y> &rhs);

		template <class X, class Y>  
		friend bool operator!= (const pair<X,Y> &lhs, const pair<X,Y> &rhs);

		template <class X, class Y>  
		friend bool operator<  (const pair<X,Y> &lhs, const pair<X,Y> &rhs);

		template <class X, class Y>  
		friend bool operator<= (const pair<X,Y> &lhs, const pair<X,Y> &rhs);

		template <class X, class Y>  
		friend bool operator>  (const pair<X,Y> &lhs, const pair<X,Y> &rhs);

		template <class X, class Y>  
		friend bool operator>= (const pair<X,Y> &lhs, const pair<X,Y> &rhs);
	// -----------------------------------------------------------------------------
	}; // END struct pair

// Non-member RELATIONAL OPERATORS
	template <class T1, class T2>  
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
	
	template <class T1, class T2>  
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return ( !(lhs == rhs) ); }
	
	template <class T1, class T2>  
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return ( lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second) ); }

	template <class T1, class T2>  
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return ( !(rhs < lhs) ); }
		
	template <class T1, class T2>  
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs < lhs); }

	template <class T1, class T2>  
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return ( !(lhs < rhs) ); }
// ----------------------------------------------------------------------------------------------------------------------------------------

	template <class T1, class T2>  
	ft::pair<T1,T2> make_pair (T1 x, T2 y) { return ( ft::pair<T1,T2>(x,y) ); }

	template <class T1, class T2>
	std::ostream& operator<< (std::ostream& os, const ft::pair<T1, T2>  & rhs) {
		std::cout << rhs.first << " => " << rhs.second;
		return os;
	}
	
}	// END namespace ft

#endif // PAIR_HPP