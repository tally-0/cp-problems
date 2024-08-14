#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, code[1000] = { 0 };
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0, a; j < n; j++) {
			cin >> a;
			code[i] |= a;
		}
	}
	for(int i = 0; i < n; i++)
		cout << code[i] << " ";	

	return 0;
}