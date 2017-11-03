#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Observer {
	public:
		virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject {
	public:
		virtual void registerObserver(Observer* o) = 0;
		virtual void removeObserver(Observer* o) = 0;
		virtual void notifyObservers() = 0;
};

//class DisplayElement {
//	public:
//		virtual void display() = 0;
//};

class WeatherData : public Subject {
	private:
		list<Observer*> observers;
		float temperature;
		float humidity;
		float pressure;
	public:
		WeatherData () {
			observers = list<Observer*>();
			temperature = 0.0;
			humidity = 0.0;
			pressure = 0.0;
		}
		void registerObserver(Observer* o) {
			observers.push_back(o);
		}
		void removeObserver(Observer* o) {
			observers.remove(o);
		}
		void notifyObservers() {
			for (auto it = observers.begin(); it != observers.end(); ++it) {			
				(*it)->update(temperature, humidity, pressure);
			}
		}

		void measurementsChanged() {
			notifyObservers();
		}

		void setMeasurements(float f, float h, float p) {
			temperature = f;
			humidity = h;
			pressure = p;
			measurementsChanged();
		}
};

class CurrentConditionsDisplay : public Observer {
	private:
		float temperature, humidity;
		Subject* weatherData;
	public:
		CurrentConditionsDisplay(Subject* w) {
			weatherData = w;
			weatherData->registerObserver(this);
		}

		void display() {
			cout << "Current conditions: " << temperature << "F degrees and "\
				<< humidity << "% humidity." << endl;
		}

		void update(float t, float h, float p) {
			temperature = t;
			humidity = h;
			display();
		}

		void deRegist() {
			weatherData->removeObserver(this);
		}
};
