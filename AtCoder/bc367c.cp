#include<iostream>

using namespace std;

#define endl '\n'

int n, k, r[8], a[8];

void rec(int i, int s) {
	if (i == n) {
		if (s % k == 0) {
			for(int j = 0; j < n; j++)
				cout << a[j] << " ";
			cout << endl;
		}
		return;
	}
	for(int j = 1; j <= r[i]; j++) {
		a[i] = j;
		rec(i + 1, s + j);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> r[i];

	rec(0, 0);

	return 0;
}