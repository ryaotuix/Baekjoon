#include <bits/stdc++.h>

using namespace std;

int N; 
string S;
vector<string> vec; // store all substrs
map<string, int> m; // string -> point


void input()
{
    cin >> N >> S;
}

void getSubstrs()
{
    for (int i = 0; i < N; i++)
    {
        string cur;
        for (int j = i; j < N; j++)
        {
            cur.push_back(S[j]);
            if (cur.size() > N-2) break;
            vec.push_back(cur);
        }
    }

    // sort strings
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());   // erase all overlapping strings
}

void fillMap()
{
    int i = 1;
    for (string s : vec)
    {
        m[s] = i;
        i++;
        // cout << s << " " << m[s] << "\n";
    }
}


int getMaxNum()
{
    int ret = 0;
    for (int L = 1; L < N; L++)
    {
        string s1 = S.substr(0, L);
        for (int R = L + 1; R < N; R++)
        {
            string s2 = S.substr(L, R-L);
            string s3 = S.substr(R, N-R);
            // cout << s1 << " " << s2 << " " << s3 << "\n";

            int temp = m[s1] + m[s2] + m[s3];
            ret = max(temp, ret);

        }
    }

    return ret;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    getSubstrs();
    fillMap();
    cout << getMaxNum();
}