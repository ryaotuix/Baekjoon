#include <bits/stdc++.h>

using namespace std;

/*
    separate numbers into
    1. negative
    2. 0 and 1
    3. positive

    sort negatvie in ascending order
    sort positive in descending order

    if (negative size is odd)
        -> multiply each besides the last one

    if (positive side is odd)
        -> multiply each besides the last one
*/


// return [sum, remaining value]
vector<int> multiplyVector(vector<int> &vec)
{
    int len = vec.size();
    // if size is odd, there is remaining value
    if (len % 2 == 1)
    {
        int sum = 0;
        int i = 0;
        while (i < len - 1)
        {
            sum += vec[i] * vec[i + 1];
            i += 2;
        }

        return {sum, vec[len - 1]};
    }
    // if size is even,
    else
    {
        int sum = 0;
        int i = 0;
        while (i < len)
        {
            sum += vec[i] * vec[i + 1];
            i += 2;
        }
        return {sum, 0};
    }
}

// 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> negative;
    vector<int> positive;
    bool isZero = false;
    int oneCnt = 0;

    while(N--)
    {
        int temp;
        cin >> temp;

        if (temp < 0)
        {
            negative.push_back(temp);
        }
        else if (temp == 0)
        {
            isZero = true;
        }
        else if (temp == 1)
        {
            oneCnt++;
        }
        else
        {
            positive.push_back(temp);
        }
    }

    // sort negative in ascending
    sort(negative.begin(), negative.end());
    // sort positive in descending
    sort(positive.begin(), positive.end(), greater<int>());

    vector<int> resNegative = multiplyVector(negative);
    vector<int> resPositive = multiplyVector(positive);

    int sum = resNegative[0] + resPositive[0] + resPositive[1] + oneCnt;
    if (!isZero)
    {
        sum += resNegative[1];
    }

    cout << sum;
}