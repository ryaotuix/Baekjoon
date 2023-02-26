#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string key;
    int value;
    int n; // (counts)
    Node *left = NULL;
    Node *right = NULL;

    Node(string k, int v, int count);
    void printNode();
};

Node::Node(string k, int v, int count)
{
    key = k;
    value = v;
    n = count;
}

void Node::printNode()
{
    cout << "key: " << key << " value: " << value << " n: " << n << endl;
}

class BST
{
public:
    Node *root = NULL;

    // Constructor
    BST(Node *r) { root = r; }
    BST(){};

    //  DIFFERENT TRAVERSALS
    void inOrder(Node *mid)
    {
        if (mid == NULL)
        {
            cout << "it's null";
            return;
        }

        if (mid->left != NULL) // left
            inOrder(mid->left);

        mid->printNode(); // root

        if (mid->right != NULL) // right
            inOrder(mid->right);
    }

    void preOrder(Node *mid)
    {
        if (mid == NULL)
            return;

        mid->printNode(); // root

        if (mid->left != NULL) // left
            preOrder(mid->left);
        if (mid->right != NULL) // right
            preOrder(mid->right);
    }

    void postOrder(Node *mid)
    {
        if (mid == NULL)
            return;

        if (mid->left != NULL) // left
            postOrder(mid->left);
        if (mid->right != NULL) // right
            postOrder(mid->right);
        mid->printNode(); // root
    }

    // FIND
    int get(Node *x, string key)
    {
        if (x == NULL)
            return NULL;
        if (key < x->key)
            return get(x->left, key);
        else if (key > x->key)
            return get(x->right, key);
        else
            return x->value;
    }

    // FIND MAX
    Node * findMax()
    {
        Node * curr = this->root;
        if (curr == NULL)
        {
            cout << "Root is NULL\n";
            return NULL;
        }

        while (curr != NULL && curr->right != NULL)
        {
            curr = curr->right;
        }
        
        cout << "MAX NODE : ";
        curr->printNode();
        return curr;
    }

    // FIND MIN
    Node * findMin()
    {
        Node * curr = this->root;
        if (curr == NULL)
        {
            cout << "Root is NULL\n";
            return NULL;
        }

        while (curr != NULL && curr->left != NULL)
        {
            curr = curr->left;
        }
        
        cout << "MIN NODE : ";
        curr->printNode();
        return curr;
    }
 
    // INSERTION
    Node * insert(Node *x, string key, int val)
    {
        if (this->root == NULL)
        {
            root = new Node(key, val, 1);
            return root;
        }

        if (x==NULL) return new Node(key, val, 1);
        if (key < x->key)
        {
            x->left = insert(x->left, key, val);
            return x;
        }
        else if (key > x->key)
        {
            x->right = insert(x->right, key, val);
            return x;
        }
        else
        {
            x->value = val;
            return x;
        }
        x->n = x->left->n + x->right->n + 1;
        return x;
    }

    // DELETE
};

int main()
{
    // Node * a = new Node ("a", 1 , 1);
    // Node * b = new Node ("b", 2, 1);
    // Node * c = new Node ("c", 3, 1);
    // Node * d = new Node ("d", 4, 1);
    // Node * e = new Node ("e", 5, 1);
    // Node * f = new Node ("f", 6, 1);
    // Node * g = new Node ("g", 7, 1);
    // Node * h = new Node ("h", 8, 1);

    // d->left = b;
    // b->left = a;
    // b->right = c;
    // d->right = f;
    // f->left = e;
    // f->right = g;
    // g->right = h;

    BST bst;
    bst.insert(bst.root, "d", 4);

    bst.insert(bst.root, "a", 1);
    bst.insert(bst.root, "b", 2);
    bst.insert(bst.root, "c", 3);
    bst.insert(bst.root, "e", 5);
    bst.insert(bst.root, "f", 6);
    bst.insert(bst.root, "g", 7);
    bst.insert(bst.root, "h", 8);

    bst.findMax();
    bst.findMin();

    bst.inOrder(bst.root);
    // bst.preOrder(bst.root);
    // bst.postOrder(bst.root);
    // int res = bst->get(bst->root, "f");
}
