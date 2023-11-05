#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	int n;
	cin >> n;

	int first[8] = { 0 }, prefix = 0, ans = 0;
	for(int i = 1, a; i <= n; i++) {
		cin >> a;
		prefix += a;
		prefix %= 7;
		if (!first[prefix])
			first[prefix] = i;
		else
			ans = max(ans, i - first[prefix]);
	}

	cout << ans << endl;

	return 0;
}