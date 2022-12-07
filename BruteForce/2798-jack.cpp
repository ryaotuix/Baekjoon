#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M; // N is number of cards, M is max sum
    cin >> N >> M;

    int arr[N+1];
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    vector<int> v;
    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(2);

    // for (int i = 0 ; i< v.size(); ++i)
    //     cout << v[i] << endl;

    // add all the possible sum in the vector v
    for (int i = 0; i < N-2; ++i)
    {
        for (int j = i+1; j < N-1; ++j)
        {
            for (int k = j +1; k < N; ++k)
            {
                v.push_back(arr[i] + arr[j] + arr[k]);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > max && v[i] <= M) max = v[i];
    }

    cout << max;
    return 0;
}