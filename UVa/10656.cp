#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		int s = 0;
		for(int i = 0, a; i < n; i++) {
			cin >> a;
			if (a)
				cout << (s ? " " : "") << a;
			s += a;
		}
		if (!s)
			cout << "0";
		cout << endl;
	}

	return 0;
}