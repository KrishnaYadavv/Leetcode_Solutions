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

vector<vector<int>>temp;

void hF(TreeNode* root,int i,int j){
    if(!root)return;
    temp.push_back({j,i,root->val});
    hF(root->left,i+1,j-1);
    hF(root->right,i+1,j+1);
}


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        hF(root,0,0);
        sort(temp.begin(),temp.end());
        int j=0;
        vector<vector<int>>ans;
        while(j<temp.size()){
            vector<int>arr;
            arr.push_back(temp[j][2]);
            j++;
            while(j<temp.size()&&temp[j][0]==temp[j-1][0]){
                arr.push_back(temp[j][2]);
                j++;
            }
            ans.push_back(arr);
        }
        return ans;
    }
};