#include <bits/stdc++.h>

using namespace std;

typedef pair<char, char> children;      // struct to store left and right children
children tree[30];                      // arr to represent children of each alphabet node
int n;                                  // total num of nodes

int charToInt(const char c)             // function to change character to int (for tree array index)
{
    return c - 'A';
}

void printTree()        
{
    for (int i = 0; i < n; i++)
    {
        cout << "parent : " << (char) (i + 'A') << endl;
        cout << "left : " << tree[i].first << endl;
        cout << "right : " << tree[i].second << endl;
        cout << endl;
    }
}


void preOrder(int curr)
{
    // 1. print current
    cout << (char) (curr + 'A');

    char left = tree[curr].first;
    char right = tree[curr].second;

    // 2. go to left
    if (left != '.')
        preOrder(charToInt(left));
    
    // 3. go to right
    if (right != '.')
        preOrder(charToInt(right));
}

void inOrder(int curr)
{
    char left = tree[curr].first;
    char right = tree[curr].second;

    // 1. go to left
    if (left != '.')
        inOrder(charToInt(left));
    
    // 2. print current
    cout << (char) (curr + 'A');

    // 3. go to right
    if (right != '.')
        inOrder(charToInt(right));
}

void postOrder(int curr)
{
    char left = tree[curr].first;
    char right = tree[curr].second;

    // 1. go to left
    if (left != '.')
        postOrder(charToInt(left));

    // 2. go to right
    if (right != '.')
        postOrder(charToInt(right));

    // 3. print current
    cout << (char) (curr + 'A');
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char parent; cin >> parent;
        char left, right;
        cin >> left >> right;

        children child = make_pair(left, right);

        int parentInd = charToInt(parent);
        tree[parentInd] = child;
    }

    // INPUT DONE

    // printTree();
    // return 0;



    preOrder(0);
    cout << endl;
    inOrder(0);
    cout << endl;
    postOrder(0);
    
}
