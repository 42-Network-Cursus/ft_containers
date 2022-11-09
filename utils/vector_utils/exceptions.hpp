#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

namespace ft {
	class OUTOFRANGE : std::exception {
		public:
		using std::exception::what;
			virtual const char* what() throw() {
				return ("Out of range");
			}
	};
}

#endif