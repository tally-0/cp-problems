#include<iostream>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("circlecross.in");
	ofstream cout("circlecross.out");

	string str;
	cin >> str;

	int n = str.length(), f[26] = { 0 }, s[26] = { 0 };
	for(int i = 0; i < n; i++)
		if (f[str[i] - 'A'] != 0)
			s[str[i] - 'A'] = i + 1;
		else
			f[str[i] - 'A'] = i + 1;

	int ans = 0;
	for(int i = 0; i < 26; i++)
		for(int j = i + 1; j < 26; j++)
			if (f[i] < f[j] && f[j] < s[i] && s[i] < s[j] || f[j] < f[i] && f[i] < s[j] && s[j] < s[i])
				ans++;

	cout << ans;

	return 0;
}