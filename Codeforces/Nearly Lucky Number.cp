#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	cin >> n;

	int ld = 0;
	for(int i = 0; i < n.size(); i++) {
		if (n[i] == '4' || n[i] == '7') {
			ld++;
		}
	}

	if (ld == 4 || ld == 7) cout << "YES";
	else cout << "NO";

	return 0;
}