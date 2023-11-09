#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d;
	while(cin >> d) {
		for(int i = 0; i <= 9999; i++) {
			int c = i * i;
			if (c >= (int)pow(10.0, d))
				break;
			int a = c / (int)pow(10.0, d / 2);
			int b = c % (int)pow(10.0, d / 2);
			if ((a + b) * (a + b) == c)
				cout << setw(d) << setfill('0') << c << endl;
		}
	}

	return 0;
}