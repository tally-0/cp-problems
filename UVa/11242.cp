#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout << setprecision(2);

	int f, r;
	while(cin >> f && f) {
		cin >> r;
		vector<int> a(f);
		for(int &i : a) cin >> i;
		vector<int> b(r);
		for(int &i : b) cin >> i;

		vector<float> d(f*r);
		int k = 0;
		for(int i : a) {
			for(int j : b) d[k++] = (float)j / (float)i;
		}
		sort(d.begin(), d.end());

		float maxs = 0;
		for(int i = 1; i < k; i++) maxs = max(maxs, d[i] / d[i-1]);

		cout << maxs << endl;
	}

	return 0;
}