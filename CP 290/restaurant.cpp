#include <iostream>
#include <string>

using namespace std;

// Flag variables
    int toDrop = 2;
    int toTake = 1;
    int pile1 = 0;
    int pile2 = 0;


void res(int n)
{
    string command;
    int commandNum;

    for (int i = 0; i < n; i++)
    {
        cin >> command >> commandNum;
        
        if (command == "DROP")
        {
            cout << "DROP 2 " << commandNum << "\n";
            pile2 += commandNum;
        }
        else if (command == "TAKE")
        {
            // when we have to take more plates than we have in pile 1
            if (commandNum > pile1)
            {
                int extra = commandNum - pile1;

                // 1st, see there are some plates in pile 1, then empty the pile1
                if (pile1 != 0)
                {
                    cout << "TAKE 1 " << pile1 << "\n";
                    pile1 = 0;
                }
                
                cout << "MOVE 2->1 " << pile2 << "\n";
                pile1 = pile2;
                pile2 = 0;
                cout << "TAKE 1 " << extra << "\n";
                pile1 -= extra;
            }
            // when we have enough plates to take from pile 1
            else
            {
                if (commandNum <= pile1)
                {
                    cout << "TAKE 1 " << commandNum << "\n";
                    pile1 -= commandNum;
                    continue;
                }
                cout << "MOVE 2->1 " << pile2 << "\n";
                cout << "TAKE 1 " << commandNum << "\n";
                pile1 -= commandNum;
            }
        }
    }
    cout << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while (n != 0)
    {
        res(n);
        cin >> n;
        pile1 = 0;
        pile2 = 0;
    }

}