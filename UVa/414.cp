#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		cin.ignore();
		string s;
		int ssum = 0, ms = 25;
		for(int i = 0; i < n; i++) {
			getline(cin, s);
			int j = 0;
			while(j < 25 && s[j] == 'X')
				j++;
			int l = j;
			while(j < 25 && s[j] != 'X')
				j++;
			ssum += j - l;
			ms = min(ms, j - l);
		}
		cout << ssum - n * ms << endl;
	}

	return 0;
}