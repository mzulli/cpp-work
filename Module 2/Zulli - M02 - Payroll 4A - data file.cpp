#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

main() {
	int id;
	float hours, rate, grosspay, netpay, taxamount, taxrate;
	char status;
	
	ifstream fin("employee2.in");
	
	while(fin >> id >> hours >> rate >> status){
		grosspay = hours * rate;

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
				<< "EMPLOYEE ID:   "	<< setw(12) << id			<< endl
				<< "HOURS WORKED:  "	<< setw(12) << hours		<< endl
				<< "HOURLY RATE:   "	<< setw(12) << rate			<< endl
				<< "GROSS PAY:    $"	<< setw(12) << grosspay		<< endl
				<< "STATUS:        "	<< setw(12) << status		<< endl
				<< "TAX RATE:      "	<< setw(12) << taxrate		<< endl
				<< "TAX AMOUNT:   $"	<< setw(12) << taxamount	<< endl
				<< "NET PAY:      $"	<< setw(12) << netpay		<< endl
				<< endl;
	}//WHILE
	
	fin.close();
	return 0;
}//MAIN
