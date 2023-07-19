#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
int countVowelSubstrings(string word)
{
    // materials
    unordered_map<char, int> um; // map to count
    int distinct = 0;            // distinct vowel counts
    int i = 0, j = 0, k = 0;     // ptrs
    int total = 0;

    // move right ptr
    for (j = 0; j < word.size(); j++)
    {
        char curr = word[j];

        // if not vowel -> start the new window (reset the cnt, i, j, k)
        if (!isVowel(curr))
        {
            um.clear();
            i = j + 1;
            k = j + 1;
            distinct = 0;
            continue;
        }

        // if new -> distinct cnt
        if (!um[curr])
            distinct++;

        // increment this count
        um[curr]++;

        while (distinct == 5)
        {
            um[word[k]]--;
            if (!um[word[k]])
                distinct--;
            k++;
        }

        cout << "i : " << i << " " << word[i] << ", k : " << k << " " << word[k] << ", j : " << j << " " << word[j] << ", added " << k - i << endl;
        total += k - i;
    }

    return total;
}

int main()
{
    string s = "aeiouaa";
    cout <<countVowelSubstrings(s);
}