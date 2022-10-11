#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

namespace ft {
	class OUTOFRANGE : std::exception {
		public:
			virtual const char* what() throw() {
				return ("Out of range");
			}
	};
}

#endif