#include "1_duck.h"
using namespace std;

class MallarDuck : public Duck {
	public:
		MallarDuck() {
			flyBehavior = new FlyWithWings();
		}
};

int main(int argc, char *argv[])
{
	MallarDuck mDuck;
	mDuck.fly();

	return 0;
}
