#include <iostream>
#include <iterator>

#include "alpha_iterator.h"

int main() 
{
	std::string s("1A2lphaNumeric*str2ing with 123132 and text");
	alpha_iterator<std::string> it(s.begin(), s.end());
	alpha_iterator<std::string> itEnd(s.end());

	std::copy(it, itEnd, std::ostream_iterator<std::string::value_type>(std::cout));
	std::cout << std::endl;
}