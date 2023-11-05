#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

    int n, q, l, r;
    cin >> n >> q;
    int p[3][100001];
    p[0][0] = p[1][0] = p[2][0] = 0;
    for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 3; j++)
			p[j][i] = p[j][i - 1];
        cin >> l;
        --l;
		p[l][i]++;
    }
    while(q--) {
        cin >> l >> r;
        for(int j = 0; j < 3; ++j) {
            cout << p[j][r] - p[j][l-1];
            if(j != 2)
				cout << " ";
        }
        cout << endl;
    }
}