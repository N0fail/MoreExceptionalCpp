#include "task2.h"
#include <cassert> // for assert
#include <iomanip> // for setw
#include <iostream> // for cout
#include <sstream> // for ostringstream
#include <boost/lexical_cast.hpp>

void sprintf_example(int i, char* buff)
{
	sprintf(buff, "%4d", i); // never use
}

void snprintf_example(int i, char* buff, int buflen)
{
	snprintf(buff, buflen, "%4d", i); // use if performance is really critical or for complex formatting
}

void stringstream_example(int i, std::string& s)
{
	std::ostringstream tmp; // need to allocate new memory; simple formatting or wide strings
	tmp << std::setw(4) << i;
	s = tmp.str();
}

void strstream_example(int i, std::string& s) // unsupported 
{
	return;
}

void lexical_cast_example(int i, std::string& s)
{
	s = boost::lexical_cast<std::string>(i); // only for converting 
}

void task2()
{
	char smallBuff[5];
	int value = 11;
	sprintf_example(value, smallBuff);
	assert(value == 11);
	std::cout << smallBuff << std::endl;

	//value = 111111;
	//sprintf_example(value, smallBuff); // stack was corrupted error
	//assert(value == 111111);
	//std::cout << smallBuff << std::endl;

	value = 22;
	snprintf_example(value, smallBuff, 5);
	assert(value == 22);
	std::cout << smallBuff << std::endl;

	value = 222222;
	snprintf_example(value, smallBuff, 5);
	assert(value == 222222);
	std::cout << smallBuff << std::endl;

	std::string s;
	value = 33;
	stringstream_example(value, s);
	assert(value == 33);
	std::cout << s << std::endl;

	value = 333333;
	stringstream_example(value, s);
	assert(value == 333333);
	std::cout << s << std::endl;

	value = 44;
	stringstream_example(value, s);
	assert(value == 44);
	std::cout << s << std::endl;

	value = 444444;
	lexical_cast_example(value, s);
	assert(value == 444444);
	std::cout << s << std::endl;
}