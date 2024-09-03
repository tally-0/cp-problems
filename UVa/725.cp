#include<iostream>
#include<iomanip>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, first = false;
	while(cin >> n && n) {
		if (first++)
			cout << endl;

		bool sol = false;
		for(int a = 1234; a <= 98765 / n; a++) {
			int b = a * n;
			int f = (a < 10000);
			for(int i = a; i; i /= 10)
				f |= 1 << (i % 10);
			for(int i = b; i; i /= 10)
				f |= 1 << (i % 10);
			if (f != (1 << 10) - 1)
				continue;
			sol = true;

			cout << setw(5) << setfill('0') << b << " / " << setw(5) << setfill('0') << a << " = " << n << endl;
		}

		if (!sol)
			cout << "There are no solutions for " << n << "." << endl;
	}

	return 0;
}