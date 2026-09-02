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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {

            // Case 1: No left subtree
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }

            // Case 2: Left subtree exists
            else {
                // Find inorder predecessor
                TreeNode* IP = curr->left;

                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                // Create thread
                if (IP->right == NULL) {
                    IP->right = curr;
                    curr = curr->left;
                }

                // Remove thread
                else {
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};