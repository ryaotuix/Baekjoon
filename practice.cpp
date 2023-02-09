#include <bits/stdc++.h>


// USING STANDARD LIBRARY
// 1. Make STRUCTURES (book with name and size) and array of them/ vector of them
// 2. sort by its name (make operator)
// 3. sort by its size (make operator)
// 4. sort arrays (both descending and ascending)
// 5. make min Priority Queue, max Priority Queue
// 6. get minimum element from the array
// 7. get maximum element from the array 
// 8. accept decimal (2 decimal places, 3 decimal places), and change it to integer
// 9. move vector elements 1 right
// 10. hashmap using map <int, int>

using namespace std;

struct book
{
    string name;
    int size;
    bool operator<(book & other) { return size > other.size;}
    void printInfo(){
        cout << name << " " << size << endl;
    }
};

class MyCompare
{
    public: 
    bool operator()(const book & a, const book& b)
    {
        if (a.size == b.size) return a.name < b.name;
        return a.size < b.size;
    }
};


void printV(vector<auto>&v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i].printInfo();
    }
    cout << endl;
}


int main()
{
    book a = {"Harry Potter", 1000};
    book b = {"Bible", 5000};
    book c = {"Lord", 10};
    book d = {"A book", 10};
    vector<book> v = {a, b, c, d};
    printV(v);
    sort(v.begin(), v.end(), MyCompare());
    printV(v);
    sort(v.begin(), v.end());
    printV(v);

    priority_queue<book, vector<book>, MyCompare> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);

    while (!pq.empty())
    {
        book curr = pq.top();
        curr.printInfo();
        pq.pop();
    }

}



