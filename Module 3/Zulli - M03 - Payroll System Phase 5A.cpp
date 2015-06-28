#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

main() {
	string firstname, lastname;
	int id;
	float hours, base_hours, ot_hours, rate, ot_rate, grosspay, netpay;
	float taxamount, taxrate;
	char status;
	
	// print table header
	cout 	<< setiosflags(ios::left) 
			<< "                                                  ZULLI PAYROLL" 
			<< endl
			<< setw(16) << "FIRST NAME" << setw(16) << "LAST NAME" 
			<< setw(8) << "STATUS" << setw(6) << "ID" << setw(8) << "HOURS" 
			<< setw(10) << "OT HOURS" << setw(10) << "RATE" 
			<< setw(10) << "OT RATE" << setw(10) << "GROSS" 
			<< setw(10) << "TAX" << setw(10) << "NET"
			<< endl
			<< "=============== =============== ======= ===== ======= "
			<< "========= ========= ========= ========= ========= ========="
			<< endl;
	
	// loop through input file
	ifstream fin("employee5A.in");
	while(fin >> firstname >> lastname >> status >> id >> hours >> rate){
		// set base and ot hours
		if(hours <= 40) {
			base_hours = hours;
			ot_hours = 0;
		}
		else {
			base_hours = 40;
			ot_hours = hours - 40;
		}
		
		// calculate gross pay
		ot_rate = rate * 1.5;
		grosspay = (base_hours * rate) + (ot_hours * ot_rate);

		// calculate tax rate from gross
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

		// adjust tax rate based on status
		if(status == 's' || status == 'S'){
			taxrate += .05;
		}
		else if(status == 'h' || status == 'H'){
			taxrate -= .05;
		}
		if(taxrate < 0) {
			taxrate = 0;
		}

		// calculate tax and net pay
		taxamount = grosspay * taxrate;
		netpay = grosspay - taxamount;
		
		// print employee data
		cout	<< setprecision(2) 
				<< setiosflags(ios::showpoint | ios::fixed | ios::left)
				<< endl
				<< setw(16) << firstname << setw(16) << lastname 
				<< setw(8) << status << setw(6) << id
				<< setw(8) << hours << setw(10) << ot_hours << setw(10) << rate
				<< setw(10) << ot_rate << setw(10) << grosspay 
				<< setw(10) << taxrate << setw(10) << netpay
				<< endl;
	}//WHILE
		
	return 0;
}//MAIN
