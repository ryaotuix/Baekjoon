// #include <bits/stdc++.h>
// #include <string>

// using namespace std;

// string maxS;
// int fin;
// int res;

// void printMax(vector<char> & vectorSet, int stringInd, bool wasSmall)
// {
//     if (stringInd == fin)   // when string Index exceeds the final (print all possible digits)
//         return;

//     for (int i = 0; i < vectorSet.size(); i++)
//     {
//         if (wasSmall)                   // (if previously printed digit is smaller than the target, we should print the max for the rest)
//         {
//             cout << vectorSet[0];
//             printMax(vectorSet, stringInd + 1, wasSmall);
//             return;
//         }

//         if (vectorSet[i] <= maxS[stringInd])      // only print when the vectorSet[i] is smaller than the current digit
//         {
//             cout << vectorSet[i];
//             if (vectorSet[i] < maxS[stringInd])
//                 wasSmall = true;

//             printMax(vectorSet, stringInd + 1, wasSmall);
//             return;
//         }
//     }
// }


// int main()
// {
//     cin >> maxS;
//     int n; cin >> n;
//     fin = maxS.length();

//     vector<char> vectorSet;
//     for (int i = 0; i < n; i++)
//     {
//         char tmp; cin >> tmp;
//         vectorSet.push_back(tmp);
//     }

//     sort(vectorSet.begin(), vectorSet.end(), greater<char>());  // sort so that we can check the biggest one first

//     printMax(vectorSet, 0, false);

// }


// #include <bits/stdc++.h>

// using namespace std;

// int n, k;
// int res = 0;
// int digit = 0;

// int getClosestMax(vector<int> & v)
// {
//     cout << digit << " " << res << endl;
//     // Base case : when digit == -1     or   res becamse the target (n)
//     if (digit == -1)
//         return res;

//     bool didAdd = false;

//     for (int n : v)
//     {
//         int curr = n * (int) pow(10, digit);
//         cout << curr << "!!!!" << endl;
//         if ((res + curr <= n) && (digit >= 0))
//         {
//             res += curr;
//             digit--;
//             didAdd = true;
//             return getClosestMax(v);
//         }
//     }
    
//     // for the case when currs are all bigger
//     if (didAdd == false)
//     {
//         digit--;
//         return getClosestMax(v);
//     }

//     return res;
// }


// int main()
// {
//     cin >> n >> k;

//     int forDigit = n;
//     while (forDigit > 9)
//     {
//         digit++;
//         forDigit /= 10;
//     }
//     // Here, we have total number of digits (ex, 657 ==> 2)

//     vector<int> vSet;
//     for (int i = 0; i < k; i++)
//     {
//         int t; cin >> t;
//         vSet.push_back(t);
//     }
//     sort(vSet.begin(), vSet.end(), greater<int>());
//     // Here, vSet would contain items in descending order

    
//     res = getClosestMax(vSet);
//     cout << res;

// }


#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int res = 0;
vector<int> v;

// num : number that I can make with k dif numbers
// ten : 자릿수
void dfs(int num, int ten)
{
    // base case: when number exceeds n
    if (n < num)
        return;
    
    // cout << "res : " << res << " num : " << num << endl;
    res = max(res, num);            // update result if number exceed res, save res

    for (int i = 0; i < v.size(); i++)
    {
        dfs(num + v[i]*ten, ten * 10);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    dfs(0, 1);
    cout << res;
    
    return 0;
}

