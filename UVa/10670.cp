#include<iostream>
#include<algorithm>
#include<sstream>

using namespace std;

#define endl '\n'
typedef pair<int, string> pis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, m, l;
	pis costs[100];
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> l;
		cin.ignore();
		for(int i = 0; i < l; i++) {
			string str, name;
			int a, b;
			getline(cin, str);
			cerr << str << endl;
			for(int j = 0; j < str.length(); j++)
				if (str[j] == ',' || str[j] == ':')
					str[j] = ' ';
			stringstream ss(str);
			ss >> name >> a >> b;
			int w = n * 2, cost = -b, cifs;
			do {
				cost += b;
				w /= 2;
				cifs = a * (w - (w / 2));
			} while (w / 2 >= m && cifs > b);
			cost += (w - m) * a;
			costs[i] = { cost, name };
		}
	
		sort(costs, costs + l, [](const pis &lhs, const pis &rhs) {
			if (lhs.first == rhs.first)
				return lhs.second < rhs.second;
			return lhs.first < rhs.first;
		});

		cout << "Case " << tc << endl;
		for(int i = 0; i < l; i++)
			cout << costs[i].second << " " << costs[i].first << endl;
	}

	return 0;
}