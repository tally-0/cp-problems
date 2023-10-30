#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout << setprecision(4);

	int n, perc = 0, a;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		perc += a;
	}
	cout << (float)perc / (float)n;

	return 0;
}