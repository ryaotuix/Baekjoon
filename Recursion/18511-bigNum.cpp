#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

// Ingredients
string N;
int eles;
stack <int> s;
int curr = 0;
bool flag = false; // true if it is reached 0
bool filltherest = false;
bool runRec = false;



void recursion(int * sortedSet, string & N, int curr)
{
    // Base case when index reach the length of the string
    cout << "\n";
    cout << "current index is " << curr << endl;


    // Base Cases
    if (curr == N.length())   return;
    if (filltherest)
    {
        while(curr < N.length())
        {
            s.push(sortedSet[0]);
            curr++;
        }
        return;
    }



    // this is an Integer to Compare 
    int toCompare = static_cast<int>(N[curr] - '0');
    cout << "Comparing " << toCompare << endl;

    // when reached 0
    if (toCompare == 0) {
        flag = true;
        runRec = true;
    }
    

    for (int i = 0; i < eles; i++)
    {
       
        int val = sortedSet[i];
        cout << "to " << "sortedSet[" << i << "] " << val << endl;

        // case 1
        if (flag) {
            cout << "ENTER 1\n";
            toCompare = 10; 
            cout << "POP " << s.top() << endl;
            s.pop(); 
            return;
        }

        // case 2
        if (toCompare >= val)
        {
            cout << "ENTER 2\n";
            s.push(val); cout << "PUSH " << val << endl; 
            if (toCompare > val) filltherest = true;
            cout << "\n";
            runRec = true;
        }
        else runRec = false;
        
        // case 3
        if(runRec)
        {
            cout << "ENTER 3\n";
            recursion(sortedSet, N, curr+1);
            break;
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> eles;

    // get elements of K
    int arr[eles];
    for (int i = 0; i < eles; i++)
    {
        int input;
        cin >> input;
        arr[i] = input;
    }

    sort(arr, arr+ eles, greater<int>());

    recursion(arr, N, curr);
    //cout << "---------------------\n";
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

}