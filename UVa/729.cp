#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, h;
	cin >> t;
	while(t--) {
		cin >> n >> h;
		string s = "";
		for(int i = 0; i < n; i++)
			s += (i >= (n - h)) + '0';
		do {
			cout << s << endl;
		} while(next_permutation(s.begin(), s.end()));
		if (t)
			cout << endl;
	}

	return 0;
}