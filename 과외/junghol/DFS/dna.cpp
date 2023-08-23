#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> strings;
bool used[10] = {false, };
string res;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        res += temp;
        strings.push_back(temp);
    }
    
    return;
}

string combine(string & a, string & b)
{
    string s = a + b;
    
    int sizeDif = a.size() - b.size();
    for (int i = a.size()-1; i >= max(0, sizeDif); i--)
    {
        int j = 0;
        
        if (b[j] == a[i])
        {
            // check if the rest of a is same as rest of b
            int k = i;
            bool found = true;
            while(k < a.size())
            {
                if (b[j] != a[k])
                {
                    found = false;
                    break;
                }
                k++;
                j++;
            }

            if (found)
            {
                // edge case where if b > a and a is all matched and i starts from 0
                if (b.size() > a.size() && i == 0)
                    s = b;
                else
                    s = a.substr(0, i) + b;
            }
        }
    }

    return s;
}

int arr[10];

void dfs(string & comb, int cnt)
{
    // base case: if cnt == n, then we have counted all
    if (cnt == n)
    {
        // replace res if new comb is shorter
        if (comb.size() < res.size())
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << ": ";
            cout << res << "\n";
            res = comb;
        }
        return;
    }

    for (int i = 0; i < strings.size(); i++)
    {
        if (!used[i])
        {
            arr[cnt] = i;
            used[i] = true;
            string s = combine(comb, strings[i]);
            dfs(s, cnt + 1);
            used[i] = false;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << "\n";

    string start = "";
    int cnt = 0;
    dfs(start, cnt);

    cout << res.size() << "\n";
    cout << res;

    vector<string> vec = {"T", "TAG", "ACTG", "CA", "TGCAG"};
    
    cout << "\n";
    cout << "-----------------------------\n";
    string s = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        cout << s << " ";
        s = combine(s, vec[i]);
    }
    cout << s;
}