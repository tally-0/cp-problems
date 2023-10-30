#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, max = 0, maxi = -1, min = 101, mini = -1, a;
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> a;
		if (a > max) {
			max = a;
			maxi = i;
		}
		if (a <= min) {
			min = a;
			mini = i;
		}
	}

	cout << (n - mini) + (maxi - 1) - (mini < maxi ? 1 : 0);

	return 0;
}