#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;
 
#define endl '\n'
typedef long long ll;
 
int n, m;
ll mat[10][100];
ll par[10][100], mem[10][100];
 
ll dp(int c, int r) {
    if (c == m)
        return 0;
    if (mem[r][c] != -1)
        return mem[r][c];
    int rs[3];
    for(int i = -1; i < 2; i++)
        rs[i + 1] = (r + i + n) % n;
    sort(rs, rs + 3);
    mem[r][c] = LLONG_MAX;
    for(int nr : rs) {
        ll a = dp(c + 1, nr);
        if (a < mem[r][c]) {
            mem[r][c] = a;
            par[r][c] = nr;
        }
    }
    mem[r][c] += mat[r][c];
    return mem[r][c];
}
 
 
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    while(cin >> n >> m){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];

        memset(mem, -1, sizeof(mem));
        ll ans = LLONG_MAX;
        int ansi;
        for(int i = 0; i < n; i++){
            ll d = dp(0, i);
            if (d < ans) {
                ans = d;
                ansi = i;
            }
        }

        for(int i = 0; i < m - 1; i++) {
            cout << ansi + 1 << " ";
            ansi = par[ansi][i];
        }
        cout << ansi + 1 << endl << ans <<endl;
    }
    
    return 0;
}
