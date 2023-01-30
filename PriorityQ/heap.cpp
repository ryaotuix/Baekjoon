#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> minPQ = {0,1,3,4,5,6,7,8,9,2};
int minSize = minPQ.size()-1;

vector<int> maxPQ = {0,9,7,6,5,4,3,2,1,8};
int maxSize = maxPQ.size()-1;

void printVector(vector<int> v)
{
    for (int i = 1; i <= v.size()-1; i++)
        cout << v[i] << " ";

    cout << "\n";
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// MIN HEAP -----------------------------------------------------------------------------------------------------------------------
void swimUpMin(int ind, vector<auto> & v)
{
    while (ind > 1 && v[ind/2] > v[ind])
    {
        cout << "minPQ[ind] : " << v[ind] << " and minPQ[ind/2] : " << v[ind/2] << "\n";
        printVector(v);
        swap(v[ind/2], v[ind]);
        ind = ind/2;
    }
    printVector(v);
}

void sinkDownMin(int ind, vector<auto> & v)
{
    int n = v.size();
    while(2*ind <= n)
    {
        int j = 2*ind;
        if (j < n && v[j]<v[j+1]) j++;
        if (!(v[ind] < v[j])) break;
        swap(v[ind], v[j]);
        ind = j;
    }
}

// MAX HEAP -----------------------------------------------------------------------------------------------------------------------

void swimUpMax(int ind, vector<auto> & v)
{
    while (ind > 1 && v[ind/2] < v[ind])
    {
        cout << "maxPQ[ind] : " << v[ind] << " and maxPQ[ind/2] : " << v[ind/2] << "\n";
        printVector(v);
        swap(v[ind/2], v[ind]);
        ind = ind/2;
    }
    printVector(v);
}

int main()
{

    swimUpMin(minSize, minPQ);
    cout << "===================================================\n";
 
    swimUpMax(maxSize, maxPQ);
}