#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, max = -1, cur = 0, a, b;
	cin >> n;
	
	while(n--) {
		cin >> a >> b;
		cur += b-a;
		if (cur > max) max = cur;
	}

	cout << max;

	return 0;
}