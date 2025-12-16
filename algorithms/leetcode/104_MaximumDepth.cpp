#include <iostream>

struct TreeNode {
    int val{};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
    explicit TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {}
};

int maximumDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftNode = maximumDepth(root->left); 
    int rightNode = maximumDepth(root->right); 

    return 1 + (leftNode > rightNode ? leftNode : rightNode);
}

int main() {
    std::cout << maximumDepth;

    return 0;
}