#include<iostream>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int mask = 0;
	ll app[1024] = { 0 }, ans = 0;
	app[0]++;
	for(const char& c : s) {
		mask ^= (1 << (c - '0'));
		ans += app[mask];
		app[mask]++;
	}
	cout << ans;

	return 0;
}