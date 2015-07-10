#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

// function prototypes
int readdata(string[], string[], char[], int[], float[], float[], int);
void findhours(float[], float[], float[], int);
void findotrate(float[], float[], int);
void findgrosspay(float[], float[], float[], float[], float[], int);
void findtaxrate(float[], float[], char[], int);
void findtaxamt(float[], float[], float[], int);
void findnetpay(float[], float[], float[], int);
float findavgnet(float[], int);
void printdata(string[], string[], char[], int[], float[],  float[], float[], float[], float[], float[], float[], float, int);
void sortnetpay(float[], int);

int main() {
    const int SIZE = 6; // set array size
    
    // declare arrays
    string firstname[SIZE], lastname[SIZE];
    int id[SIZE];
    float hours[SIZE], base_hours[SIZE], ot_hours[SIZE], rate[SIZE], ot_rate[SIZE], grosspay[SIZE], netpay[SIZE];
    float taxamount[SIZE], taxrate[SIZE];
    char status[SIZE];
    
    int n = readdata(firstname, lastname, status, id, hours, rate, SIZE);
    
    // make calculations
    findhours(base_hours, hours, ot_hours, n);
    findotrate(ot_rate, rate, n);
    findgrosspay(grosspay, base_hours, rate, ot_hours, ot_rate, n);
    findtaxrate(grosspay, taxrate, status, n);
    findtaxamt(taxamount, grosspay, taxrate, n);
    findnetpay(netpay, grosspay, taxamount, n);
    
    float avg = findavgnet(netpay, SIZE);
    
    printdata(firstname, lastname, status, id, hours, ot_hours, rate, ot_rate, grosspay, taxrate, netpay, avg, n);
    sortnetpay(netpay, n);
    
    return 0;
} // MAIN

// function definitions:
// pull data from the input file to the array
int readdata(string firstname[], string lastname[], char status[], int id[], float hours[], float rate[], int n) {
    ifstream fin("employees.in");
    n = 0;
    while (fin >> firstname[n] >> lastname[n] >> status[n] >> id[n] >> hours[n] >> rate[n]) n++;
    fin.close();
    return n;
} // readdata

// set base and ot hours
void findhours(float base_hours[], float hours[], float ot_hours[], int n){
    for (int i = 0; i < n; i++) {
        base_hours[i] = hours[i];
        ot_hours[i] = 0;
        
        if (base_hours[i] > 40) {
            ot_hours[i] = base_hours[i] - 40;
            base_hours[i] = 40;
        }
    }
} // findhours

// set ot rate
void findotrate(float ot_rate[], float rate[], int n){
    for (int i = 0; i < n; i++) {
        ot_rate[i] = rate[i] * 1.5;
    }
} // findotrate

// calculate gross pay
void findgrosspay(float grosspay[], float base_hours[], float rate[], float ot_hours[], float ot_rate[], int n){
    for (int i = 0; i < n; i++) {
        grosspay[i] = (base_hours[i] * rate[i]) + (ot_hours[i] * ot_rate[i]);
    }
} // findgrosspay

// calculate tax rate based on gross and status
void findtaxrate(float grosspay[], float taxrate[], char status[], int n){
    for (int i = 0; i < n; i++) {
        if(grosspay[i] > 1000){
            taxrate[i] = .3;
        }
        else if(grosspay[i] > 800){
            taxrate[i] = .2;
        }
        else if(grosspay[i] > 500){
            taxrate[i] = .1;
        }
        else{
            taxrate[i] = 0;
        }
        
        // adjust tax rate based on status
        if(status[i] == 's' || status[i] == 'S'){
            taxrate[i] += .05;
        }
        else if(status[i] == 'h' || status[i] == 'H'){
            taxrate[i] -= .05;
        }
        if(taxrate[i] < 0) {
            taxrate[i] = 0;
        }
    }
} // findtaxrate

// calculate tax amount
void findtaxamt(float taxamount[], float grosspay[], float taxrate[], int n){
    for (int i = 0; i < n; i++){
        taxamount[i] = grosspay[i] * taxrate[i];
    }
} // findtaxamt

// calculate net pay
void findnetpay(float netpay[], float grosspay[], float taxamount[], int n){
    for (int i = 0; i < n; i++) {
        netpay[i] = grosspay[i] - taxamount[i];
    }
} // findnetpay

// calculate average net pay
float findavgnet(float netpay[], int n){
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += netpay[i];
	}
	return sum / n;
}

// print data table
void printdata(string firstname[], string lastname[], char status[], int id[], float hours[],  float ot_hours[], float rate[], float ot_rate[], float grosspay[], float taxrate[], float netpay[], float avg, int n){
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
    
    // print employee data
    for (int i = 0; i < n; i++) {
        cout	<< setprecision(2)
        << setiosflags(ios::showpoint | ios::fixed | ios::left)
        << endl
        << setw(16) << firstname[i] << setw(16) << lastname[i]
        << setw(8) << status[i] << setw(6) << id[i]
        << setw(8) << hours[i] << setw(10) << ot_hours[i] << setw(10) << rate[i]
        << setw(10) << ot_rate[i] << setw(10) << grosspay[i]
        << setw(10) << taxrate[i] << setw(10) << netpay[i]
        << endl;
    }
    
    // print net pay info
    cout	<< endl 
			<< "AVERAGE NET PAY FOR ALL EMPLOYEES: " << avg
			<< endl;
} // printdata

// sort and print net pay
void sortnetpay(float netpay[], int n) {
	// print unsorted
	cout << endl << "NET PAY BEFORE SORTING: " << endl;
	for (int i = 0; i < n; i++) {
		cout << netpay[i] << " ";
	}
	cout << endl;
	
	// sort
	float netpaysorted[n];
	for (int i = 0; i < n; i++) {
		netpaysorted[i] = netpay[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (netpaysorted[j] < netpaysorted[j - 1]) {
				float temp = netpaysorted[j];
				netpaysorted[j] = netpaysorted[j - 1];
				netpaysorted[j - 1] = temp;
			} // end if
		} // end j
	} // end i
	
	// print sorted
	cout << endl << "NET PAY AFTER SORTING: " << endl;
	for (int i = 0; i < n; i++) {
		cout << netpaysorted[i] << " ";
	}
} // sortnetpay
// END
