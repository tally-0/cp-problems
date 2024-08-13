#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, age[10];
	for(int t = 1; t <= T; t++) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> age[i];
		cout << "Case " << t << ": " << age[n / 2] << endl;
	}

	return 0;
}