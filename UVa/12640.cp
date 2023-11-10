#include<iostream>
#include<sstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	while(getline(cin, str)) {
		stringstream ss(str);
		int ans = 0, s = 0, a;
		while(ss >> a) {
			s += a;
			s = max(s, 0);
			ans = max(s, ans);
		}
		cout << ans << endl;
	}

	return 0;
}