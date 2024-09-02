#include<iostream>

using namespace std;

#define endl '\n'

int a, b, row[8], used, n;

void backtrack(int c) {
	if (c == 8) {
		cout << (n < 10 ? " " : "") << n++ << "     ";
		for(const int &r : row)
			cout << " " << r + 1;
		cout << endl;
		return
	}
	for(int i = 0; i < 8; i++) {
		if (used & (1 << i))
			continue;
		if (c == b && i != a)
			continue;
		bool f = true;
		for(int j = 0; j < c && f; j++)
			f = (abs(row[j] - i) != c - j);
		if (!f)
			continue;
		used |= (1 << i);
		row[c] = i;
		backtrack(c + 1);
		used &= ~(1 << i);
	}
}
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, a;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		a--;
		b--;

		cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";

		used = 0;
		n = 1;
		backtrack(0);
		
		if(t)
			cout << endl;
	}

	return 0;
}