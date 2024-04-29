#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	cin >> a;
	string b = "h";
	for(int i = 0; i < 2 * (a.length() - 2); i++)
		b += "e";
	cout << b + "y" << endl;

	return 0;
}