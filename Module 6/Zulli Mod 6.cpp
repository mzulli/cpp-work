#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class employee {
	ifstream fin;
	string firstname, lastname;
	int id;
	float hours, base_hours, ot_hours, rate, ot_rate, grosspay, netpay;
	float taxamount, taxrate;
	char status;

	// set base and ot hours
	void findhours() {
	    base_hours = hours;
	    ot_hours = 0;
	        
	    if (base_hours > 40) {
	        ot_hours = base_hours - 40;
	        base_hours = 40;
	    }
	} // findhours

	// set ot rate
	void findotrate() {
	    ot_rate = rate * 1.5;
	} // findotrate

	// calculate gross pay
	void findgrosspay() {
	    grosspay = (base_hours * rate) + (ot_hours * ot_rate);
	} // findgrosspay

	// calculate tax amount
	void findtaxamt() {
	    taxamount = grosspay * taxrate;
	} // findtaxamt

	// calculate net pay
	void findnetpay() {
	    netpay = grosspay - taxamount;
	} // findnetpay

	// print table headers
	void printheader() {
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
	} // printheader

	// print data for employee
	void printdata() {
	    cout	<< setprecision(2)
	    << setiosflags(ios::showpoint | ios::fixed | ios::left)
	    << endl
	    << setw(16) << firstname << setw(16) << lastname
	    << setw(8) << status << setw(6) << id
	    << setw(8) << hours << setw(10) << ot_hours << setw(10) << rate
	    << setw(10) << ot_rate << setw(10) << grosspay
	    << setw(10) << taxrate << setw(10) << netpay
	    << endl;
	} // printdata

public:
	employee() {
		taxrate = .3;
	}

	~employee() {
	}

	// print employee pay report
	void printreport() {
		int i = 0;
		printheader();
		while(fin >> firstname >> lastname >> status >> id >> hours >> rate){
			findhours();
			findotrate();
			findgrosspay();
			findtaxamt();
			findgrosspay();
			printdata();
			i++;
		}
	}
};

class hourly: public employee {
public:
	hourly() {
		fin.open("hourly.in");
	}

	~hourly() {
		fin.close();
	}
};

class salary: public employee {
	// set ot rate
	void findotrate() {
	    ot_rate = rate / 52 / 40 * 1.5;
	} // findotrate

	// calculate gross pay
	void findgrosspay() {
	    grosspay = rate / 52 + (ot_hours * ot_rate);
	} // findgrosspay

public:
	salary() {
		fin.open("salary.in");
	}

	~salary() {
		fin.close();
	}
};

int main() {
	employee staff[6];
    employee.printreport();
} // MAIN
