#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int c[10] = { 0 };
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= i; j *= 10)
				c[((i / j) % 10)]++;
		for(int i = 0; i < 10; i++)
			cout << (i == 0 ? "" : " ") << c[i];
		cout << endl;
	} 

	return 0;
}