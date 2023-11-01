#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int n, w[20], h[20], x[20], y[20], ans;
int area, used[20];

bool ins(int i, int j) {
    return !((x[i] + w[i]) <= x[j]) && 
			!(x[i] >= (x[j] + w[j])) && 
			!((y[i] + h[i]) <= y[j]) && 
			!(y[i] >= (y[j] + h[j]));
}

void backtrack(int i) {
	if (i == n) {
		ans = max(area, ans);
		return;
	}
	bool f = true;
	for(int j = 0; j < i && f; j++)
		if (used[j])
			f = !ins(j, i);
	if (f) {
		area += w[i] * h[i];
		used[i] = true;
		backtrack(i + 1);
		used[i] = false;
		area -= w[i] * h[i];
	}
	backtrack(i + 1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n && n) {
		for(int i = 0; i < n; i++)
			cin >> w[i] >> h[i] >> x[i] >> y[i];
		
		ans = 0, area = 0;
		memset(used, false, sizeof(used));
		backtrack(0);
		cout << ans << endl;
	}

	return 0;
}