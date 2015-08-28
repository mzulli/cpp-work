#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Employee {
public:
	ifstream fin;
	string firstName, lastName;
	int id;
	float hours, baseHours, otHours, rate, otRate, grossPay, netPay;
	float taxAmt, taxRate;
	char status;

	// set base and ot hours
	void findHours() {
	    baseHours = hours;
	    otHours = 0;
	        
	    if (baseHours > 40) {
	        otHours = baseHours - 40;
	        baseHours = 40;
	    }
	} // findHours

	// set ot rate
	virtual void findOtRate() {}

	// calculate gross pay
	virtual void findGrossPay() {}

	// calculate tax amount
	void findTaxAmt() {
	    taxAmt = grossPay * taxRate;
	} // findTaxAmt

	// calculate net pay
	void findNetPay() {
	    netPay = grossPay - taxAmt;
	} // findNetPay

	// print table headers
	void printHeader() {
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
	} // printHeader

	// print data for employee
	void printData() {
	    cout	<< setprecision(2)
	    << setiosflags(ios::showpoint | ios::fixed | ios::left)
	    << endl
	    << setw(16) << firstName << setw(16) << lastName
	    << setw(8) << status << setw(6) << id
	    << setw(8) << hours << setw(10) << otHours << setw(10) << rate
	    << setw(10) << otRate << setw(10) << grossPay
	    << setw(10) << taxRate << setw(10) << netPay
	    << endl;
	} // printData

	Employee() {
		fin.open("employees.in");
		taxRate = .3;
	}

	~Employee() {
		fin.close();
	}
};

class Hourly: public Employee {
public:
	// set ot rate
	void findOtRate() {
		otRate = rate * 1.5;
	} // findOtRate
	
	// calculate gross pay
	void findGrossPay() {
		grossPay = (baseHours * rate) + (otHours * otRate);
	} // findGrossPay

	Hourly() {
		// fin.open("hourly.in");
	}

	~Hourly() {
		// fin.close();
	}
};

class Salary: public Employee {
public:
	// set ot rate
	void findOtRate() {
	    otRate = rate / 52 / 40 * 1.5;
	} // findOtRate

	// calculate gross pay
	void findGrossPay() {
	    grossPay = rate / 52 + (otHours * otRate);
	} // findGrossPay

	Salary() {
		// fin.open("salary.in");
	}

	~Salary() {
		// fin.close();
	}
};

int main() {
	Employee *empl = new Employee();
	Employee *fullStaff[6];

	for (int i = 0; i < 6; i++) {
		empl->fin >> empl->firstName >> empl->lastName
			>> empl->status >> empl->id >> empl->hours 
			>> empl->rate;
		empl->findHours();
		empl->findOtRate();
		empl->findGrossPay();
		empl->findTaxAmt();
		empl->findNetPay();
		if (empl->status == 'h' || empl->status == 'H') {
			Hourly hrly;
			empl = &hrly;
		}
		else {
			Salary slry;
			empl = &slry;
		}
		fullStaff[i] = empl;
	}

	// print table header
	empl->printHeader();

/*	// create array of hourly employees
	hourly hrly;
	hourly hEmp[3];

	for (int i = 0; i < 3; i++) {
		hrly.fin >> hEmp[i].firstName >> hEmp[i].lastName >> hEmp[i].status >> hEmp[i].id >> hEmp[i].hours >> hEmp[i].rate;
		hEmp[i].findHours();
		hEmp[i].findOtRate();
		hEmp[i].findGrossPay();
		hEmp[i].findTaxAmt();
		hEmp[i].findNetPay();
	}

	// create array of salary employees
	salary slry;
	salary sEmp[3];

	for (int i = 0; i < 3; i++) {
		slry.fin >> sEmp[i].firstName >> sEmp[i].lastName >> sEmp[i].status >> sEmp[i].id >> sEmp[i].hours >> sEmp[i].rate;
		sEmp[i].findHours();
		sEmp[i].findOtRate();
		sEmp[i].findGrossPay();
		sEmp[i].findTaxAmt();
		sEmp[i].findNetPay();
	}
*/
/*	// fill pointer array with hourly and salary employees
	employee *staff[6];

	for (int i = 0; i < 3; i++) {
		staff[i] = hEmp+i;
	}
	int j = 0;
	for (int i = 3; i < 6; i++) {
		staff[i] = sEmp+j;
		j++;
	}
*/
	// sort pointer array
	for (int i = 0; i < 5; i++) {
		for (int j = 5; j > i; j--) {
			if (fullStaff[j]->netPay < fullStaff[j-1]->netPay) {
				Employee *temp = fullStaff[j];
				fullStaff[j] = fullStaff[j-1];
				fullStaff[j-1] = temp;
			}
		}
	}

	// print pointer array
	for (int i = 0; i < 6; i++) {
		fullStaff[i]->printData();
	}

	// print highest and lowest net
	cout << endl;
	cout << "LOWEST NET : $  " << fullStaff[0]->netPay << " (" << fullStaff[0]->firstName << " " << fullStaff[0]->lastName << ")" << endl;
	cout << "HIGHEST NET: $" << fullStaff[5]->netPay << " (" << fullStaff[5]->firstName << " " << fullStaff[5]->lastName << ")" << endl;
} // MAIN