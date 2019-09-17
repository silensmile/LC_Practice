#include<iostream>
#include<vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> ansi;


    return ans;
    //if (root == NULL)
    //    return false;
    //if (root->val == sum&&root->left == nullptr&&root->right == nullptr)
    //    return true;
    //return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}