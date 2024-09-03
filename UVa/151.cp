#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		for(int k = 1; ; k++) {
			int s = 0;
			for(int i = 2; i < n; i++)
				s = (s + k) % i;
			if (s == 11) {
				cout << k << endl;
				break;
			}
		}
	}

	return 0;
}
