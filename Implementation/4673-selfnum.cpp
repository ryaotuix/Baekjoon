#include <iostream>

using namespace std;
const int N = 10001;
bool arr[N]; // default is false (0)


/*
// my method 1
bool isSelf (int n)
{
    int first, tenth, hundredth, thousand, sum;
    for (int i = 1; i < n; i++)
    {
        first = i%10;
        tenth =  ((i%100) - first)/10;
        sum = i+ first + tenth;
        
        if (i >= 100) 
        {
            hundredth = ((i%1000) - (10*tenth) - first)/100;
            sum += hundredth;
        }
        if (i >= 1000)
        {
            thousand = i/1000;
            sum += thousand;
        }
        if (n == sum) return false;   
    }
  
    return true;
}
*/

// n 이 생성자일때 값을 리턴
int d(int n)
{
    int sum = 0;
    sum += n; // add itself

    while (n != 0)
    {
        sum += n%10; // add first digit into
        n = n/10; // 1234 becomes 123
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    //int n = 1e4;
    for (int i = 1; i < N; i++)
    {
        int dn = d(i);
        if (dn < N)
            arr[dn] = true; // 생성자가 있으면 true 로 바꾸기
        // if (isSelf(i))
        // {
        //     cout << i << endl;
        // }
    }

    for (int i =1; i<N; ++i)
    {
        if (arr[i] == false)
            cout << i << endl;
    }
    return 0;
}