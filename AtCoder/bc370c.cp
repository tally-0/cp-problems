#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t, x[101];
	int n = 0, m = s.length(), i = 0;
	while(i < m) {
		while(i < m && s[i] <= t[i])
			i++;
		if (i < m) {
			s[i] = t[i];
			x[n++] = s;
		}
	}
	for(i--; i >= 0; i--) {
		if (s[i] != t[i]) {
			s[i] = t[i];
			x[n++] = s;
		}
	}

	cout << n << endl;
	for(i = 0; i < n; i++)
		cout << x[i] << endl;

	return 0;
}