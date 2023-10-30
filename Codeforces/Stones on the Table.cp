#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int count = 0;
	for(int i = 1; i < n; i++) {
		if (s[i - 1] == s[i]) count ++;
	}

	cout << count;

	return 0;
}