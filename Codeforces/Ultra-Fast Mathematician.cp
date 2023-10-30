#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b, c = "";
	cin >> a >> b;

	for(int i = 0; i < a.length(); i++) {
		if (a[i] == b[i]) c += '0';
		else c+= '1';
	}

	cout << c;

	return 0;
}