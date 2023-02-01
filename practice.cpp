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

struct book{
    string name;
    int size;
    bool operator<(book& other) {
        if (size == other.size) return name < other.name;
        return size < other.size;
    }
    void printBook()
    {
        cout << "Name : " << name << "\n";
        cout << "Size : " << size << "\n"; 
    }
};

bool cmp(const book&a, const book&b)
{
    if (a.size == b.size) return a.name > b.name;
    else return a.size > b.size;
}

int main()
{
    string s; cin >> s;
    int x = stoi(s.substr(2, 4)); // ex) 3.141592 ==> 1415
    cout << x << endl;

    vector<book> library;

    book arr[5];
    book a = {"Harry Potter", 520}; arr[1] = a;
    book b = {"Lord of the rings", 1000}; arr[2] = b;
    book c = {"Bible", 5000}; arr[3] = c;
    book d = {"A Piano Tutorial", 1000}; arr[4] = d;

    // push in a vector called library
    library.push_back(c); library.push_back(b); library.push_back(a); library.push_back(d);

    // print arr and sort arr
    for (int i = 1; i <5; i++) arr[i].printBook();
    sort(arr+1, arr+5, cmp);
    cout << "---------------sorted-----------------\n";
    for (int i = 1; i <5; i++) arr[i].printBook();

    book min = *min_element(arr+1, arr+5);
    book max = *max_element(arr+1, arr+5);
    cout << "MIN: ";
    min.printBook();
    cout << "MAX: ";
    max.printBook();

    // print vector and sort vector
    // for (auto book : library) book.printBook();
    // sort(library.begin(), library.end(), cmp);
    // cout << "--------------sorted---------------\n";
    // for (auto book : library) book.printBook();

}