#include <iostream>
#include <vector>

using namespace std;

int main() {
    int inf = 1 << 29;
    int n;

    int h[100001] = { 0 }, b[100001] = { 0 };
    for(int i = 1; i < 100001; i++)
        h[i] = b[i] = inf;

    cin >> n;
    for(int i = 0, ch; i < n; i++) {
        cin >> ch;
        for(int j = 100001 - ch - 1; j >= 0; j--)
            if(h[j] + 1 < h[j+ch])
                h[j+ch] = h[j]+1;
    }

    cin >> n;
    for(int i = 0, cb; i < n; i++) {
        cin >> cb;
        for(int j = 100001 - cb - 1; j >= 0; j--) {
            if(b[j] + 1 < b[j+cb]) {
                b[j+cb] = b[j]+1;
    }

    int ans = inf;
    for(int i = 1; i < 100001; i++)
        if(h[i] + b[i] < ans)
            ans = h[i] + b[i];

    if(ans >= inf/2)
        cout << "impossible" << endl;
    else
        cout << ans << endl;

    return 0;
}