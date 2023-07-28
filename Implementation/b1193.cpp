// #include <bits/stdc++.h>

// using namespace std;

// void getFraction(int target)
// {
//     int num = 1;
//     int increment = 1;
//     int notOneVal = 1;
//     bool increase = true;

//     while (num <= target)
//     {
//         notOneVal++;
//         increase = !increase;
//         num += increment;
//         increment++;
//     }

//     // i.e. if target = 7, num = 11, increment = 5
//     increment--;
//     num -= increment;
//     notOneVal--;
//     increase = !increase;

//     // if (increase  == false, notOneVal is at denom)
//     // if (increase == true, notOnevVal is at num)
//     int denom = 1;
//     int numer = 1;
//     if (!increase)
//     {
//         denom = notOneVal;
//     }
//     else
//     {
//         numer = notOneVal;
//     }

//     while (num < target)
//     {
//         if (increase)
//         {
//             numer--;
//             denom++;
//         }
//         else
//         {
//             numer++;
//             denom--;
//         }
//         num++;
//     }

//     cout << numer << "/" << denom;
// }

// int main()
// {
//     int target;
//     cin >> target;
//     getFraction(target);
// }

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int input; cin >> input;

    // function to get a line
    int l = 1;
    while(true)
    {
        // This is nice little sequence!
        if ((l-1)*l/2 < input && input <= l*(l+1)/2)
        {
            //cout << l << endl;
            break;
        }
        l++;
    }

    int denom = 1;
    int nom = 1;

    int howManyBefore = (l-1)*l/2;
    int thisLine = input - howManyBefore - 1;

    // if line is even, it strts as 1/line
    if (l % 2 == 0)
    {
        denom = l - thisLine;
        nom = 1 + thisLine;
        
    }
    // if line is odd, it starts as line/1
    else
    {
        nom = l - thisLine;
        denom = 1 + thisLine;
    }

    cout << nom << "/" << denom;


    

}