#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int g;
	string str;
	while(cin >> g >> str) {
		int l = str.length() / g;
		for(int i = 0; i < g; i++)
			for(int j = (i + 1) * l - 1; j >= i * l; j--)
				cout << str[j];
		cout << endl;
	}

	return 0;
}