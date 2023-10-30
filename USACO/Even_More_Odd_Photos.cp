#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, num;
	cin >> n;
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num % 2 == 0) even++;
		else odd++;
	}

	if (odd > even) {
		int diff = odd - even;
		switch (diff % 3) {
		case 0:
			cout << 2 * even + diff / 3 * 2 << endl;
			break;
		case 1:
			cout << 2 * even + diff / 3 * 2 - 1 << endl;
			break;
		case 2:
			cout << 2 * even + diff / 3 * 2 + 1 << endl;
			break;
		}
	} else if (odd < even) {
		cout << 2 * odd + 1 << endl;
	} else {
		cout << odd + even << endl;
	}

	return 0;
}