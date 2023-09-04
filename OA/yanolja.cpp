#include <bits/stdc++.h>

using namespace std;

// Tree Node structure
typedef struct TreeNode{
    TreeNode * left;
    TreeNode * right;
    int val;

    TreeNode(int v) : val(v) {}
}TreeNode;


/*
    BUILD TREE  
*/
int arr[32] = {-1, 1, 2, 3, 0, 4, 5, 6, 0, 0, 0, 0, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0};

void construct(TreeNode * curr, int ind)
{
    if (ind >= 32) return;
    int l = 2*ind;
    int r = 2*ind + 1;

    // only dive in when left and right is not 0
    if (arr[l] != 0)
        curr->left = new TreeNode(arr[l]);
    if (arr[r] != 0)
        curr->right = new TreeNode(arr[r]);

    if (arr[l] != 0) construct(curr->left, l);
    if (arr[r] != 0) construct(curr->right, r);
}

TreeNode * init()
{
    TreeNode * head = new TreeNode(arr[1]);
    construct(head, 1);
    return head;
}


/*
    TEST TREE
*/
void printInorder(TreeNode * node)
{
    if (node == NULL)
    {
        return;
    }

    // First recur on left child
    printInorder(node->left);

    // Then print the data of node
    cout << node->val << " ";

    // Now recur on right child
    printInorder(node->right);
}

void printPreorder(TreeNode * node)
{
    if (node == NULL)
        return;

    // First print data of node
    cout << node->val << " ";

    // Then recur on left subtree
    printPreorder(node->left);

    // Now recur on right subtree
    printPreorder(node->right);
}

void printPostorder(TreeNode * node)
{
    if (node == NULL)
        return;


    printPostorder(node->left);

    printPostorder(node->right);

    cout << node->val << " ";

}


/*
    Here START ALGORITHM!!
*/

int getPerfectHeight(TreeNode * node)
{
    // Base Case when node is NULL -> height is 0
    if (node == NULL) return 0;

    // otherwise, perfect height is smaller side + 1
    return min(getPerfectHeight(node->left), getPerfectHeight(node->right)) + 1;
}

// given that head is not NULL, maximum Height is at least 1
int maximumHeight = 1;

void dfs(TreeNode * curr)
{
    if (curr == NULL) return;
    maximumHeight = max(maximumHeight, getPerfectHeight(curr));
    dfs(curr->left);
    dfs(curr->right);
}

int getPerfectSize()
{
    return pow(2, maximumHeight) - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TreeNode * head = init();

    // cout << "\n";
    // printInorder(head);
    // cout << "\n";
    // printPreorder(head);
    // cout << "\n";
    // printPostorder(head);
    // cout << "\n";

    dfs(head);
    cout << getPerfectSize();
}