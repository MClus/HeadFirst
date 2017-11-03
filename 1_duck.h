#include <iostream>
using namespace std;

class FlyBehavior {
	public:
		virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
	public:
		void fly() {
			cout << "Fly with wings" << endl;
		}
};

class FlyNoWay : public FlyBehavior {
	public:
		void fly() {
			cout << "Can not fly" << endl;
		}
};

class Duck {
	protected:
		FlyBehavior* flyBehavior;
	public:
		void swim() {
			cout << "I can swim" << endl;
		}
		void fly() {
			flyBehavior->fly();
		}
};
