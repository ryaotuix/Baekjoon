#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N;
int dice[6];
int sumOne = 51;
int sumTwo = 101;
int sumThree = 151;

int total = 0;
int max1 = 0;

void input()
{
    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i];
        total += dice[i];
        max1 = max(max1, dice[i]);
    }
}

ll getSum()
{

    ll numDice = N * N * N;

    for (int i = 0; i < 6; i++) 
    {
        sumOne = min(sumOne, dice[i]);
        
        for (int j = i + 1; j < 6; j++)
        {
            // skip if it is opposite
            if (i+j == 5)   continue;
            sumTwo = min(sumTwo, dice[i]+dice[j]);

            for (int k = j+1; k < 6; k++)
            {
                // skip if two sides are opposite
                if (k+i == 5 || k+j == 5)    continue;
                sumThree = min(sumThree, dice[i]+dice[j]+dice[k]);
            }
        }
    }

    ll numThree = 4;
    ll numTwo = ((N-2) * 4) + ((N-1)*4); // 위에, 옆에
    ll numOne = (N-2) * (N-2) + ((N-2)*(N-1)*4);

    return (sumOne*numOne) + (sumTwo*numTwo) + (sumThree*numThree); 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();

    // exception
    if (N == 1)
    {
        cout << total - max1;
        return 0;
    }

    cout << getSum();
}