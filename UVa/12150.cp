#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		int start[2001] = { 0 }, c, p, valid = false;
		for(int i = 0; i < n; i++) {
			cin >> c >> p;	
			if (i + p < 0 || i + p >= n)
				valid = false;
			if (valid && start[i + p])
				valid = false;
			if (!valid)
				continue;
			start[i + p] = c;
		}
		if (!valid) {
			cout << -1 << endl;
			continue;
		}
		cout << start[0];
		for(int i = 1; i < n; i++)
			cout << " " << start[i];
		cout << endl;
	}

	return 0;
}