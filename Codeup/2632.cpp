#include <iostream>

using namespace std;

int cnt = 0;
int stairs;

void bottomUp(int n)
{
    // n is always 0 ! 
    // get stairs as input in main
    // !!! BASE CASE : When it reaches # of STAIRS 
    if(n == stairs) cnt++;
    if(n >= stairs) return;
    bottomUp(n+1);
    bottomUp(n+2);
}

int topDown(int n)
{
    // Base case: 
    // stair 1: 1
    // stair 2: 2
    // n is target stairs here!!
    if (n == 1) return 1;
    if (n == 2) return 2;
    return (topDown(n-1) + topDown(n-2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);   

    int n; cin >> n;
    cout << topDown(n) << endl;

}


/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> stairs;
    bottomUp(0); // bottom up is 0
    cout << cnt << endl;

}
*/