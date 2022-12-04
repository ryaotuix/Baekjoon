#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int rectime = 0;

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
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        char * s = (char*)malloc(sizeof(char) * 1e3);
        scanf("%s", s);
        int isPalindrome = recursion(s, 0, strlen(s)-1); // is this palindrome?
        cout << isPalindrome << " " << rectime << endl;
        rectime = 0;
    }

    return 0;
}