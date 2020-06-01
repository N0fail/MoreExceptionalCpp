#include "task5.h"

#include <iostream>

class car
{
public:
	void go_to_start(double x = 0,double y = 0){}
};

class helicopter
{
public:
	void go_to_start(double x = 0, double y = 0, double z = 0){}
};

template<class T>
void move_transport_to_start(T& t)
{
	t.go_to_start(); // works without inheritance
}


void task5()
{
	car c;
	helicopter h;
	move_transport_to_start(c);
	move_transport_to_start(h);

}