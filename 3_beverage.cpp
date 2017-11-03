#include "3_beverage.h"
using namespace std;

int main() 
{
	Beverage* beverage = new Espresso();
	std::cout << beverage->getDescription() << "\t$" << beverage->cost() << std::endl;
	
	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);

	cout << beverage2->getDescription() << "\t$" << beverage2->cost() << endl;

	return 0;
}
