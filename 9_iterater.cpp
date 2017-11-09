#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

typedef int Object;


class Iterator {
	public:
		virtual bool hasNext() = 0;
		virtual Object next() = 0;
};

class ZhListIterator : public Iterator {
	private:
		list<Object> objectlist;
		list<Object>::iterator pos;
	public:
		ZhListIterator(list<Object> obj) {
			objectlist = obj;
			pos = objectlist.begin();
		}

		bool hasNext() {
			if (pos == objectlist.end())
				return false;
			else
				return true;
		}
		
		Object next() {
			Object temp = *pos;
			pos++;
			return temp;
		}
};

class ZhList {
	private:
		list<Object> data;
	public:
		void listAdd(Object d) {
			data.push_front(d);
		}
		Iterator* createIterator() {
			return new ZhListIterator(data);
		}
};

class ZhVectorIterator : public Iterator {
	private:
		vector<Object> objvector;
		size_t pos;
	public:
		ZhVectorIterator(vector<Object> obj) {
			objvector = obj;
			pos = 0;
		}

		bool hasNext() {
			if (pos < objvector.size())
				return true;
			else
				return false;
		}
		Object next() {
			Object temp = objvector[pos];
			pos++;
			return temp;
		}
};

class ZhVector {
	private:
		vector<Object> data;
	public:
		void vectorAdd(Object d) {
			data.push_back(d);
		}
		Iterator* createIterator() {
			return new ZhVectorIterator(data);
		}
};

int main(int argc, char *argv[])
{
	ZhList ld;
	ZhVector lv;
	ld.listAdd(1);
	ld.listAdd(2);
	ld.listAdd(3);
	lv.vectorAdd(4);
	lv.vectorAdd(5);

	Iterator* ild = ld.createIterator();
	Iterator* ilv = lv.createIterator();

	while (ild->hasNext()) {
		cout << ild->next() << endl;
	}	

	while (ilv->hasNext()) {
		cout << ilv->next() << endl;
	}

	return 0;
}
