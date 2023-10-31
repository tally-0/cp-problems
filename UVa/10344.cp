#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int nums[5];

bool calc(int o, int s) {
    if (o == 4)
        return s == 23;
    o++;
    return calc(o, s + nums[o]) || calc(o, s - nums[o]) || calc(o, s * nums[o]);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4]) {
        int s = 0;
        for(const int &n : nums)
            s += n;
        if (!s)
            break;

        sort(nums, nums + 5);
        bool f = false;
        do {
            f = calc(0, nums[0]);
        } while (next_permutation(nums, nums + 5) && !f);
        
        if (f)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}