#include<iostream>
#include<cmath>

using namespace std;

#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s;
	ll p;
	while(cin >> s >> p && s + p) {
		ll g = sqrt(p) - 1;
		cerr << g << endl;
		int di, dj, l = g + 1;
		if (g % 2) {
			di = (g + 1) / 2;
			dj = -(g + 1) / 2;
			g *= g;
			g += l;
			for(int i = 0; i < l && g < p; i++, di--, g++);
			for(int i = 0; i < l && g < p; i++, dj++, g++);
		} else {
			di = -g / 2;
			dj = g / 2;
			g *= g;
			g += l;
		}
		while(g < p) {
			for(int i = 0; i < l && g < p; i++, di++, g++);
			for(int i = 0; i < l && g < p; i++, dj--, g++);
			l++;
			for(int i = 0; i < l && g < p; i++, di--, g++);
			for(int i = 0; i < l && g < p; i++, dj++, g++);
			l++;
		}
		s++;
		cout << "Line = " << s / 2 + di << ", column = " << s / 2 + dj << "." << endl;
	}
	
	return 0;
}