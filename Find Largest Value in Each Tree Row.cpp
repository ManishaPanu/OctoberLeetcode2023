class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN;
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                maxi = max(maxi, curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(maxi);
        } 
        return ans;
    }
};
