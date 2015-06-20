#include<iostream>
using namespace std;
main() {
	char ch;
	int freqletter[200];
	for(ch = 'a';ch <= 'z';ch++) {
		freqletter[ch] = 0;
	} // FOR
	cout << "Enter some lower case letters (Ctrl + Z to End): ";
	while(cin >> ch) {
		freqletter[ch] = freqletter[ch] + 1;
	} // WHILE
	cout << "\n\n\n\t\tLETTER FREQUENCY " << endl << endl;
	int lineCounter = 1;
	for(ch = 'a'; ch <= 'z'; ch++) {
		cout << " " << ch << " = " << freqletter[ch];
		if(lineCounter >= 5){
			cout << endl;
			lineCounter = 0;
		} // IF
		lineCounter++;
	} // FOR
	cout << endl;
	return 0;
} // MAIN
