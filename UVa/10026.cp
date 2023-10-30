#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
	int dur;
	int fine;
	int id;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases, n, temp;
	cin >> cases;
	while(cases--) {
		cin >> n;
		vector<Job> jobs(n);
		for(int i = 0; i < n; i++) {
			cin >> jobs[i].dur >> jobs[i].fine;
			jobs[i].id = i + 1;
		}
		
		// stable sort to keep lexicographical order
		stable_sort(jobs.begin(), jobs.end(), [] (const Job &lhs, const Job &rhs) {
			return lhs.dur * rhs.fine < rhs.dur * lhs.fine;
		});

		cout << jobs[0].id;
		for(int i = 1; i < n; i++) {
			cout << " " << jobs[i].id;
		}
		cout << endl;
		if(cases) cout << endl;
	}
	
	return 0;
}