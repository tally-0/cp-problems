#include<iostream>
#include<cfloat>
#include<cmath>
#include<iomanip>

using namespace std;

#define endl '\n'

double d, cap, mpg, cost, sd[55], sp[55];
int s;

double backtrack(double cd, double cc, double cf, int i) {
	if (i == s) {
		double rem = d - cd;
		if (rem <= cf * mpg)
			return cc;
		return DBL_MAX;
	}
	double rem = sd[i] - cd;
	if (rem > cf * mpg)
		return DBL_MAX;
	cf -= (rem / mpg);
	double nrc = backtrack(sd[i], cc, cf, i + 1);
	if (cf <= cap / 2)
		return min(backtrack(sd[i], cc + round((cap - cf) * sp[i]) / 100 + 2, cap, i + 1), nrc);
	return nrc;
}
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(2);
	cout << fixed;

	for(int t = 1; cin >> d && d >= 0 ; t++) {
		cin >> cap >> mpg >> cost >> s;
		for(int i = 0; i < s; i++)
			cin >> sd[i] >> sp[i];

		double ans = backtrack(0, cost, cap, 0);
		
		cout << "Data Set #" << t << endl;
		cout << "minimum cost = $" << ans << endl;
	}

	return 0;
}