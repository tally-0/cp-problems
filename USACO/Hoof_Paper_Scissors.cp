#include <iostream>

using namespace std;

#define endl "\n"

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n, arr[3][100001];
    cin >> n;
    arr[0][0] = arr[1][0] = arr[2][0] = 0;
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        arr[0][i] = arr[0][i - 1] + (c == 'S');
        arr[1][i] = arr[1][i - 1] + (c == 'P');
        arr[2][i] = arr[2][i - 1] + (c == 'H');
    }

    int ans = -1;
    for(int i = 1; i <= n; i++) {
        int wins = max(arr[0][i], max(arr[1][i], arr[2][i]));
        wins += max(arr[0][n] - arr[0][i], max(arr[1][n] - arr[1][i], arr[2][n] - arr[2][i]));
        ans = max(ans, wins);
    }
    cout << ans << endl;

    return 0;
}