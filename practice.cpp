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

using namespace std;

// 1. 
struct book{
    int size;
    string name;
    bool operator<(book& other) {
        if (size == other.size) return name < other.name;
        return size <other.size;
    }
    void printBook() {
        cout << "Book's name : " << name << "\n";
        cout << "Book's size : " << size << "\n";
    }
};

bool cmp(const book &a, const book&b)
{
    if  (a.size != b.size) return a.size > b.size;
    return a.name > b.name;
}

int main()
{
    string s; cin >> s; // let's say it is always 0.99 (two decimal places)
    int i = stoi(s.substr(2,1)); // stoi(string.(starting index, length))
    cout << i;
    // 1.
    book a = book{1000, "B thrown of glass"};
    book b = book{1000, "A harry potter"};
    book c = book{10, "C my lil ponny"};

    book arr[4]; arr[1] = a; arr[2] = b; arr[3] = c;
    arr[0].printBook(); arr[1].printBook(); arr[2].printBook(); arr[3].printBook(); 
        sort(arr+1, arr+4);


    cout << endl;
    vector<book> library = {a, b, c};
    
    sort(library.begin(), library.end()); // sort ascending
    sort(library.begin(), library.end(), cmp); // sort descending
    
    for (int i =1 ; i<4; i++)
    {
        arr[i].printBook();
    }
    // for (auto& book : arr) book.printBook();

    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(1);
    minPQ.push(3);
    minPQ.push(0);
    while (!minPQ.empty())
    {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }

}