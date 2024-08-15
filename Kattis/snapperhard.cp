#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, k;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n >> k;
		if (k && !((k + 1) % (1 << n)))
			cout << "Case #" << t << ": ON" << endl;
		else
			cout << "Case #" << t << ": OFF" << endl;
	}

	return 0;
}