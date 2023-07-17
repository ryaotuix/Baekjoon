#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll divi = 1e9 + 7;

// function 
/*
    pow(a,b) % n =  a ^ b % n   ==      is always 

    = a^(b/2) % n * a^(b - b/2) % n

    Base Case : if a^(b/2) is less than maxInt (sqrt divi)
*/
// Function to calculate modular exponentiation (base^exponent) % modulus
int modularExponentiation(int base, int exponent, int modulus) {
    if (modulus == 1)
        return 0;

    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}


int main()
{
    ll a = 1e9;
    ll b = 1e9;
    ll n = 13;
    ll result = modularExponentiation(a, b, n);
    cout << "\n\n";
    cout << result;
}