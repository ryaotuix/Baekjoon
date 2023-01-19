#include <iostream>
#include <vector>
#include <string>
#include <cstring>


using namespace std;


class node
{
    int ind;
    struct node * prev;
    struct node * next;

    node(int i) 
    {
        ind = i;
    }
    ~node();    
} node;


class DLL {
    DLL(); // constructor
    ~DLL(); // destructor
    void printInorder(string & arr); // print in order
    private:
        node * head;
        node * tail;
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    int num;
    cin >> num;

    string arr[num+1];
    bool isHead[num+1] = {false};

   
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i+1];
    }
    
    node * head = new node();
    

}