#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int rectime = 0;
char word[1001];

int recursion(const char *s, int l, int r){
    rectime++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else {
        return recursion(s, l+1, r-1);
    }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
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