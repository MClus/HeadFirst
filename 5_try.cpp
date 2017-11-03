#include <iostream>
using namespace std;

class A {
	private:
		A* ptr;
		static int count;
	public:
		A() {
			count++;
			ptr = this;
		}

		A* getThisPtr() {
			return ptr;
		}
		static int getCount() {
			return count;
		}
};

int A::count = 0;

int main(int argc, char *argv[])
{
	A* a = new A;
	A* b = new A;

	cout << a->getThisPtr() << "\t@\t" << a->getCount() << endl;
	cout << b->getThisPtr() << "\t@\t" << b->getCount() << endl;

	return 0;
}
