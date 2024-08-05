#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int booked[100] = { 0 }, r, n;
	cin >> r >> n;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		booked[a] = true;
	}
	for(int i = 0; i < r; i++) {
		if (!booked[i]) {
			cout << i;
			return 0;
		}
	}
	cout << "too late";

	return 0;
}