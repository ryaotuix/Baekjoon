#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> vec1;   // > 0
vector<int> vec2;   // <= 0

void input()
{
    cin >> N;
    while(N--)
    {
        int temp;
        cin >> temp;
        if (temp <= 0)
            vec2.push_back(temp);
        else
            vec1.push_back(temp);
    }
    
    int sum = 0;
    // sort vec1 in descending order
    sort(vec1.begin(), vec1.end(), greater<int>());
    // sort vec2 in ascending order
    sort(vec2.begin(), vec2.end());

    if (vec1.size() == 0)
    {

    }
    else if (vec1.size() == 1)
    {
        sum += vec1[0];
    }
    else
    {
        for (int i = 0; i < vec1.size()-1; i++)
        {
            if (vec1[i] * vec1[i+1] > vec1[i] + vec1[i+1])
            {
                sum += vec1[i] * vec1[i+1];
                i++;
            }
            else
            {
                sum += vec1[i];
            }

            cout << "now i is " << i << " " << sum << " ";
        }
        sum += vec1[vec1.size() - 1];

    }

    if (vec2.size() == 0)
    {
        
    }
    else if (vec2.size() == 1)
    {
        sum += vec2[0];
    }
    else
    {
        for (int i = 0; i < vec2.size()-1; i++)
        {
            if (vec2[i] * vec2[i+1] > vec2[i] + vec2[i+1])
            {
                sum += vec2[i] * vec2[i+1];
                i++;
            }
            else
            {
                sum += vec2[i];
            }
            cout << sum << " ";
        }
        sum += vec2[vec2.size() - 1];
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
}