#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    stack<int> s;
    pair<int,int> brackets[10];
    int np = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(')
            s.push(i);
        if(str[i] == ')') {
            brackets[np++] = { s.top(), i };
            s.pop();
        }
    }

    vector<string> ans;
    for(int i = 1; i < (1 << np); i++) {
        bool print[200] = { false };
        for(int j = 0; j < np; j++) {
            if(i & (1<<j)) {
                print[brackets[j].first] = true;
                print[brackets[j].second] = true;
            }
        }
        string t = "";
        for(int j = 0; j < str.size(); j++)
            if(!print[j])
                t += str[j];
        ans.push_back(t);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(const string &i : ans)
        cout << i << endl;
}