#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, ans = -1;
	cin >> n;
	n--;
	string a, b;
	cin >> a;
	while(n--) {
		cin >> b;
		if (ans == -1)
			ans = (a < b);
		if (a < b != ans) {
			cout << "NEITHER";
			return 0;
		}
		a = b;
	}

	if (ans)
		cout << "INCREASING";
	else
		cout << "DECREASING";
		

	return 0;
}