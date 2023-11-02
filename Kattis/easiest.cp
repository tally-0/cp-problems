#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int sod(int n) {
	int s = 0;
	for(int i = n; i > 0; i /= 10)
		s += i % 10;
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		int t = sod(n), p;
		for(p = 11; sod(p * n) != t; p++);
		cout << p << endl;
	}

	return 0;
}