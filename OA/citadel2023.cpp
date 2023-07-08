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

unsigned long long calculateModulo(unsigned long long a, unsigned long long b, unsigned long long n) {
    unsigned long long result = 1;

    // Perform modular exponentiation
    a = a % n;
    while (b > 0) {
        // If b is odd, multiply result with a and take modulo n
        if (b & 1) {
            result = (result * a) % n;
        }

        // b must be even now
        b = b >> 1; // Divide b by 2
        a = (a * a) % n;
    }

    return result;
}


int main()
{

}