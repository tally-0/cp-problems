#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b, c;
	cin >> a;
	c = a;
	for(int i = 1; i < a.length() - 1; i++) {
		for(int j = i + 1; j < a.length(); j++) {
			b = a;
			reverse(b.begin(), b.begin() + i);
			reverse(b.begin() + i, b.begin() + j);
			reverse(b.begin() + j, b.end());
			c = min(c, b);
		}
	}
	cout << c << endl;

	return 0;
}