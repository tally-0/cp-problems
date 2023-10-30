#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, c[20][3], arr[8];
    while(cin >> n >> m && n + m) {
        for(int i = 0; i < m; i++)
            cin >> c[i][0] >> c[i][1] >> c[i][2];
        
        for(int i = 0; i < n; i++)
            arr[i] = i;
        int ans = 0;
        do {
            bool f = true;
            for(int i = 0; i < m; i++) {
                int a, b;
                for(int j = 0; j < n; j++) {
                    if (c[i][0] == arr[j])
                        a = j;
                    if (c[i][1] == arr[j])
                        b = j;
                }
                if (c[i][2] > 0) {
                    if (abs(a - b) > c[i][2])
                        f = false;
                } else if(abs(a - b) < -c[i][2])
                    f = false;
                if (!f)
                    break;
            }
            if (f)
                ans++;
        } while (next_permutation(arr, arr + n));

        cout << ans << endl;
    }

    return 0;
}
