/*
start:14:55
end:15:01
시간복잡도:O(N)
공간복잡도:O(lgN)
풀이: 간단한 문제였다. 재귀로 쉽게풀수 있었음.
*/
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
    int totalDepth;
    int values[101];
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        solve(root, 1);
        for(int i=1;i<=totalDepth;i++){
            answer.push_back(values[i]);
        }
        return answer;
    }
    void solve(TreeNode*root, int depth){
        if(root==NULL)return;
        totalDepth= max(totalDepth,depth);
        solve(root->left, depth+1);
        values[depth]= root->val;
        solve(root->right, depth+1);
    }
};
