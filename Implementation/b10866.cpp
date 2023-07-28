#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int val;
    Node * next;
    Node * prev;
    // constructor
    Node(int a)
    {
        val = a;
        next = NULL;
        prev = NULL;
    }
} Node;


class MyDeque
{
 public:
    Node * head;        
    Node * tail;
    int size = 0;

    // functions
    void push_front(int x)
    {
        Node * node = new Node(x);
        size++;

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void push_back(int x)
    {
        Node * node = new Node(x);
        size++;

        if (tail == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void pop_front()
    {
        if (head == NULL)
            cout << -1 << endl;
        else
        {
            size--;

            if (size == 0)
            {
                cout << head->val << endl;
                head = NULL;
                tail = NULL;
                return;
            }

            int val = head->val;
            cout << val << endl;
            Node * org = head;
            head = head->next;
            head->prev = NULL;
            delete(org);
        }
    }

    void pop_back()
    {
        if (tail == NULL)
            cout << -1 << endl;
        else
        {
            size--;

            if (size == 0)
            {
                cout << tail->val << endl;
                head = NULL;
                tail = NULL;
                return;
            }

            int val = tail->val;
            cout << val << endl;
            Node * org = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete(org);
        }
    }

    void getSize()
    {
        cout << size << endl;
    }

    void isEmpty()
    {
        if (size == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    void front()
    {
        if (head == NULL)
            cout << -1 << endl;
        else
            cout << head->val << endl;
    }

    void back()
    {
        if (tail == NULL)
            cout << -1 << endl;
        else
            cout << tail->val << endl;
    }

    void print()
    {
        Node * n = head;
        while (n != NULL)
        {
            cout << n->val << " ";
            n = n->next;
        }
        cout << endl;
    }
};

int main()
{
    MyDeque * dq = new MyDeque();

    int n; cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string cmd; cin >> cmd;
        int x;

        // get x only when these commands are called 
        if (cmd == "push_back" || cmd == "push_front")
            cin >> x;

        if (cmd == "push_back")
            dq -> push_back(x);
        else if (cmd == "push_front")
            dq -> push_front(x);
        else if (cmd == "pop_back")
            dq -> pop_back();
        else if (cmd == "pop_front")
            dq -> pop_front();
        else if (cmd == "size")
            dq -> getSize();
        else if (cmd == "empty")
            dq -> isEmpty();
        else if (cmd == "front")
            dq -> front();
        else if (cmd == "back")
            dq -> back();


        // cout << "command was " << cmd << endl;
        // cout << "done!" << endl;

        // dq -> print();
    }
}