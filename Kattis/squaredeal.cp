#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

void flip(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r[3][2];
	for(auto &rect : r)
		for(int &dim : rect)
			cin >> dim;
	int p[3];
	for(int i = 0; i < 3; i++) 
		p[i] = i;
	bool ans = false;
	do {
		for(int i = 0; i < (1 << 3) && !ans; i++) {
			for(int j = 0; j < 3; j++)
				if(i & (1 << j))
					flip(r[p[j]][0], r[p[j]][1]);
			if(r[p[0]][0] + r[p[1]][0] + r[p[2]][0] == r[p[0]][1] && r[p[0]][1] == r[p[1]][1] && r[p[0]][1] == r[p[2]][1])
				ans = true;
			if (r[p[0]][0] + r[p[1]][0] == r[p[2]][0] && r[p[2]][0] == r[p[0]][1] + r[p[2]][1] && r[p[1]][1] == r[p[0]][1])
				ans = true;
			for(int j = 0; j < 3; j++)
				if(i & (1 << j))
					flip(r[p[j]][0], r[p[j]][1]);
		}
	} while(next_permutation(p, p + 3) && !ans);

	if (ans)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}