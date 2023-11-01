#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
typedef long long int ll;

string s;
ll ans = 0, ways;
int vows = 1065233;

void solve(int i) {
	if (i == s.length()) {
		int f = false, a = 0, b = 0;
		for(const char &c : s) {
			if (c == 'L')
				f = true;
			if (vows & (1 << ( c - 'A'))) {
				a++;
				b = 0;
			} else {
				b++;
				a = 0;
			}
			if (a >= 3 || b >= 3) {
				f = false;
				break;
			}
		}
    	ans += f * ways;
		return;
	}

    if (s[i] != '_')
		solve(i + 1);
    else {
        s[i] = 'L';
        solve(i + 1);
        s[i] = 'B';
        ways *= 20;
        solve(i + 1);
        ways /= 20;
        s[i] = 'A';
        ways *= 5;
        solve(i + 1);
        ways /= 5;
        s[i] = '_';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    ways = 1;
    solve(0);
    cout << ans;

    return 0;
}