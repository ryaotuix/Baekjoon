#include <bits/stdc++.h>

using namespace std;

// materials
int len;
int total;
char arr[15 + 5];   // valid password
unordered_map<char, int> um;   // char -> visited or not

void input()
{
    cin >> len >> total;
    for (int i = 0; i < total; i++)
        cin >> arr[i];

    // sort
    sort(arr, arr + total);

    // for (int i = 0; i < total; i++)
    //     cout << arr[i] << " ";
    // cout << "\n";
}

bool isVowel(char & c)
{
    if (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u')
        return true;
    
    return false;
}


char res[15 + 5];   // store result

// depth = 0, prev = 0, consonant = 0
void dfs(int depth, int prev, int vowel, int consonant)
{
    // Base Case: depth == len
    if (depth == len)
    {
        // print only when consonant count is >= 2
        if (vowel >= 1 && consonant >= 2)
        {
            for (int i = 0; i < len; i++)
                cout << res[i];
            cout << endl;
        }

        return;
    }

    for (int i = 0; i < total; i++)
    {
        // not visited and i >= prev
        if (!um[ arr[i] ] && i >= prev)
        {
            // mark used
            um[ arr[i] ]++;

            // fill result 
            res[depth] = arr[i];
            
            // recurse with different vowel and consonant count according to the current char
            if (isVowel( arr[i] ))
                dfs(depth+1, i, vowel + 1, consonant);
            else    
                dfs(depth+1, i, vowel, consonant+1);
            
            // mark it unused
            um[ arr[i] ]--;
        }
    }
}


int main()
{
    input();
    dfs(0, 0, 0, 0);
}
