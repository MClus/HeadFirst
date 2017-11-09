#include <iostream>
using namespace std;

class State {
	public:
		virtual void insertQuarter() = 0;
		virtual void edectQuarter() = 0;
		virtual void turnCrank() = 0;
		virtual void dispense() = 0;
};
class GumballMachine {
	private:
		State* soldOut, noQuarter, hasQuarter, sold;
		state* state;
		int count;
	public:
		GumballMachine(int num) {
			soldOut = new SoldOutState(this);
			noQuarter = new NoQuarterState(this);
			hasQuarter = new HasQuarterState(this);
			sold = new SoldState(this);
			count = num;
			if (count > 0)
				state = noQuarter;
		}
		~GumballMachine() {
			delete soldOut;
			delete noQuarter;
			delete hasQuarter;
			delete sold;
			state = NULL;
		}

		void insertQuarter() { state->insertQuarter(); }
		void ejectQuarter() { state->ejectQuarter(); }
		void turnCrank() { state->turnCrank(); }
		void setState(State* s) { state = s}
		void releaseBall() {
			cout << "A gumball comes rolling out the solt..." << endl;
			if (count != 0) count--;
		}
};

class NoQuarterState : public State {
	private:
		GumballMachine* gm;
	public:
		NoQuarterState(Gumballmachine* g) { gm = g; }
		void insertQuarter() {
			cout << "You inserted a quarter..." << endl;
			gm->setState(gm->getHasQuarterState());
		}
		void ejectQuarter() {
			cout << "You haven't inserted a quarter" << endl;
		}
		void turnCrank() {
			cout << "You turned, but there's no quarter" << endl;
		}
		void dispense() {
			cout << "You need to pay first" << endl;
		}
};


class HasQuarterState : public State {
	private:
		GumballMachine* gm;
	public:
		HasQuarterState(Gumballmachine* g) { gm = g; }
		void insertQuarter() {
			cout << "You have inserted a quarter, please waiting" << endl;
		}
		void ejectQuarter() {
			gm->setState(gm->getNoQuarterState());
			cout << "You haven't inserted a quarter" << endl;
		}
		void turnCrank() {
			cout << "You turned, but there's no quarter" << endl;
		}
		void dispense() {
			cout << "You need to pay first" << endl;
		}
};


class SoldState : public State {
	public:
		void insertQuarter()
class NoQuarterState : public State {
	private:
		GumballMachine* gm;
	public:
		NoQuarterState(Gumballmachine* g) { gm = g; }
		void insertQuarter() {
			cout << "You inserted a quarter..." << endl;
			gm->setState(gm->getHasQuarterState());
		}
		void ejectQuarter() {
			cout << "You haven't inserted a quarter" << endl;
		}
		void turnCrank() {
			cout << "You turned, but there's no quarter" << endl;
		}
		void dispense() {
			cout << "You need to pay first" << endl;
		}
};


class SoldState : public State {
	public:
		void insertQuarter()
class NoQuarterState : public State {
	private:
		GumballMachine* gm;
	public:
		NoQuarterState(Gumballmachine* g) { gm = g; }
		void insertQuarter() {
			cout << "You inserted a quarter..." << endl;
			gm->setState(gm->getHasQuarterState());
		}
		void ejectQuarter() {
			cout << "You haven't inserted a quarter" << endl;
		}
		void turnCrank() {
			cout << "You turned, but there's no quarter" << endl;
		}
		void dispense() {
			cout << "You need to pay first" << endl;
		}
};


class SoldState : public State {
	public:
		void insertQuarter()
class NoQuarterState : public State {
	private:
		GumballMachine* gm;
	public:
		NoQuarterState(Gumballmachine* g) { gm = g; }
		void insertQuarter() {
			cout << "You inserted a quarter..." << endl;
			gm->setState(gm->getHasQuarterState());
		}
		void ejectQuarter() {
			cout << "You haven't inserted a quarter" << endl;
		}
		void turnCrank() {
			cout << "You turned, but there's no quarter" << endl;
		}
		void dispense() {
			cout << "You need to pay first" << endl;
		}
};


class SoldState : public State {
	public:
		void insertQuarter()
class SoldState : public State {
	public:
		void insertQuarter()
