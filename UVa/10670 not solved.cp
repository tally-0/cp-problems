#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

#define endl '\n'
#define is pair<int,string>
#define vis vector<is>

float log(double base, int res) { return (float)(log2(res) / base); }

void parse(string &in, string &name, int &a, int &b) {
	int delimit = in.find(":");
	name = in.substr(0,delimit);
	in = in.substr(delimit+1);
	delimit = in.find(",");
	a = stoi(in.substr(0,delimit));
	b = stoi(in.substr(delimit+1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases, n, m, l, a, b, c;
	double base = log2(0.5);
	string name, in;

	cin >> cases;
	for(int t = 1; t <= cases; t++) {
		cin >> n >> m >> l;
		cin.ignore();
		vis v(l);

		for(is &i : v) {
			getline(cin, in);
			parse(in, name, a, b);
			int total = 0;

			c = floor(log(base, (float)max(2*a, m)/(float)n));
			cerr << c << endl;
			total += c * b;

			c = (int)((n - (n % 2 == 0 ? 0 : 1)) * (double)pow(0.5, c)) - m + (n % 2 == 0 ? 0 : 1);
			total += c * a;

			i = make_pair(total, name);
		}

		sort(v.begin(), v.end());

		cout << "Case " << t << endl;
		for(is i : v) cout << i.second << " " << i.first << endl;
	}
		
	return 0;
}