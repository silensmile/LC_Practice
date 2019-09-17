#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    if (a > b)
        return a + 1;
    else
        return b + 1;
}