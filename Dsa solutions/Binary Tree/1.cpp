// Lecture 1 & 2
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
// size of tree
int size(TreeNode *root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
}
// height of tree
int height(TreeNode *root)
{
    return root == NULL ? -1 : max(height(root->left), height(root->right)) + 1;
}
// maximum value of tree
int maximum(TreeNode *root)
{
    return root == NULL ? -(int)1e9 : max(root->val, max(maximum(root->left), maximum(root->right)));
}
// minimum value of tree
int minimum(TreeNode *root)
{
    return root == NULL ? (int)1e9 : min(root->val, min(minimum(root->left), minimum(root->right)));
}
// finding an element in tree
bool find(TreeNode *root, int data)
{
    if (root == NULL)
        return false;

    if (root->val == data)
        return true;

    return find(root->left, data) || find(root->right, data);
}
// NodeToRoot Path
bool nodeToRootPath_(TreeNode *root, int data, vector<TreeNode *> &ans)
{

    if (root == NULL)
        return false;

    if (root->val == data)
    {
        ans.push_back(root);
        return true;
    }

    // if (nodeToRootPath_(root->left, data, ans))
    // {
    //     ans.push_back(root);
    //     return true;
    // }

    // if (nodeToRootPath_(root->right, data, ans))
    // {
    //     ans.push_back(root);
    //     return true;
    // }

    // return false;

    bool res = nodeToRootPath_(root->left, data, ans) || nodeToRootPath_(root->right, data, ans);

    if (res)
        ans.push_back(root);
    return res;
}
// NodeToRoot Path
vector<TreeNode *> nodeToRootPath_(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return {};
    }

    if (root->val == data)
    {
        return {root};
    }

    vector<TreeNode *> left = nodeToRootPath_(root->left, data);
    if (left.size() != 0)
    {
        left.push_back(root);
        return left;
    }

    vector<TreeNode *> right = nodeToRootPath_(root->right, data);
    if (right.size() != 0)
    {
        right.push_back(root);
        return right;
    }

    return {};
}
// NodeToRoot Path
vector<TreeNode *> nodeToRootPath(TreeNode *root, int data)
{
    return nodeToRootPath_(root, data);
}
// rootToAllLeafPath
void rootToAllLeafPath(TreeNode *root, vector<vector<int>> &ans, vector<int> &smallAns)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        smallAns.push_back(root->val);
        ans.push_back(smallAns);
        smallAns.pop_back();

        return;
    }

    smallAns.push_back(root->val);
    rootToAllLeafPath(root->left, ans, smallAns);
    rootToAllLeafPath(root->right, ans, smallAns);
    smallAns.pop_back();
}
//rootToAllLeafPath
vector<vector<int>> rootToAllLeafPath(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<int> smallAns;
    
    rootToAllLeafPath(root, ans, smallAns);
    return ans;
}
//exactlyOneChild
void exactlyOneChild(TreeNode* root, vector<int> &ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->left == NULL || root->right == NULL) {
            ans.push_back(root->val);
        }

        exactlyOneChild(root->left, ans);
        exactlyOneChild(root->right, ans);
    }

     vector<int> exactlyOneChild(TreeNode* root) {
        vector<int> ans;
        exactlyOneChild(root);
        return ans;
    }
//exactlyOneChild
    int countExactlyOneChild(TreeNode* node) {
        if (node == NULL || (node->left == NULL && node->right == NULL))
            return 0;

        int leftSinglechildCount = countExactlyOneChild(node->left);
        int rightSinglechildCount = countExactlyOneChild(node->right);

        int ans = leftSinglechildCount + rightSinglechildCount;
        if (node->left == NULL || node->right == NULL)
            ans++;

        return ans;
    }

   //kdown function to give all values below that node at distance k
    void kdown(TreeNode* root, int k, TreeNode* block, vector<int> &ans) {
        if (root == NULL || k < 0 || root == block)
            return;

        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        kdown(root->left, k - 1, block, ans);
        kdown(root->right, k - 1, block, ans);
    }
// distanceK
    int distanceK(TreeNode* root, TreeNode* target, int k,vector<int> &ans ) {
        if (root == NULL)
            return -1;

        if (root == target) {
            kdown(root, k, NULL, ans);
            return 1;
        }

        int ld = distanceK(root->left, target, k, ans);
        if (ld != -1) {
            kdown(root, k - ld, root->left, ans);
            return ld + 1;
        }

        int rd = distanceK(root->right, target, k, ans);
        if (rd != -1) {
            kdown(root, k - rd, root->right, ans);
            return rd + 1;
        }

        return -1;
    }
//distanceK
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<TreeNode*> path;
        nodeToRootPath_(root, target->val, path);

        vector<int> ans ;
        TreeNode* block = NULL;
        for (int i = 0; i < path.size(); i++) {
            kdown(path[i], k - i, block, ans);
            block = path[i];
        }
    }
    // Burning tree
      void burningTreeNode(TreeNode* root, int time, TreeNode* blockNode, vector<vector<int>> &ans) {
        if (root == NULL || root == blockNode)
            return;
        if (time == ans.size()) 
        ans.push_back({});
            
        ans[time].push_back(root->val);

        burningTreeNode(root->left, time + 1, blockNode, ans);
        burningTreeNode(root->right, time + 1, blockNode, ans);

    }

    int burningTree_(TreeNode* root, int fireNode, vector<vector<int>> &ans) {
        if (root == NULL)
            return -1;
        if (root->val == fireNode) {
            burningTreeNode(root, 0, NULL, ans);
            return 1;
        }

        int lt = burningTree_(root->left, fireNode, ans);
        if (lt != -1) {
            burningTreeNode(root, lt, root->left, ans);
            return lt + 1;
        }

        int rt = burningTree_(root->right, fireNode, ans);
        if (rt != -1) {
            burningTreeNode(root, rt, root->right, ans);
            return rt + 1;
        }

        return -1;
    }

    void burningTree(TreeNode* root, int data) {
        vector<vector<int>> ans;
        burningTree_(root, data, ans);
    }

    // Node with water and fire.
    void burningTreeNodeWithWater(TreeNode *root, int time, TreeNode *blockNode, unordered_set<int> &waterSet, vector<vector<int>> &ans)
{
    if (root == NULL || root == blockNode || waterSet.find(root->val) != waterSet.end())
        return;
    if (time == ans.size()) // if(time == ans.size()) ans.push_back({});
        ans.push_back({});
    ans[time].push_back(root->val);

    burningTreeNodeWithWater(root->left, time + 1, blockNode, waterSet, ans);
    burningTreeNodeWithWater(root->right, time + 1, blockNode, waterSet, ans);
}

int burningTreeWithWater(TreeNode *root, int fireNode, unordered_set<int> &waterSet,  vector<vector<int>> ans)
{
    if (root == NULL)
        return -1;
    if (root->val == fireNode)
    {
        if (waterSet.find(root->val) == waterSet.end())
        { // for cpp : map.find(root->val) != map.end();
            burningTreeNodeWithWater(root, 0, NULL, waterSet, ans);
            return 1;
        }
        return -2; // fire node is present but it have water.
    }

    int lt = burningTreeWithWater(root->left, fireNode, waterSet, ans);
    if (lt > 0)
    {
        if (waterSet.find(root->val) == waterSet.end())
        {
            burningTreeNodeWithWater(root, lt, root->left, waterSet, ans);
            return lt + 1;
        }
        return -2; // fire node is present but it have water.
    }

    if (lt == -2)
        return -2;

    int rt = burningTreeWithWater(root->right, fireNode, waterSet, ans);
    if (rt > 0)
    {
        if (waterSet.find(root->val) == waterSet.end())
        {
            burningTreeNodeWithWater(root, rt, root->right, waterSet, ans);
            return rt + 1;
        }
        return -2; // fire node is present but it have water.
    }
    if (rt == -2)
        return -2;

    return -1;
}

void burningTreeWithWater(TreeNode *root, int data)
{
    unordered_set<int> waterSet;
    vector<vector<int>> ans;

    burningTreeWithWater(root, data, waterSet, ans);
    for (vector<int> &ar : ans)
    {
        for (int ele : ar)
            cout << ele << " ";
        cout << endl;
    }
}

//lowestCommonAncestor
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> list1, list2;
    nodeToRootPath_(root, p->val, list1);
    nodeToRootPath_(root, q->val, list2);

    int i = list1.size() - 1, j = list2.size() - 1;
    TreeNode *LCA = NULL;

    while (i >= 0 && j >= 0)
    {
        if (list1[i] != list2[j])
            break;

        LCA = list1[i];
        i--;
        j--;
    }

    return LCA;
}

bool LCA(TreeNode *root, TreeNode *p, TreeNode *q,TreeNode* &LCANode)
{
    if (root == NULL)
        return false;
    bool selfPresent = (root == p || root == q);

    bool leftPresent = LCA(root->left, p, q,LCANode);
    if (LCANode != NULL)
        return true;

    bool rightPresent = LCA(root->right, p, q,LCANode);
    if (LCANode != NULL)
        return true;

    if ((leftPresent && rightPresent) || (leftPresent && selfPresent) || (rightPresent && selfPresent))
        LCANode = root;

    return leftPresent || rightPresent || selfPresent;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *LCANode = NULL;
    LCA(root, p, q,LCANode);
    return LCANode;
}

int main()
{
    return 0;
}
