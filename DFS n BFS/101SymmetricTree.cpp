#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *first2 = new TreeNode(4);
TreeNode *sec2 = new TreeNode(5);
TreeNode *left1 = new TreeNode(3, first2, sec2);

TreeNode *third2 = new TreeNode(5);
// TreeNode *last2 = new TreeNode(4);
TreeNode *right1 = new TreeNode(3, third2, nullptr);



TreeNode *root = new TreeNode(2, left1, right1);

// Recursively
bool cmp(const TreeNode *a, const TreeNode *b)
{
    // cout << a->val << " " << b->val << endl;

    // base cases
    // i) when both are null
    if (a == nullptr && b == nullptr) return true;
    // when only one is null
    if (a == nullptr || b== nullptr) return false;
    // when they have different values
    if (a->val != b->val) return false;

    // ii) when it is a leaf with same value
    if (a->val == b->val && a->left == nullptr && a->right == nullptr && b->left == nullptr && b->right == nullptr)
        return true;
    else
    {
        return cmp(a->right, b->left) && cmp(a->left, b->right);
    }
}

// bool isSymmetric(TreeNode *root)
// {
//     if (root == nullptr)
//         return true;
//     return cmp(root->left, root->right);
// }

bool isSymmetric(TreeNode * root)
{
    // if root is null ptr
    if (!root)
        return true;

    // two different queues
    queue<TreeNode *> qLeft;    qLeft.push(root->left);
    queue<TreeNode *> qRight;   qRight.push(root->right);

    // iterate it when both Queues are filled with something
    while(!qLeft.empty() && !qRight.empty())
    {
        TreeNode * currL = qLeft.front(); qLeft.pop();
        TreeNode * currR = qRight.front(); qRight.pop();

        // if both are null pointers
        if (currL == nullptr && currR == nullptr)  continue;
        // if only one side is nullptr, it is asymmetric
        if (currL == nullptr || currR == nullptr)   return false;
        // if asymmetric, it is not symmetric
        if (currL->val != currR->val)   return false;

        // Otherwise, we would have to proceed checking
        qLeft.push(currL->left);
        qRight.push(currR->right);
        qLeft.push(currL->right);
        qRight.push(currR->left);

    }

    // when everything is done
    return true;

    
    
}

int main()
{
    cout << isSymmetric(root) << endl;
}