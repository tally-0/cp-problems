#include<iostream>
#include<map>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string c[12];
	for(string &i : c)
		cin >> i;
	
	bool f = false;
	for(int i = 0; i < 10; i++) {
		for(int j = i + 1; j < 11; j++) {
			for(int k = j + 1; k < 12; k++) {
				int a = 0;
				for(int p = 0; p < 4; p++) {
					if ((c[i][p] == c[j][p] && c[i][p] == c[k][p]) || (c[i][p] != c[j][p] && c[j][p] != c[k][p] && c[i][p] != c[k][p]))
						a++;
				}
				if (a == 4) {
					cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
					f = true;
				}
			}
		}
	}
	if (!f)
		cout << "no sets";

	return 0;
}