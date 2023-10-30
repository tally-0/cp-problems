#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	while(cin >> n >> k) {
		cout << n + (n - 1) / (k - 1) << endl;
	}	

	return 0;
}