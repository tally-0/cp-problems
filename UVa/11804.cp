#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
#define fi first
#define se second
typedef pair<string,pair<int,int>> sii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    sii p[10];
    for(int tc = 1; tc <= t; tc++) {
        for(sii &i : p)
            cin >> i.fi >> i.se.fi >> i.se.se;

        sort(p, p + 10, [](const sii &lhs, const sii &rhs) {
            if (lhs.se.fi == rhs.se.fi) {
                if (lhs.se.se == rhs.se.se)
                    return lhs.fi < rhs.fi;
                return lhs.se.se < rhs.se.se;
            } else
                return lhs.se.fi > rhs.se.fi;
        });
        sort(p, p + 5);
        sort(p + 5, p + 10);

        cout << "Case " << tc << ":\n(" << p[0].fi;
        for(int i = 1; i < 5; i++)
            cout << ", " << p[i].fi;
        cout << ")\n(" << p[5].fi;
        for(int i = 6; i < 10; i++)
            cout << ", " << p[i].fi;
        cout << ")\n";
    }

    return 0;
}
