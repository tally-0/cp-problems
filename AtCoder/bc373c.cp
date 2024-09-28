#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int a = -1000000001, b = -1000000001;
	for(int i = 0, c; i < n; i++) {
		cin >> c;
		a = max(a, c);
	}
	for(int i = 0, c; i < n; i++) {
		cin >> c;
		b = max(b, c);
	}

	cout << (a + b);
	

	return 0;
}