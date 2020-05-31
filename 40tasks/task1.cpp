#include "task1.h"
#include <vector>
#include <cassert>
#include <iostream>
#include <iterator>

void task1_wrong()
{
	std::vector<int> v;

	v.reserve(2); // reserves memory for at least 2 elements
	// assert(v.capacity() == 2); // WRONG: checks if reserved memory == 2, likely throw error
	assert(v.capacity() >= 2); // CORRECT: should be instead


	
	// v[0] = 1; // WRONG: variable locations is undefined, might throw an error
	// v.at(0); // will throw an error

	for (std::vector<int>::iterator i = v.begin(); i < v.end(); ++i) // no iterations, because no elements were put
	{
		std::cout << *i << std::endl;
	}
}

void task1_correct()
{
	std::vector<int> v;
	v.resize(2); // puts 2 elements in container
	v[0] = 1; // CORRECT
	v.at(0); // no error
	v[1] = 2;
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) // iterates fine, because resize; != works with all iterator types, < only with free access iterators
	{
		std::cout << *i << "\n"; // "\n" is better, then std::endl for better performance 
	}

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n")); // Pog
}
