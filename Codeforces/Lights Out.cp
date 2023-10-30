#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

void flip (char &c) {
	if (c == '1') c = '0';
	else c = '1';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<string> u(3);
	for(auto &s : u) s = "111";

	int a;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			cin >> a;
			if (a % 2) {
				flip(u[j][i]);
				if (i > 0) flip(u[j][i-1]);
				if (i < 2) flip(u[j][i+1]);
				if (j > 0) flip(u[j-1][i]);
				if (j < 2) flip(u[j+1][i]);
			}
		}
	}

	for(auto s : u) cout << s << endl;

	return 0;
}