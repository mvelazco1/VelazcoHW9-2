
#include "analogin.h"

int main(int argc, char* argv[]){

	analogIn AIN0(0); // object init

	cout <<"The AIN0 analog value is being read." <<endl;
	cout <<"Resistance measurement is." << endl;

	int ADCval = AIN0.readADCsample();

	cout << "The ADC value ..." << ADCval << endl;


	float v1 = 1.80;
	float r1 = 1000.0; // wrong vlaue for resistance to get an output
	float v2 = ADCval * (1.80f/4096.0f);

	float I = ( v1 - v2 )/ r1; // ohms law v=i/r
	float r2 = (v2 - 0)/ I;

	if(r2 >= 1000)
	{
		cout.precision(2);
	}
	else 
	{
		cout.precision(4);
	}
	cout << "Resistance is: " << r2 << endl;

	return 0;
}

