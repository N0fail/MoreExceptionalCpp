#include <iostream>

template<class T>
void f(T x)
{
	std::cout << "void f(T x) " << x << "\n";
}

template<>
void f(int x)
{
	std::cout << "void f(int x) " << x << "\n";
}

void f(int x)
{
	std::cout << "not a template void f(int x) " << x << "\n";
}

template<class T1, class T2>
void f(T1 x, T2 y)
{
	std::cout << "void f(T1 x, T2 y) x=" << x << " y=" << y << "\n";
}

template<class T>
void f(int x, T y)
{
	std::cout << "void f(int x, T y) x=" << x << " y=" << y << "\n";
}

template<>
void f(int x, int y)
{
	std::cout << "void f(int x, int y) x=" << x << " y=" << y << "\n";
}

//template<class T> 
//void f(T x, int y) // ambiguous with void f(int x, T y)
//{
//	std::cout << "void f(T x, int y) " << x << "\n";
//}

template<class T>
class F
{
public:
	F(T x)
	{
		std::cout << "constructor f(T x) " << x << "\n";
	}

	F(int x)
	{
		std::cout << "constructor f(int x) " << x << "\n";
	}
};

//template<class T>
//void g<int>(int x) // not allowed anymore, confusing behaviour
//{
//}

template<class T>
class Gimplementation
{
public:
	static void g(T x)
	{
		std::cout << "static void Gimplementation::g(T x) x =" << x << "\n";
	}
};

template<class T>
void g(T x)
{
	Gimplementation<T>::g(x);
}

void g(int x)
{
	std::cout << "g(int x) x =" << x << "\n";
}

void task7()
{
	f(1);
	f<int>(1);
	f(1.2);
	f(1, 1);
	f(1, 1.2);
	f(1.1, 1.2);
	F<double>(1);
	F<double>(1.2);
	g(1);
	g<int>(1);
	g(1.2);
}