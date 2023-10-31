#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

#define endl '\n'

int s, d;

int backtrack(int postings[12], int m = 0, int t = 0) {
    if(m >= 5) {
        int sum = 0;
        for(int i = m - 5; i < m; i++)
            sum += postings[i];
        if(sum >= 0)
            return INT_MIN;
        if (m == 12)
            return t;
    }
    int a[12] , b[12];
    for(int i = 0; i < m; i++)
        a[i] = b[i] = postings[i];
    a[m] = s;
    b[m] = -d;
    return max(backtrack(a, m + 1, t + s), backtrack(b, m + 1, t - d));
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    int zeros[12] = { 0 };
    while(cin >> s >> d) {
        int ans = backtrack(zeros);
        if(ans < 0)
            cout << "Deficit\n";
        else
            cout << ans << '\n';
    }

    return 0;
}