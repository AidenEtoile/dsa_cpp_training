#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void printInOrder(TreeNode* node) {
    // 1. Base Case: If the node is completely empty, stop and go back up!
    if (node == nullptr) {
        return;
    }

    // 2. Magic Step 1: Recursively travel down the left branch
    printInOrder( node->left );

    // 3. Magic Step 2: Print the current node's data
    std::cout << node->data << " ";

    // 4. Magic Step 3: Recursively travel down the right branch
    printInOrder( node->right );
}

int main(){
    TreeNode* left_node = new TreeNode{5, nullptr, nullptr};
    TreeNode* right_node = new TreeNode{15};
    TreeNode* root = new TreeNode{10, left_node, right_node};

    printInOrder(root);
    std::cout << std::endl;
}