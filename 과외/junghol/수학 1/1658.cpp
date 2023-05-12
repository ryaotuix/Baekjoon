#include <iostream>

using namespace std;


/*
// 최대 공약수
int gcf(int a, int b)
{
    int smaller = a < b ? a : b;
    while (smaller)
    {
        if (a % smaller == 0 && b % smaller == 0)
            return smaller;
        smaller--;
    }
    return -1;
}

//  최대 공배수
int lcm(int a, int b)
{
    int greater = a > b ? a : b;
    int cnt = 1;

    while (true)
    {
        int target = greater * cnt;
        if (target % a == 0 && target % b == 0)
            return target;
        cnt++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int greatestCommonFactor = gcf(a, b);
    int leastCommonMultiple = lcm(a, b);

    cout << greatestCommonFactor << "\n" << leastCommonMultiple;

    return 0;
}
*/

// USE EUCLIDEAN ALGORITHM
/*
1. gcf(a, b) = gcf(b, a%b)
2. lcm(a, b) = a*b / gcf(a, b)
*/

int gcf(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a%b == 0)
        return b;
    else 
        return gcf(b, a%b);
}


int main()
{
    int a, b;
    cin >> a >> b;
    int g = gcf(a, b);
    int l = a* b / g;
    cout << g << "\n" << l;
}