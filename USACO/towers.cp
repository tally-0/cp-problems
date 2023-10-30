#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define vi vector<int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vi towers;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		auto it = upper_bound(towers.begin(), towers.end(), k);
		if (it == towers.end()) towers.push_back(k);
		else *it = k;
	}

	cout << towers.size();

	return 0;
}