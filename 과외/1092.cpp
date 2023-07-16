#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull x;
ull y;
const ull maxi = 20091024;
// unordered_map<ull, ull> um;     // um : exponent -> value
// unordered_map<ull, int>> isFound; // isFound : exponent -> is found

ull getPow(ull exponent)
{
    // Base Case:
    if (exponent == 1)
    {
        return x;           // then x
    }

    ull temp = getPow(exponent/2);

    // cout << "exp : " << exponent << " temp : " << temp << endl;
    
    // if exponent is even
    if (exponent % 2 == 0) 
        return temp * temp % maxi;
    else
        return (temp * temp) % maxi * x % maxi;
}

// a^2x % N
// a^x % N  *  (a^x % N) % N

int main()
{
    cin >> x >> y;
    cout << getPow(y);
}