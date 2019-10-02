// Lambdas as in C++20 standard
// Python, here we come

#include <iostream>
#include <vector>

int main(void){

	// Lambdas before C++20

	auto before_20 = [](auto first, auto second){
		return first + second;
	};

	std::cout << before_20(4,5) << '\n';

	// C++20 introduced template
	// syntax for lambdas

	// By using template syntax both the
	// parameters to lambda should be of
	// same type

	auto after_20 = []<typename T>(T first, T second){
		return first + second;
	};

	std::cout << after_20(4,6) << '\n';

	// Parameter to the lambda should be
	// a vector of any type T
	
	auto length = []<typename T>(const std::vector<T> &v){
		return v.size();
	};

	std::vector<int> vec{1,2,3,4};

	std::cout << length(vec) << '\n';

	return 0;
}

