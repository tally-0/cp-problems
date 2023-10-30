#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a;
	
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '.') b += '0';
		else {
			if (a[++i] == '.') b += '1';
			else b += '2';
		}
	}
	cout << b;

	return 0;
}