#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	while(cin >> s >> t) {
		int i = 0;
		bool sub = false;
		for(int j = 0; j < t.length(); j++) {
			if (s[i] == t[j]) {
				if (s.length() - 1 == i) {
					sub = true;
					break;
				}
				i++;
			}
		}
		cout << (sub ? "Yes" : "No") << endl;
	}
	
	return 0;
}