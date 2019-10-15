/* Templates are used when:
 * Identical operations need to be performed on two or more types of data.
 * Advantage:
 * Code becomes maintainable and readable.
 * Types:
 * Function Template
 * Class Template
 */

#include <iostream>

using namespace std;

/* In the code below, T is a template argument
 * that accepts different datatypes.
 * typename is a keyword, we can also use
 * class in place of it.
 */

template <typename T>
T Small(T n1, T n2)
{
	return ((n1 < n2) ? n1 : n2);
}


int main(void){

	// Testing the function template with different parameters
	int a, b;
	float f1, f2;
	char c1, c2;

	cout << "Enter two integers: " << '\n';
	cin  >> a >> b;

	cout << Small(a,b) << " is smaller.\n";

	cout << "Enter two floating point numbers: " << '\n';
	cin  >> f1 >> f2;

	cout << Small(f1,f2) << " is smaller.\n";

	cout << "Enter two characters: " << '\n';
	cin  >> c1 >> c2;

	cout << Small(c1,c2) << " has smaller ASCII value.\n";

	return 0;
}

