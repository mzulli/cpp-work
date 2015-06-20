#include<iostream>
using namespace std;
main(){
	int id;
	float hours, rate, grosspay;
	
	cout << "ENTER EMPLOYEE ID: ";
	cin >> id;
	
	cout << "ENTER HOURS WORKED: ";
	cin >> hours;
	
	cout << "ENTER HOURLY RATE: ";
	cin >> rate;
	
	grosspay = hours * rate;
	
	cout << endl;
	cout << "EMPLOYEE ID: " << id << endl;
	cout << "HOURS WORKED: " << hours << endl;
	cout << "HOURLY RATE: " << rate << endl;
	cout << "GROSS PAY: $" << grosspay << endl;
	
	return 0;
}//MAIN
