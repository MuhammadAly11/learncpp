#include <iostream>
using namespace std;

int main() {
	// read array
	int n;
	cout << "n: ";
	cin >> n;
	int arr[n];
	cout << "numbers 1 by 1 (between 0 and 200): ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// read queries and find numbers
	int q;
	cout << "+ve q: ";
	cin >> q;
	cout << "numbers for queries 1 by 1: ";
	while (q) {
		int query;
		cin >> query;
		int pos = -1;
		for (int i = 0; i < n; i++) {
			if (query == arr[i]) {
				pos = i;
			}
		}
		cout << query << " last position is: " << pos << endl;
		q--;
	}
}

// doing this problem without nested loops would reqiure an array to store queries
// and I couldn't figure out what size should I make that array
