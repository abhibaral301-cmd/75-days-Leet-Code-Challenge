
class Solution {
public:
    int count = 0;

    pair<int,int> postOrder(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);

        int nodesum = left.first + right.first + root->val;
        int nodecount = left.second + right.second + 1;

        if(root->val == nodesum/(nodecount)){
            count++;
        }

        return{nodesum, nodecount};
    }

    int averageOfSubtree(TreeNode* root){
        postOrder(root);
        return count;
    }
        
    
};