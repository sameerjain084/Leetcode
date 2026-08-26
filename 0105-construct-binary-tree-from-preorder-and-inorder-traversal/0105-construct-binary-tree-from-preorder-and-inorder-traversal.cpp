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
    int search(vector<int>& inorder, int left , int right, int val){
        for(int i =left ; i<= right; i++){
            if(inorder[i]== val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int& preIdx, int left, int right){
          if(left>right){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIdx]);
        

        int inIdx = search(inorder , left , right , preorder[preIdx]);
        preIdx++;
        root->left = helper(preorder , inorder , preIdx , left , inIdx-1);
        root->right = helper(preorder , inorder , preIdx , inIdx+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx , 0, inorder.size()-1);
        
    }// tc is o(n^2) in future use map to solve this problem in o(n) tc instead of search we can store the value in map
};

// // class Solution {
// public:
//     unordered_map<int, int> mp;

//     TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
//                      int& preIdx, int left, int right) {

//         if (left > right) {
//             return NULL;
//         }

//         // Create root
//         TreeNode* root = new TreeNode(preorder[preIdx]);
//         preIdx++;

//         // Get root index in inorder in O(1)
//         int inIdx = mp[root->val];

//         // Build left subtree
//         root->left = helper(preorder, inorder, preIdx,
//                             left, inIdx - 1);

//         // Build right subtree
//         root->right = helper(preorder, inorder, preIdx,
//                              inIdx + 1, right);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

//         // Store inorder element and its index
//         for (int i = 0; i < inorder.size(); i++) {
//             mp[inorder[i]] = i;
//         }

//         int preIdx = 0;

//         return helper(preorder, inorder, preIdx,
//                       0, inorder.size() - 1);
//     }
// };// tc with o(n);