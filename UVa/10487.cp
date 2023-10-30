#include<iostream>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a[1000], tc = 1;
    while(cin >> n) {
        cout << "Case " << tc << ": " << endl;
        tc++;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        while(m--) {
            int b;
            cin >> b;
            int closest = INT_MIN * (b / abs(b));
            for(int i = 0; i < n - 1; i++)
                for(int j = i + 1; j < n; j++)
                    if (abs(a[i] + a[j] - b) < abs(closest - b))
                        closest = a[i] + a[j];
            cout << "Closest sum to " << b << " is " << closest << ".\n";
        }
    }

    return 0;
}
