#include <iostream>

class One {

public:
	double add(double x) { return x + 0.1; }
};

class Two :public One {

public:
	int add(int x) { return x + 1; }
};
/*
 in class two, we get these two functions.
 int add(double x); //from class one
 int add(int x); //from class two
 so the output of main() are 11 and 1.
*/
int main()
{
	Two obj;
	std::cout << obj.add(10) << " " << obj.add(0.1) << std::endl;
}