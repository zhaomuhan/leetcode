#include<iostream>
#include<queue>
using namespace std;

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

void printTree(TreeNode *root)
{ // level order traversal
    queue<TreeNode *> myQueue;
    myQueue.push(root);
    while(!myQueue.empty())
    {
        TreeNode *top = myQueue.front();
        if(top->left) myQueue.push(top->left);
        if(top->right) myQueue.push(top->right);
        cout << top->val;
        myQueue.pop();
    }
}
 
class Solution {
    int maxSoFar = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root->right == nullptr && root->left == nullptr)
        {
            root->val += maxSoFar;
            maxSoFar = root->val;
            return nullptr; // this line easy to forget!
        }
        else if (root->right)
        {
            bstToGst(root->right);
            //maxSoFar = root->right->val;
        }
        root->val += maxSoFar;
        maxSoFar = root->val;
        if(root->left)
        {
            bstToGst(root->left);
            //maxSoFar = root->left->val;
        }
        return root;
    }
};

int main()
{
    TreeNode *left = new TreeNode(5);
    TreeNode *right = new TreeNode(7, new TreeNode(), new TreeNode(8));
    TreeNode *root = new TreeNode(6, left, right);
    printTree(root);
    return 0;
}