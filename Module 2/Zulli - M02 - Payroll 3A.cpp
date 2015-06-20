#include<iostream>
using namespace std;

main() {
	int id, counter;
	float hours, rate, grosspay, netpay, taxamount;
	float const TAXRATE = .10;
	
	cout << "HOW MANY EMPLOYEES DO YOU WANT TO ENTER? ";
	cin >> counter;
	cout << endl;
	
	while(counter > 0){
		cout << "ENTER EMPLOYEE ID (LAST 4 DIGITS OF SS#): ";
		cin >> id;
		
		cout << "ENTER HOURS WORKED: ";
		cin >> hours;
		
		cout << "ENTER HOURLY RATE: ";
		cin >> rate;
		
		grosspay = hours * rate;
		taxamount = grosspay * TAXRATE;
		netpay = grosspay - taxamount;
		
		cout << endl;
		cout << "EMPLOYEE ID: " << id << endl;
		cout << "HOURS WORKED: " << hours << endl;
		cout << "HOURLY RATE: " << rate << endl;
		cout << "GROSS PAY: $" << grosspay << endl;
		cout << "TAX RATE: " << TAXRATE << endl;
		cout << "TAX AMOUNT: $" << taxamount << endl;
		cout << "NET PAY: $" << netpay << endl;
		cout << endl;
	
		counter--;
	}//WHILE
		
	return 0;
}//MAIN
