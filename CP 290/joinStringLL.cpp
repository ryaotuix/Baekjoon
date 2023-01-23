#include <iostream>
#include <vector>
#include <string>
#include <cstring>


using namespace std;


class node
{
    public:
    int ind;
    node * prev;
    node * next;

    // Constructor
    node(int i) 
    {
        ind = i;
    }
    ~node();    
};


class DLL {
    public:
    DLL(); // constructor
    ~DLL(); // destructor
    void printInorder(string & arr); // print in order
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
    DLL heads[num];


    // save it in string array
    for (int i = 0; i < num; i++)   cin >> arr[i+1];
    
    
    int a, b;
    for (int i = 0; i < num-1; i++)
    {
        
        cin >> a >> b;
        
        // if a is Head (start of the DLL chain) already
        if (isHead[a] == true)
        {
            // if b is Head (start of the DLL chain) already
            if (isHead[b] == true)
            {
                // attach two chains
                heads[a].tail -> next = heads[b].head;
                heads[b].head -> prev = heads[a].tail;
                continue;
            }
            // if b is not head
            node * node_b = new node(b);    // create a node with b
            // and make it as tail of this DLL chain (a)
            heads[a].tail -> next = node_b;
            node_b -> prev = heads[a].tail;
            heads[a].tail = node_b;
        }
        // if a is not Head
        else 
        {
            // make nodes a and b
            node * node_a = new node(a);
            node * node_b = new node(b);
            node_a -> next = node_b;
            node_b -> prev = node_a;
            // make DLL
            DLL * wow = new DLL();
            // a becomes head and b becomes tail for this DLL chain
            wow -> head = node_a;
            wow -> tail = node_b;
            // Store this chain of DLL at the index of 'a' (head node)
            heads[a] = *wow;
            isHead[a] = true; // we would have to make this flag true 
            
        }
    }

    //node * start = heads[a].head;
    

}