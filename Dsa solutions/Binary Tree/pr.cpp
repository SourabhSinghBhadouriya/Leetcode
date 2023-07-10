#include <iostream>
#include <unordered_set>
#include <vector>
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
int main() {
    int n; 
    cin>>n; // taking size of vector from user
    int a;
    vector<int> v;
    // we can also mention size here like
    // vector<int> v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    return 0;
}