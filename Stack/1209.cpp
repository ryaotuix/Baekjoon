#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s, int k) {
    stack<int> counts;
    for (int i = 0; i < s.size(); ++i) {
        // cout << s[i] << " ";
        if (i == 0 || s[i] != s[i - 1]) {
            counts.push(1);
        } else if (++counts.top() == k) {
            // cout << counts.top();
            counts.pop();
            s.erase(i - k + 1, k);
            i = i - k;
        }
        // cout << counts.top();
        // cout << endl;
    }
    return s;
    // git change
}

int main()
{
    string s = "deeedbbcccbdaa";
    int k = 3;

    removeDuplicates(s, k);
}