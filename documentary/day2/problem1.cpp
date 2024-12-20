#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* sortedArrayToBSTHelper(const int* nums, int left, int right) {
   
    if (left > right) {
        return nullptr;
    }

    int mid = left + (right - left) / 2;  

    TreeNode* root = new TreeNode(nums[mid]);

    
    root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, right);

    return root;
}


TreeNode* sortedArrayToBST(const int* nums, int size) {
    return sortedArrayToBSTHelper(nums, 0, size - 1);
}

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
   
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);

   
    TreeNode* root = sortedArrayToBST(nums, size);

  
    cout << "Preorder Traversal of the BST: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
