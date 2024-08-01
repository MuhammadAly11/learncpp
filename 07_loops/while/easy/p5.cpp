#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many numbers: ";
    cin >> n;
    int tmp_n = n;
    cout << "Enter numbers one by one \n"; 
    int odds {0}, evens {0};
    bool is_odd = true;
    int num;
    int cnt {1};

    while (n > 0) {
	cout << "number " << cnt << " ==> ";
	cin >> num;
	if (is_odd) {
	    odds += num;
	    is_odd = false;
	}
	else {
	    evens += num;
	    is_odd = true;
	}
	n--;
	cnt++;
    }

    int odd_avg, even_avg;
    if (tmp_n % 2 != 0)
	odd_avg = odds / ((tmp_n / 2) + 1);
    else
	odd_avg = odds / (tmp_n / 2);

    even_avg = evens / (tmp_n/2);

    cout << "odds avg = " << odd_avg << endl;
    cout << "even avg = " << even_avg << endl;
	
    return 0;
}
