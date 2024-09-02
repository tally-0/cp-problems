#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c[6] = { 0 };
	cin >> n;

	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		a--;
		if (c[a] == 0)
			c[a] = i;
		else
			c[a] = -1;
	}
	
	for(int i = 5; i >= 0; i--) {
		if (c[i] > 0) {
			cout << c[i];
			return 0;
		}
	}
	cout << "none";

	return 0;
}