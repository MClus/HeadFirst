#include <iostream>
using namespace std;

class Chef {
	public:
		virtual void cook() = 0;
};

class ChefA : public Chef {
	public:
		void drink() {
			cout << "Drink is ready for you, please." << endl;
		}
		void cook() {
			drink();
		}
};
class ChefB : public Chef {
	public:
		void food() {
			cout << "Food is ready for you, please." << endl;
		}
		void cook() {
			food();
		}
};
class ChefC : public Chef {
	public:
		void wine() {
			cout << "Wine is ready for you, please." << endl;
		}
		void cook() {
			wine();
		}
};

class Command {
	public:
		virtual void execute() = 0;
};

class ACommand : public Command {
	private:
		Chef* chef;
	public:
		ACommand() {
			chef = new ChefA;
		}
		void execute() {
			chef->cook();
		}
};

class BCommand : public Command {
	private:
		Chef* chef;
	public:
		BCommand() {
			chef = new ChefB;
		}
		void execute() {
			chef->cook();
		}
};

class CCommand : public Command {
	private:
		Chef* chef;
	public:
		CCommand() {
			chef = new ChefC;
		};
		void execute() {
			chef->cook();
		}
};

class CommandControl {
	private:
		Command* command;
	public:
		void setCommand(Command* ctr) {
			cout << "A" << endl;
			command = ctr;
			cout << "B" << endl;
		}
		void commandExe() {
			cout << "Prepel for you..." << endl;
			command->execute();
		}
};

int main(int argc, char *argv[])
{
	CommandControl* waiter;

	waiter->setCommand(NULL);
	waiter->commandExe();

	return 0;
}
