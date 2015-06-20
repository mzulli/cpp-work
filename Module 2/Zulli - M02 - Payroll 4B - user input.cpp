#include<iostream>
#include<iomanip>
using namespace std;

main() {
	int id, counter;
	float hours, base_hours, ot_hours, rate, ot_rate, grosspay, netpay, taxamount, taxrate;
	char status;
	
	cout << "HOW MANY EMPLOYEES DO YOU WANT TO ENTER? ";
	cin >> counter;
	cout << endl;
	
	while(counter > 0){
		cout << "ENTER EMPLOYEE ID (LAST 4 DIGITS OF SS#): ";
		cin >> id;
		
		cout << "ENTER HOURS WORKED: ";
		cin >> hours;
		if(hours <= 40) {
			base_hours = hours;
			ot_hours = 0;
		}
		else {
			base_hours = 40;
			ot_hours = hours - 40;
		}
		
		cout << "ENTER HOURLY RATE: ";
		cin >> rate;
		ot_rate = rate *1.5;

		cout << "ENTER STATUS -- S for Single, M for Married, H for Head of Household: ";
		cin >> status;
		
		if((status != 's') && (status != 'S') && (status != 'm') && (status != 'M') && (status != 'h') && (status != 'H')){
			cout << "INVALID - ENTER STATUS: ";
			cin >> status;
		}

		grosspay = (base_hours * rate) + (ot_hours * ot_rate);

		if(grosspay < 0){
			cout << "ERROR!" << endl;
		}

		else{
			if(grosspay > 1000){
				taxrate = .3;
			}

			else if(grosspay > 800){
				taxrate = .2;
			}

			else if(grosspay > 500){
				taxrate = .1;
			}

			else{
				taxrate = 0;
			}
		}

		if(status == 's' || status == 'S'){
			taxrate += .05;
		}

		else if(status == 'h' || status == 'H'){
			taxrate -= .05;
		}

		if(taxrate < 0) {
			taxrate = 0;
		}

		taxamount = grosspay * taxrate;
		netpay = grosspay - taxamount;
		
		cout	<< setprecision(2)
			<< setiosflags(ios::showpoint | ios::fixed | ios::right)
			<< endl
			<< "EMPLOYEE ID:         " << setw(12) << id		<< endl
			<< "TOTAL HOURS WORKED:  " << setw(12) << hours		<< endl
			<< "OT HOURS:            " << setw(12) << ot_hours	<< endl
			<< "BASE RATE:          $" << setw(12) << rate		<< endl
			<< "OT RATE:            $" << setw(12) << ot_rate	<< endl
			<< "GROSS PAY:          $" << setw(12) << grosspay	<< endl
			<< "STATUS:              " << setw(12) << status	<< endl
			<< "TAX RATE:            " << setw(12) << taxrate	<< endl
			<< "TAX AMOUNT:         $" << setw(12) << taxamount	<< endl
			<< "NET PAY:            $" << setw(12) << netpay	<< endl
			<< endl;

		counter--;
	}//WHILE
		
	return 0;
}//MAIN
