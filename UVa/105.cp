#include <iostream>

using namespace std;

int hm[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int l, h, r, maxr = 0;
    while (cin >> l >> h >> r) {
		maxr = max(maxr, r);
        for (int i = l; i < r; i++) hm[i] = max(hm[i], h);
    }
    
    cout << "1 " << hm[1];
    for (int i = 2; i < maxr; i++)
        if (hm[i-1] != hm[i])
			cout << " " << i << " " << hm[i];
    cout << " " << maxr << " 0\n";

	return 0;
}
