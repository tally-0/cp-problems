#include<iostream>
#include<algorithm>
#include<cctype>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	while(cin >> r >> c && r + c) {
		string strs[16], s;
		for(int i = 0; i < r; i++) {
			cin >> s;
			for(int j = 0; j < c; j++)
				strs[j] += s[j];
		}

		stable_sort(strs, strs + c, [=](const string& lhs, const string& rhs) {
			for(int i = 0; i < r; i++)
				if (tolower(lhs[i]) < tolower(rhs[i]))
					return true;
				else if (tolower(lhs[i]) > tolower(rhs[i]))
					return false;
			return false;
		});
	
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++)
				cout << strs[j][i];
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}