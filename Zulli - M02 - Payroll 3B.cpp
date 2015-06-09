#include<iostream>
#include<fstream>
using namespace std;

main() {
	int id;
	float hours, rate, grosspay, netpay, taxamount;
	float const TAXRATE = .10;
	
	ifstream fin("employee.in");
	
	while(fin >> id >> hours >> rate){
		grosspay = hours * rate;
		taxamount = grosspay * TAXRATE;
		netpay = grosspay - taxamount;
		
		cout << "EMPLOYEE ID: " << id << endl;
		cout << "HOURS WORKED: " << hours << endl;
		cout << "HOURLY RATE: " << rate << endl;
		cout << "GROSS PAY: $" << grosspay << endl;
		cout << "TAX RATE: " << TAXRATE << endl;
		cout << "TAX AMOUNT: $" << taxamount << endl;
		cout << "NET PAY: $" << netpay << endl;
		cout << endl;
	}//WHILE
		
	return 0;
}//MAIN
