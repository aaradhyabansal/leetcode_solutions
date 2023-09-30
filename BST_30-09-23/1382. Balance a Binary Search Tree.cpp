/*Given the root of a binary search tree, return a balanced binary search tree with the same node values.
 If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

*/

/*Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105*/

//sol1 unoptimised approach ,occupies extra space complexity and time complexity due to finding and storing inorder

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

    void findInorder(TreeNode*root,vector<int>& inorder)
    {
        if(root==NULL)
        return;

        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
    TreeNode* BSTusingInorder(vector<int>& inorder,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }

        int mid=(s+e)/2;
        int element=inorder[mid];
        TreeNode* root=new TreeNode(element);
        root->left=BSTusingInorder(inorder,s,mid-1);
        root->right=BSTusingInorder(inorder,mid+1,e);
        
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        findInorder(root,inorder);
        for(int i=0;i<inorder.size();i++)
        {
            cout<<inorder[i]<<endl;
        }
        return BSTusingInorder(inorder,0,inorder.size()-1);

    }
};