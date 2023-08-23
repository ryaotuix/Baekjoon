#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> strings;
bool used[10] = {false, };
int ret = 0;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        strings.push_back(temp);
        ret += temp.size();
    }
    
    return;
}


int getExtra(string & a, string & b)
{
    int ret = b.size();

    int dif = a.size()-b.size();
    int last = max(0, dif);

    // start index for str a
    for (int i = a.size() - 1; i >= last; i--)
    {
        int k = i;  // index for str a
        int j = 0;  // index for str b
        bool change = true;


        while (k < a.size())
        {
            if (b[j] != a[k])
            {
                change = false;
                break;
            }
            k++;
            j++;
        }

        if (change)
        {
            int newret = b.size()- (a.size() - i);
            ret = min(ret, newret);
        }

    }

    return ret;
}

void dfs(int prev, int currLen, int depth)
{
    // base case:
    if (depth == n)
    {
        ret = min(ret, currLen);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = true;

            // starting with this word,
            if (prev == -1)
                currLen += strings[i].size();
            else 
                currLen += getExtra(strings[prev], strings[i]);
            
            dfs(i, currLen, depth + 1);

            if (prev == -1)
                currLen -= strings[i].size();
            else 
                currLen -= getExtra(strings[prev], strings[i]);

            used[i] = false;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    dfs(-1, 0, 0);
    cout << ret << endl;
}