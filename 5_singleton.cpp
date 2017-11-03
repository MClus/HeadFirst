#include <iostream>
#include <string>

using namespace std;

class Singleton {
	private:
		static Singleton* unique;
		Singleton() {
			unique = this;
		}
	public:
		static Singleton* singletonGet() {
			if (unique == NULL) {
				unique = new Singleton;
			}
			return unique;
		}
};

Singleton* Singleton::unique = NULL;

int main(int argc, char *argv[])
{
	Singleton* first = Singleton::singletonGet();

	cout << first << endl;
	Singleton* second = Singleton::singletonGet();
	cout << second << endl;

	return 0;
}
