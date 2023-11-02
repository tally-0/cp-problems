#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mat[26][26], perm[8];
	string s;
	while(cin >> s && s != "#") {
		int n = 0, added = 0;
		memset(mat, 0, sizeof(mat));
		for(int i = 0; i < s.length(); i++) {
			int a = s[i] - 'A';
			if (!(added & (1 << a))) {
				perm[n++] = a;
				added |= (1 << a);
			}
			for(i += 2; i < s.length() && s[i] != ';'; i++) {
				int b = s[i] - 'A';
				mat[a][b] = mat[b][a] = true;
				if (!(added & (1 << b))) {
					perm[n++] = b;
					added |= (1 << b);
				}
			}
		}
		sort(perm, perm + n);

		int ans = 9, ansperm[8];
		do {
			int mb = 0;
			for(int i = 0; i < n - 1 && mb < ans; i++)
				for(int j = i + 1; j < n && mb < ans; j++)
					if (mat[perm[i]][perm[j]])
						mb = max(mb, j - i);
			if (mb < ans) {
				ans = mb;
				for(int i = 0; i < n; i++)
					ansperm[i] = perm[i];
			}
		} while(next_permutation(perm, perm + n));

		for(int i = 0; i < n; i++)
			cout << (char)(ansperm[i] + 'A') << " ";
		cout << "-> " << ans << endl;
	}

	return 0;
}