#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main() {
    const int SIZE = 3; // set array size
    
    // declare arrays
    string firstname[SIZE], lastname[SIZE];
    int id[SIZE];
    float hours[SIZE], base_hours[SIZE], ot_hours[SIZE], rate[SIZE], ot_rate[SIZE], grosspay[SIZE], netpay[SIZE];
    float taxamount[SIZE], taxrate[SIZE];
    char status[SIZE];
    
    // pull data from the input file to the array
    ifstream fin("employee5A.in");
    int n = 0;
    while (fin >> firstname[n] >> lastname[n] >> status[n] >> id[n] >> hours[n] >> rate[n]) n++;
    
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
    
    // compute overtime pay
    int i = 0;
    while (i < n) {
        // set base and ot hours
        if(hours[i] <= 40) {
            base_hours[i] = hours[i];
            ot_hours[i] = 0;
        }
        else {
            base_hours[i] = 40;
            ot_hours[i] = hours[i] - 40;
        }
        
        // set overtime pay
        ot_rate[i] = rate[i] * 1.5;
        
        // calculate gross pay
        grosspay[i] = (base_hours[i] * rate[i]) + (ot_hours[i] * ot_rate[i]);
        
        // calculate tax rate from gross
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
        
        // calculate tax and net pay
        taxamount[i] = grosspay[i] * taxrate[i];
        netpay[i] = grosspay[i] - taxamount[i];
    
        // print employee data
        cout	<< setprecision(2)
        << setiosflags(ios::showpoint | ios::fixed | ios::left)
        << endl
        << setw(16) << firstname[i] << setw(16) << lastname[i]
        << setw(8) << status[i] << setw(6) << id[i]
        << setw(8) << hours[i] << setw(10) << ot_hours[i] << setw(10) << rate[i]
        << setw(10) << ot_rate[i] << setw(10) << grosspay[i]
        << setw(10) << taxrate[i] << setw(10) << netpay[i]
        << endl;
        
        // increment the index number
        i++;
    }//WHILE
    
    return 0;
}//MAIN