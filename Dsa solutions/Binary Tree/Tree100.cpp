#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val = 0;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int val)
    {
        this->val = val;
    }
};

// 104. Maximum Depth of Binary Tree
int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }

// Path to Given Node(interview bit),, root to node path
vector<int> nodeToRootPath_(TreeNode *root, int data)
{
    if (root == nullptr)
    {
        return {};
    }

    if (root->val == data)
    {
        return {root->val};
    }

    vector<int> left = nodeToRootPath_(root->left, data);
    if (left.size() != 0)
    {
        left.push_back(root->val);
        return left;
    }

    vector<int> right = nodeToRootPath_(root->right, data);
    if (right.size() != 0)
    {
        right.push_back(root->val);
        return right;
    }
    return {};
}
vector<int>solve(TreeNode* A, int B) {
   vector<int> arr;
   if(A == NULL){
       return arr;
   }
   arr = nodeToRootPath_(A,B);
   reverse(arr.begin(),arr.end());
   return arr;
}

// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
TreeNode* getTargetCopy_01(TreeNode* node, TreeNode* target){
        if(node == NULL)return NULL;
        if(node->val == target->val)return node;
        TreeNode* left = getTargetCopy_01(node->left,target);
        if(left != NULL)return left;
        TreeNode* right = getTargetCopy_01(node->right,target);
        if(right !=  NULL)return right;

        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = getTargetCopy_01(cloned,target);
        return ans;
    }

// 938. Range Sum of BST
int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root == NULL){
            return 0;
        }
        int leftsum = rangeSumBST(root->left,low,high);
        int rightsum = rangeSumBST(root->right,low,high);
        if(root->val >= low && root->val <= high){
            return leftsum + rightsum + root->val;
        }
        else{
            return leftsum + rightsum;
        }
    }

// 2236. Root Equals Sum of Children
bool checkTree(TreeNode* root) {
        if(root->val == (root->left->val + root->right->val)){
            return true;
        }
        return false;
    }

// 1469 - Find All The Lonely Nodes
void getLonelyNodes_01(TreeNode *root,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    if(root->left != NULL && root->right == NULL){
        ans.push_back(root->left->val);
    }
    if(root->right != NULL && root->left == NULL){
        ans.push_back(root->right->val);
    }
    getLonelyNodes_01(root->left,ans);
    getLonelyNodes_01(root->right,ans);

}
vector<int> getLonelyNodes(TreeNode * root){
    vector<int> ans;
    getLonelyNodes_01(root,ans);
    return ans;
}
// 1469 - Find All The Lonely Nodes
bool getLonelyNodes_01(TreeNode* node,vector<int> &ans){
    // base case 
    if(node == NULL){
        return false;
    }

    // left recursive call
    bool hasleftchild = getLonelyNodes_01(node->left,ans);
    // right recursive call
    bool hasrightchild = getLonelyNodes_01(node->right,ans);

    if(hasleftchild && !hasrightchild){
        ans.push_back(node->left->val);
    }
    if(hasrightchild && !hasleftchild){
        ans.push_back(node->right->val);
    }
    return true;
}
vector<int> getLonelyNodes(TreeNode* root){
    vector<int> ans;
    getLonelyNodes_01(root,ans);
    return ans;
}

// 700. Search in a Binary Search Tree
TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == val){
            return root;
        }
        TreeNode *left = searchBST(root->left,val);
        if(left != NULL){
            return left;
        }
        TreeNode *right = searchBST(root->right,val);
        if(right != NULL){
            return right;
        }
        return NULL;
    }

TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)return NULL;
        if(root->val == val)return root;
        if(root->val > val){
            return searchBST(root->left,val);
        }
        else{
            return searchBST(root->right,val);
        }
    }

// 226. Invert Binary Tree
TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }

// 111. Minimum Depth of Binary Tree
int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(root->left && root->right){
            return min(left, right) + 1;
        }
        return max(left, right) + 1;
    }

// 112. Path Sum
bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL && targetSum-root->val == 0){
            return true;
        }
        bool left = hasPathSum(root->left,targetSum - root->val);
        bool right = hasPathSum(root->right,targetSum - root->val);

        return left || right;
    }

// 113. Path Sum II
void pathSum_(TreeNode *root, int targetSum, vector<int> &smallAns, vector<vector<int>> &res){
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL){
        if (targetSum - root->val == 0){
            smallAns.push_back(root->val);
            res.push_back(smallAns);
            smallAns.pop_back();
        }
        return;
    }

    smallAns.push_back(root->val);

    pathSum_(root->left, targetSum - root->val, smallAns, res);
    pathSum_(root->right, targetSum - root->val, smallAns, res);

    smallAns.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum){
    vector<vector<int>> res;
    vector<int> smallAns;
    pathSum_(root, targetSum, smallAns, res);
    return res;
    }


