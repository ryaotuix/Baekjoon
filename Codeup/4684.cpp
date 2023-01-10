#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

bool isDecrementing (int a, int b, int n)
{
    // if it is 1, next has to be n if it is decrementing
    if (a == 1)
        return (b == n) ? true : false; 
   
   return (a -1 == b) ? true : false;
}


bool isIncrementing (int a, int b, int n)
{
    // if it is n, the next one has to be 1 if it is incrementing
    if (a == n)
        return (b == 1) ? true : false;
    
    return (a +1 == b)? true : false;
}
    

pii findReversedLocation(int *arr, int n)
{
    int indexA = 0;
    int indexB = 1;
    int start = 0;
    int end = 0;

    while (true)
    {
        if (!isIncrementing(arr[indexA], arr[indexB], n)) break;
        //cout << "index A : " << indexA << " value of arr[A] : " << arr[indexA] << endl;
        //cout << "index B : " << indexB << " value of arr[B] : " << arr[indexB] << endl;
        indexA++;
        indexB++;

        // if index A and B gets out of bounds
        if (indexB == n) indexB = 0;
        if (indexA == n) indexA = 0;

        // cout << "index A : " << indexA << endl;
    }
    //cout << indexA << endl;
    start = indexB + 1;
    //cout << start << endl;

    indexA++;
    indexB++;
    //cout << "-----------------" << endl;

    while (isDecrementing(arr[indexA], arr[indexB], n))
    {
        //cout << "index A : " << indexA << " value of arr[A] : " << arr[indexA] << endl;
        //cout << "index B : " << indexB << " value of arr[B] : " << arr[indexB] << endl;
        indexA++;
        indexB++;

         // if index A and B gets out of bounds
        if (indexB == n) indexB = 0;
        if (indexA == n) indexA = 0;

        // cout << "index A : " << indexA << endl;
    }
    end = indexB;

    //cout << "start position : " << start << " end position : " << end << endl;
    return pii(start, end);
}



int main()
{
    // 여기까지가 input 받고 array 받아내기
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n; i++)
    {
        cin >> arr[i];
    }

   
    // 어디 인덱스가 reverse 되어있는지 찾아내기
    pii p = findReversedLocation(arr, n);
    int a = p.first - 1;
    int b = p.second - 1;

    stack <int> s;
    // make an array and put true if it is reversed
    bool reversed[n];
    for (int i = 0; i < n; i++)
    {
        if (i < a || i > b) reversed[i] = false;
        else {
            reversed[i] = true;
            s.push(arr[i]);
        }
    }


    // Make a new array with the reversed portion organized
    int newarr[n];
    for (int i = 0; i < n; i++)
    {
        if (reversed[i])
        {
            newarr[i] = s.top();
            s.pop();
        }
        else
            newarr[i] = arr[i];
    }

    // Find the index of '1'
    int ind;
    for (int i = 0; i < n; i++)
    {
        if (newarr[i] == 1)
        {
            ind = i;
            break;
        }
    }

    // get total number of shift to left
    int totalMove = n - ind;
    if (totalMove == 1) totalMove += n; 


    cout << totalMove-1 << endl;
    cout << p.first + 1 << " " << p.second + 1 << endl;
    cout << 1 << endl;
    
}

