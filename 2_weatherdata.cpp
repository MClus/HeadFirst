#include "2_weatherdata.h"
using namespace std;

int main(int argc, char *argv[])
{
	WeatherData* wdptr = new WeatherData();
	
	CurrentConditionsDisplay* ccd = new CurrentConditionsDisplay(wdptr);

	wdptr->setMeasurements(10.0, 20.0, 30.0);
	CurrentConditionsDisplay* ccp = new CurrentConditionsDisplay(wdptr);
	wdptr->setMeasurements(15.0, 25.5, 26.2);
	ccd->deRegist();
	wdptr->setMeasurements(11.5, 12.3, 24.5);

	return 0;
}
