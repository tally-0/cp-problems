#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<ll> v;
	for (int i = 0; i < 32; i++) {
		ll a = pow(2, i);
		for (int j = 0; j < 21; j++) { // 2^31=3^19.5
			v.push_back(a * pow(3, j));
		}
	}
	
	sort(v.begin(), v.end());	

	int m;
	while(cin >> m && m) {
		cout << *lower_bound(v.begin(), v.end(), m) << endl;
	}

	return 0;
}