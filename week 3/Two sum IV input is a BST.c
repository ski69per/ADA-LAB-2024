/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int m[100001];
int top = -1;

void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        m[++top] = root->val;
        inorder(root->right);
    }
}

bool findTarget(struct TreeNode* root, int k) {
    
    top=-1;
    inorder(root);
    int l = 0;
    int r = top;
    int sum;
   
    while (l < r) {
        sum = m[l] + m[r];
        if (sum == k)
            return true;
        else if (sum > k)
            r -= 1;
        else if (sum < k)
            l += 1;
       
    }
     return false;
}
