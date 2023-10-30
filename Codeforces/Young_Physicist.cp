#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x = 0, y = 0, z = 0, a;
	cin >> n;
	while(n--) {
		cin >> a; x += a;
		cin >> a; y += a;
		cin >> a; z += a;
	}
	if(x+y+z) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}