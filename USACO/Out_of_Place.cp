#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("outofplace.in");
	ofstream cout("outofplace.out");

	int n, o[100];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> o[i];

	int s[100];
	memcpy(s, o, n * sizeof(int));
	sort(s, s + n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		if (o[i] != s[i])
			ans++;

	cout << ans - 1;

	return 0;
}