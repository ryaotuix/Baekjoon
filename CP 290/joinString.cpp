#include <iostream>
#include <string>
#include <queue>

using namespace std;

void rec(vector<queue<int>> &qVec, int n, vector <string> &str) 
{
    cout << str[n];
    while (!qVec[n].empty())
    {
        rec(qVec, qVec[n].front(), str);
        qVec[n].pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n; cin >> n;
    //string str[n+1]; // Array declaration in C++

    vector<string> vecStr(n+1); // Vector of String
    
    // store in vecStr
    for (int i = 0; i < n; i++)
        cin >> vecStr[i+1];
    

    vector<queue<int>> vecQ(n+1);
    // vector<queue<int>> vecQ;
    // vecQ.assign(n+1, queue<int>);

    // take Input
    int a = 1; // default is 1 for the case where it only accepts one string
    int b;
    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        vecQ[a].push(b);   
    }

    rec(vecQ, a, vecStr);
    
    return 0;

}