#include <iostream>
 using namespace std;

 class CaffeineBeverage {
	 public:
		 void prepareRecipe() {
			 boilWater();
			 brew();
			 pourInCup();
			 addCondiments();
		 }
		 void boilWater() {
			 cout << "Boiling water for beverage..." << endl;
		 }
		 void pourInCup() {
			 cout << "Pouring in cup..." << endl;
		 }
		 virtual void brew() = 0;
		 virtual void addCondiments() = 0;
 };

class Tea : public CaffeineBeverage {
	void brew() {
		cout << "Steeping the tea..." << endl;
	}
	void addCondiments() {
		cout << "Adding Lemon..." << endl;
	}
};

class Coffee : public CaffeineBeverage {
	void brew() {
		cout << "Steeping coffee through filter..." << endl;
	}
	void addCondiments() {
		cout << "Adding Sugar and Milk..." << endl;
	}
};


int main(int argc, char *argv[])
{
	CaffeineBeverage* tea = new Tea;
	CaffeineBeverage* coffee = new Coffee;

	tea->prepareRecipe();
	coffee->prepareRecipe();

	return 0;
}
