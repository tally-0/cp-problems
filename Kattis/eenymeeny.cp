#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);
	int m = 1, n;
	for(int i = 0; i < s.length(); i++)
		if (s[i] == ' ')
			m++;
	cin >> n;
	string k[100];
	for(int i = 0; i < n; i++)
		cin >> k[i];
	string t[2][50];
	int n1 = 0, n2 = 0;
	int p = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			do {
				p++;
				if (p >= n)
					p = 0;
			} while(k[p] == "");
		}
		if (i % 2)
			t[1][n2++] = k[p];
		else
			t[0][n1++] = k[p];
		k[p] = "";
	}
	cout << n1 << endl;
	for(int i = 0; i < n1; i++)
		cout << t[0][i] << endl;
	cout << n2 << endl;
	for(int i = 0; i < n2; i++)
		cout << t[1][i] << endl;

	return 0;
}