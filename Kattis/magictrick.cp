#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	
	int a[26] = { 0 };
	for(const char& c : s)
		a[c - 'a']++;
	
	int ans = 1;
	for(int i = 0; i < 26 && ans; i++)
		if (a[i] > 1)
			ans = 0;
	cout << ans;

	return 0;
}