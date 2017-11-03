#include <iostream>
#include <string>
using namespace std;

class Pizza {
	private:
		string name;
	public:
		Pizza():name("Unknow Pizz"){}
		void bake () {
			cout << "Bake for 25 minutes at 3:50" << endl;
		}
		void cut() {
			cout << "Cutting the pizza into diagonal slices" << endl;
		}
		void box() {
			cout << "Place pizza in official PizzaStore box" << endl;
		}
		string getName() {
			return name;
		}
		void setName(string nn) {
			name = nn;
		}
};

class NYStylePizza : public Pizza {
	public:
		NYStylePizza() {
			setName("NY Style Pizza");
		}
};

class CCStylePizza : public Pizza {
	public:
		CCStylePizza() {
			setName("CC Style Pizza");
		}
};

class PizzaStore {
	public:
		Pizza* orderPizza(string nn) {
			Pizza* pizza = createPizza(nn);
			pizza->bake();
			pizza->cut();
			pizza->box();
			return pizza;
		}
		virtual Pizza* createPizza(string nn) = 0;
};

class NYPizzaStore : public PizzaStore {
	public:
		Pizza* createPizza(string nn) {
			Pizza* pizza = new NYStylePizza();
			//if (nn == "")
			return pizza;
		}
};

class CCPizzaStore : public PizzaStore {
	public:
		Pizza* createPizza(string nn) {
			Pizza* pizza = new CCStylePizza();
			//if (nn == "")
			return pizza;
		}
};


int main(int argc, char *argv[])
{
	PizzaStore* nystore = new NYPizzaStore();
	PizzaStore* ccstore = new CCPizzaStore();

	Pizza* p1 = nystore->orderPizza("Chese");
	cout << p1->getName() << " is ready." << endl;
	Pizza* p2 = ccstore->orderPizza("Chese");
	cout << p2->getName() << " is ready" << endl;

	return 0;
}
