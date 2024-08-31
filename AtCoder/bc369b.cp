#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l[100], r[100];
	cin >> n;
	int ln = 0, rn = 0;
	for(int i = 0, a, s; i < n; i++) {
		cin >> a >> s;
		if (s == 'L')
			l[ln++] = a;
		else
			r[rn++] = a;
	}

	sort(l, l + ln);
	sort(r, r + rn);
	int ans = 0;
	for(int i = 0; i < ln; i++)
		ans += abs(l[i] - l[ln / 2]);
	for(int i = 0; i < rn; i++)
		ans += abs(r[i] - r[rn / 2]);

	return 0;
}