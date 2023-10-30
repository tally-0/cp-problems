#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string top, bot;
	while(cin >> top >> bot) {
		int tl = top.length(), bl = bot.length();
		int res = tl + bl;
		for(int i = -tl; i < bl; i++) {
			bool fits = true;
			for(int j = 0; j < tl; j++) {
				if (i+j >= 0 && i+j < bl && top[j] == bot[i+j] && top[j] != '1') {
					fits = false;
					break; 
				}
			}
			if (fits) res = min(res, max(bl, i + tl) - min(i, 0));
		}
		cout << res << endl;
	}

	return 0;
}