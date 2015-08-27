#include<iostream>
using namespace std;
int swap(int [], int, int);
int main() {
	int slot[10] = {8, 3, 1, 5, 7, 10, 4, 9, 6, 2};
	int n = 10;
	int lower, upper, sortflag, sml, scan;
	lower = 0;
	upper = n - 1;
	sortflag = 1;
	while ((lower < upper) && (sortflag == 1)) {
		sml = lower;
		sortflag = 0;
		scan = lower + 1;
		while (scan <= upper - lower) {
			if (slot[scan] > slot[scan + 1]) {
				swap(slot, scan, scan + 1);
				sortflag = 1;
				if (slot[scan] < slot[sml]) sml = scan;
			} // IF
			scan++;		
		} // WHILE
		swap(slot, lower, sml);
		upper--;
		lower++;	
	} // WHILE
	cout << "AFTER SORT:" << endl;
	for (int i = 0; i < n; i++) cout << slot[i] << " ";
	cout << endl;
	return 0;	
} // MAIN

int swap(int slot[], int i, int j) {
	int temp;
	temp = slot[i];
	slot[i] = slot[j];
	slot[j] = temp;
	return 0;
} // SWAP