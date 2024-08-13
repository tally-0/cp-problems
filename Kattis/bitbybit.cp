#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string ins;
	int n, reg[32], a, b;
	while(cin >> n && n) {
		memset(reg, -1, sizeof reg);
		for(int i = 0; i < n; i++) {
			cin >> ins >> a;
			if (ins[0] == 'C')
				reg[a] = 0;
			else if (ins[0] == 'S')
				reg[a] = 1;
			else if (ins[0] == 'O') {
				cin >> b;
				if (reg[a] == 1 || reg[b] == 1)
					reg[a] = 1;
				else if (reg[a] == 0 && reg[b] == 0)
					reg[a] = 0;
				else
					reg[a] = -1;
			} else {
				cin >> b;
				if (reg[a] == 1 && reg[b] == 1)
					reg[a] = 1;
				else if (reg[a] == 0 || reg[b] == 0)
					reg[a] = 0;
				else
					reg[a] = -1;
			}
		}
		for(int i = 31; i >= 0; i--)
			if (reg[i] == -1)
				cout << '?';
			else
				cout << reg[i];
		cout << endl;
	}

	return 0;
}