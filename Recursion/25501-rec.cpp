#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int rectime = 0;
string word;

int recursion(string & word, int l, int r){
    rectime++;
    if(l >= r) return 1;
    else if(word[l] != word[r]) return 0;
    else {
        return recursion(word, l+1, r-1);
    }
}

int isPalindrome(string & word){
    return recursion(word, 0, word.length()-1);
}


int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        int palin = isPalindrome(word); // is this palindrome?
        cout << palin << " " << rectime << endl;
        rectime = 0;
    }

    return 0;
}