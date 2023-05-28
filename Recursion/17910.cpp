// #include <bits/stdc++.h>

// using namespace std;

// // denominator and nominator
// int denom;
// int nom;
// vector<int> v;

// // 통분 function
// void fractionRed()
// {
//     int x = __gcd(nom, denom);
//     nom = nom / x;
//     denom = denom / x;
// }

// // start with right = 1 (right is a ptr of a vector)
// void rec(int right)
// {
//     int left = right - 1;
//     // base case : when right reach the end of the vector
//     if (right == v.size() - 1)
//     {
//         denom = v[right];
//         nom = v[left] * v[right] + 1;
//         fractionRed();
//         return;
//     }


//     // otherwise:
//     rec(right + 1);
    
//     // swap denom and nom
//     int temp = denom;
//     denom = nom;
//     nom = temp;

//     nom = left * denom + nom;
//     fractionRed();
// }



// int main()
// {
//     // input accept
//     int n; cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int input; cin >> input;
//         v.push_back(input);
//     }

//     // start
//     rec(1);

//     // 만약 1 이면
//     if (nom == denom)
//         cout << 1;
//     else
//         cout << nom << "/" << denom;
// }


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii; // first : nom  second : denom

vector<ll> v;          // vector that stores Xi
// ll nom;                // 분자
// ll denom;              // 분모

ll getGCD(ll a, ll b)
{
    ll rem = a % b;
    if (rem == 0)
        return b;
    return getGCD(b, rem);
}


pii rec(ll x)
{
    // base case:
    if (x == v.size() - 1)
    {
        return {1, v[x]};
    }

    // otherwise REC +1 
    pii before = rec(x+1);      // first : 분자   second : 분모

    ll nom = v[x] * before.second + before.first;
    ll denom = before.second;

    // 통분
    ll gcd = getGCD(nom, denom);

    // base:
    if (x == 0)
        return {nom/gcd, denom/gcd};
    else
        return {denom/gcd, nom/gcd};
}


int main()
{
    // input done
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        v.push_back(temp);
    }

    pii res = rec(0);

    // if (res.second == 1)
    // {
    //     cout << res.first;
    //     return 0;
    // }
    cout << res.first << "/" << res.second;
}