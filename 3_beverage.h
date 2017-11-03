#include <iostream>
#include <string>
using std::string;

class Beverage {
	protected:
		string description;
	public:
		virtual string getDescription() {
			return description;
		}

		virtual double cost() = 0;
};

class CondimentDecorator : public Beverage {
	public:
		virtual string getDescription() = 0;
};

class Espresso : public Beverage {
	public:
		Espresso() {
			description = "Espresso";
		}

		double cost() {
			return 1.97;
		}
};
class HouseBlend : public Beverage {
	public:
		HouseBlend() {
			description = "HouseBlend";
		}
		double cost() {
			return 0.89;
		}
};
class DarkRoast : public Beverage {
	public:
		DarkRoast() {
			description = "DarkRoast";
		}
		double cost() {
			return 0.99;
		}
};
class Decaf : public Beverage {
	public:
		Decaf() {
			description = "Decaf";
		}
		double cost() {
			return 0.78;
		}
};

class Milk : public CondimentDecorator {
	private:
		Beverage* bevptr;
	public:
		Milk(Beverage* bev) {
			bevptr = bev;
		}
		string getDescription() {
			return bevptr->getDescription().append(", Milk");
		}
		double cost() {
			return 0.2 + bevptr->cost();
		}
};
class Mocha : public CondimentDecorator {
	private:
		Beverage* bevptr;
	public:
		Mocha(Beverage* bev) {
			bevptr = bev;
		}
		string getDescription() {
			return bevptr->getDescription().append(", Mocha");
		}
		double cost() {
			return 0.3 + bevptr->cost();
		}
};
class Soy : public CondimentDecorator {
	private:
		Beverage* bevptr;
	public:
		Soy(Beverage* bev) {
			bevptr = bev;
		}
		string getDescription() {
			return bevptr->getDescription().append(", Soy");
		}
		double cost() {
			return 0.5 + bevptr->cost();
		}
};
class Whip : public CondimentDecorator {
	private:
		Beverage* bevptr;
	public:
		Whip(Beverage* bev) {
			bevptr = bev;
		}
		string getDescription() {
			return bevptr->getDescription().append(", Whip");
		};
		double cost() {
			return 0.4 + bevptr->cost();
		}
};
