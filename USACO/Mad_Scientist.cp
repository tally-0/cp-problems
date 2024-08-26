#include<iostream>
#include<fstream>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("breedflip.in");
	ofstream cout("breedflip.out");

	int n;
	string a, b;
	cin >> n >> a >> b;
	
	ll ans = 0;
	bool f = false;
	for(ll i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (!f) {
				ans++;
				f = true;
			}
		} else {
			f = false;
		}
	}
			
	cout << ans;

	return 0;
}