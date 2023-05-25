/*Romeo Meets Juliet*/
#include <iostream>

using namespace std;

int n, p, c;    // n : number of total Cowpulets, p : number of Fence Posts, c : tolerable number of Cowpulates

int fence[1000 + 5];

int solve()
{
    int leftptr = 1;
    int rightptr = p + 1;

    int leftCnt = 0;
    int rightCnt = 0;

    bool leftStop = false;
    bool rightStop = false;
    while(true)
    {
        if (leftStop && rightStop)
            break;
        
        if (leftptr == p+1)
            leftStop = true;
        if (rightptr == 1)
            rightStop = true;
        
        if (leftCnt + fence[leftptr] > c)
            leftStop = true;
        if (rightCnt + fence[rightptr-1] > c)
            rightStop = true;


        if (!leftStop)
        {
            leftCnt += fence[leftptr++];
        }
        if (!rightStop)
        {
            rightCnt += fence[rightptr-1];
            rightptr--;
        }
    }

    // cout << leftptr << " " << rightptr << endl;

    return (leftptr - 1 > p - rightptr) ? leftptr - 1 : p - rightptr; 

}

int main()
{
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++)
    {
        int ind; cin >> ind;
        fence[ind]++;
    }

    int res = solve();
    cout << res;

}