#include <bits/stdc++.h>

using namespace std;

// template <class T>
// class queue
// {
//   public:
//     queue( const queue &);                // copy ctor
//     queue& operator=( const queue& q);   // assignment operator
//   //...
// }; 
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

queue<TreeNode *> q1;
queue<TreeNode *> q2;

queue<int> res1;
queue<int> res2;

 bool isSameTree(TreeNode* p, TreeNode* q) {
        q1.push(p);
        q2.push(q);
        // add it to q1
        while (!q1.empty())
        {
            TreeNode * curr = q1.front(); q1.pop();
            res1.push(curr->val);

            if (curr->left != nullptr)
                {
                    q1.push(curr->left);
                    res1.push(-1);
                }
            if (curr->right != nullptr)
                {
                    q1.push(curr->right);
                    res1.push(-2);
                }
        }

        // add it to q2
        while (!q2.empty())
        {
            TreeNode * curr = q2.front(); q2.pop();
            res2.push(curr->val);

            if (curr->left != nullptr)
            {
                q2.push(curr->left);
                res2.push(-1);
            }
            if (curr->right != nullptr)
            {
                q2.push(curr->right);
                res2.push(-2);
            }   
        }

        queue<int> temp1 (res1);
        queue<int> temp2 (res2);
        while (!temp1.empty())
        {
            cout << temp1.front() << " ";
            temp1.pop();
        }
        cout << endl;
        while (!temp2.empty())
        {
            cout << temp2.front() << " ";
            temp2.pop();
        }
        cout << endl;


        if (res1.size() != res2.size()) return false;
        while (!res1.empty())
        {
            int one = res1.front(); res1.pop();
            int two = res2.front(); res2.pop();
            if (one != two) return false;
        }
        return true;

    }
 
int main()
{
    
    TreeNode * pL = new TreeNode(2);
    TreeNode * pR = new TreeNode(3);
    TreeNode * p = new TreeNode(1, pL, pR);

    TreeNode * qL = new TreeNode(2);
    TreeNode * qR = new TreeNode(3);
    TreeNode * q = new TreeNode(1, qL, qR);

    
    cout << p->val << " " << p->left->val << " " << p->right->val;
    cout << endl;
    cout << q->val << " " << q->left->val << " " << q->right->val;
    cout << endl << endl;

    cout << isSameTree(p, q);

}


recursion answer could be done