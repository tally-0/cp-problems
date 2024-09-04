#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cout << "PERFECTION OUTPUT" << endl;
	while(cin >> n && n) {
		int s = 1;
		for(int m = 2; m <= sqrt(n); m++)
            if (!(n % m))
                s += m + (n / m);

		cout << setw(5) << n << "  ";
		if (s == n || n == 1)
			cout << "PERFECT" << endl;
		else if (s < n)
			cout << "DEFICIENT" << endl;
		else
			cout << "ABUNDANT" << endl;
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}