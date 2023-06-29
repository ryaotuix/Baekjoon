#include <bits/stdc++.h>

/*
    Idea:
        Use Stack to keep the last char
        it is always better to use if current characer < prev character AND prev character exist later on, always better to use prev character later on
    
    Materials:
        stack<char>
        bool arr used
        int arr last index
*/

using namespace std;

stack<char> st;
bool used[26] = {false};
int lastInd[26] = {-1};

void init(string s)
{
    memset(used, false, 26);                                    // init used arr = false
    memset(lastInd, -1, 26);                                    // init lastInd = -1
    for (int i = 0; i < s.size(); i++)                          // fill in last Ind according to string
    {
        lastInd[s[i] - 'a'] = i; 
    }
}

void markUsed(char c)
{
    used[c-'a'] = true;
}

void markUnused(char c)
{
    used[c-'a'] = false;
}

string removeDuplicateLetters(string s)
{
    init(s);

    // first char must be pushed and marked visit
    st.push(s[0]);
    markUsed(s[0]);

    for (int i = 1; i < s.size(); i++)
    {
        char prev = st.top();
        char curr = s[i];

        // if curr is used, skip

        // if curr is not used, 
        if (used[curr - 'a'] == false)
        {
            // if prev > curr AND prev exists later 
            while (!st.empty() && st.top() > curr && lastInd[st.top() - 'a'] > i)
            {
                // POP it and make it unused
                markUnused(st.top());
                st.pop();
            }

            // push curr and make it used
            st.push(curr);
            markUsed(curr);
        }
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}


int main()
{
    string s = "bcabc";
    init(s);
    cout << removeDuplicateLetters(s);

}