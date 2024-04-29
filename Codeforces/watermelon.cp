#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w;
	cin >> w;
	cout << (w % 2 || w <= 2 ? "NO" : "YES");

	return 0;
}