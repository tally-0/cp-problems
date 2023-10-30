#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, start[24];
	while(cin >> n) {
		for(int i = 0; i < n; i++) cin >> start[i];

		int swaps = 0;
		for(int i = 0; i < n; i++) {
			cin >> a;
			int j;
			for(j = 0; start[j] != a; j++) {
				if(start[j] != -1) swaps++;
			}
			start[j] = -1;
		}
		cout << swaps << endl;
	}

	return 0;
}

// slower variant
/*
#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s[25], e[25];
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            cin >> s[i];
        for(int i = 0; i < n; i++)
            cin >> e[i];
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j;
            for(j = i; j < n; j++)
                if (e[i] == s[j])
                    break;
            for(int k = j; k > i; k--)
                s[k] = s[k - 1];
            ans += j - i;
        }
        cout << ans << endl;
    }

    return 0;
 }
 */
