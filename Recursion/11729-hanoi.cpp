#include <iostream>
#include <math.h>


using namespace std;

/*
ALGORITHM
i) Move (n-1) from A to B
ii) move bottom from A to C
iii) move (n-1) from B to C
*/


int cnt;
// A, B, C are sticks (starting as 1, 2, 3)
void hanoi(int discs, int A, int B, int C) // starting from A, use B, to move all to C
{
    if (discs == 1)
    {
        cout << A << " " << C << "\n";
        return;
    }
    hanoi(discs-1, A, C, B); // starging from A, use C, to move all to B (i)
    cout << A << " " << C << "\n"; // (ii)
    hanoi(discs-1, B, A ,C); // starting from B, use A, to move all to C (iii)
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int discs;
    cin >> discs;
    cnt = (int) pow(2, discs) - 1;
    cout << cnt << endl;
    hanoi(discs, 1, 2, 3);
    
    return 0;
}
