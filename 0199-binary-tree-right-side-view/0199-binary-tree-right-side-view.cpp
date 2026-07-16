/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int count=0;
vector<int>ans;

void hF(TreeNode* root,int i){
    if(root==NULL)return;
    if(i>count){
        ans.push_back(root->val);
        count=max(count,i);
    }
    hF(root->right,i+1);
    hF(root->left,i+1);
}

    vector<int> rightSideView(TreeNode* root) {
        hF(root,1);
        return ans;
        
    }
};