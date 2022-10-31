#ifndef IS_INTEGRAL
# define IS_INTEGRAL

namespace ft 
{
	// Base template, defaults to false
	template <typename T> 
	struct is_integral { static const bool value = false; };

	// Specializations for integral types
	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<wchar_t> { static const bool value = true; }; // Not used anymore ?

	template <>
	struct is_integral<signed char> { static const bool value = true; };

	template <>
	struct is_integral<short int> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long int> { static const bool value = true; };

	template <>
	struct is_integral<long long int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long int> { static const bool value = true; };

} // END namespace ft

#endif // IS_INTEGRAL