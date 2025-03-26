/*
start:14:30
end:14:55
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 항상느끼지만 초기화에 신경써야한다. 진짜! 초기화를 안해서 여러번 틀렸다.
그리고 변수를 재활용하지말자 그냥 새거만들어서 명확한 풀이를 만드는게 중요하다.
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
    int maxCnt=1;
    int depth[10001];//항상 초기화에 신경쓰자!!!!
    void solve(TreeNode* node, int cnt){ 
        if(node == NULL) return;
        maxCnt= max(maxCnt,cnt);
        depth[cnt]+= node->val;
        solve(node->right,cnt+1);
        solve(node->left,cnt+1);
    }
    int maxLevelSum(TreeNode* node) {
        depth[1]= node->val;
        solve(node->right,2);
        solve(node->left,2);
        int answer= depth[1];
        int answerCnt=1;
        for(int i=2;i<=maxCnt;i++){
        if(answer<depth[i]){answerCnt=i; answer= depth[i];}
        }
        return answerCnt;
    }

};
