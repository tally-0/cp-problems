#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	while(cin >> s && s != "#") {
		next_permutation(s.begin(), s.end());
		bool f = true;
		for(int i = 1; i < s.length() && f; i++)
			f = s[i-1] <= s[i];
		if (f)
			cout << "No Successor" << endl;
		else
			cout << s << endl;
	}

	return 0;
}