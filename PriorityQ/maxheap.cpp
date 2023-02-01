#include <bits/stdc++.h>

using namespace std;

class MaxHeap 
{
    private:
        vector<int> maxHeap = {0,9,7,6,5,4,3,2,1,8};
    public:
        int size = maxHeap.size()-1;
        void printInfo();
        void swimUP(int ind);
        void insert(int x);
        void sinkDown(int ind);
        void deleteTop();
};

void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b= temp;
}
void MaxHeap::printInfo()
{
    for (int i = 1; i <= size; i++)
        cout << maxHeap[i] << " ";
    cout << "\n";
}
void MaxHeap::swimUP(int ind)
{
    int x = ind;
    while (ind > 1 && maxHeap[ind/2] < maxHeap[ind]) // if the parent < this leaf
    {
        swap(maxHeap[ind/2], maxHeap[ind]);
        ind = ind/2;
    }
    cout << "index " << x << " (i.e) MaxHeap[" << x << "] : " << maxHeap[ind] << " Swam UP!\n";
}
void MaxHeap::insert(int x)
{
    size++;
    maxHeap.push_back(x); 
    swimUP(size);
}
void MaxHeap::sinkDown(int ind)
{
    while (2*ind <= size)
    {
        int j = 2*ind;
        if (j<size && maxHeap[j]<maxHeap[j+1]) j++;
        if (maxHeap[ind] > maxHeap[j]) break;
        swap(maxHeap[j], maxHeap[ind]);
        ind = j;
    }
}
void MaxHeap::deleteTop()
{
    swap(maxHeap[1], maxHeap[size]);
    size--;
    sinkDown(1);
}



int main()
{
    MaxHeap x;
    x.printInfo();
    cout << "\n";

    x.swimUP(x.size);
    x.printInfo();
    cout << "\n";

    x.insert(10);
    x.printInfo();
    cout << "\n";

    x.deleteTop();
    x.printInfo();
    cout << "\n";

}