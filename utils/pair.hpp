#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <typename T1, typename T2> 
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		private:
			first_type	first;
			second_type	second;
		
	};

	template <class T1, class T2>  
	ft::pair<T1,T2> make_pair (T1 x, T2 y) {
		return ( ft::pair<T1,T2>(x,y) );
	}
	
}	// END namespace ft

#endif // PAIR_HPP