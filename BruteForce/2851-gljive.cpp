#include <iostream>
#include <cmath>

using namespace std;

int arr[10];

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    int goal = 100;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
        // if new sum is closer to 100 (goal) than current res or equal to res, change res to sum
        if (abs(goal - res) >= abs(goal-sum))
        {
            res = sum;
            // if res is greater than 100 than
            if (res > goal)
            {
                cout << res;
                return 0;
            }

        }
    }

    cout << res;
    return 0;

}

/*
int main()
{
    const int goal = 100;
    int sum = 0;
    int score;

    for (int i = 0; i < 10; i++)
    {
        int mush; cin >> mush;
        int sum_before = sum;
        sum += mush;

        // exactly goal?
        if (sum == goal) {
            score = goal;
            continue;
        }
        
        // if it just exceeded the goal
        if (sum_before < goal && sum > goal)
        {
            score = (goal-sum_before < sum-goal) ? sum_before : sum;
        }
        
    }

    // if total sum hasn't reached the goal
    if (sum < goal)
        score = sum;

    
    cout << score << "\n";

    return 0;
}
*/