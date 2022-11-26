template<typename Vector>
void	showData(Vector v) {
	typename Vector::iterator it = v.begin();
	typename Vector::iterator ite = v.end();
	
	while (it != ite) {
		std::cout << *it;
		it++;
		if (it != ite)
			std::cout << ", ";
	}
	std::cout << std::endl;
}