#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

#define endl '\n'

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeap(int y) {
	if (y % 400 == 0)
		return true;
	if (y % 100 == 0)
		return false;
	if (y % 4 == 0)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, digits[8];
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin, s);
		int i = 0;
		for(int j = 0; j < 10; j++)
			if (s[j] != ' ')
				digits[i++] = s[j] - '0';
		
		sort(digits, digits + 8);
		int ansc = 0, ansd = 99, ansm = 99, ansy = 9999;
		do {
			int d = 10 * digits[0] + digits[1];
			int m = 10 * digits[2] + digits[3];
			int y = 1000 * digits[4] + 100 * digits[5] + 10 * digits[6] + digits[7];
			if (y < 2000)
				continue;
			if (m > 12 || m < 1)
				continue;
			if (d > (days[m] + (isLeap(y) && m == 2)) || d < 1)
				continue;
			ansc++;
			if (y < ansy || y == ansy && m < ansm || y == ansy && m == ansm && d < ansd)
				ansy = y, ansm = m, ansd = d;
		} while (next_permutation(digits, digits + 8));

		cout << ansc;
		if (ansc)
			cout << " " << setw(2) << setfill('0') << ansd << " " << setw(2) << setfill('0') << ansm << " " << ansy;
		cout << endl;
	}

	return 0;
}