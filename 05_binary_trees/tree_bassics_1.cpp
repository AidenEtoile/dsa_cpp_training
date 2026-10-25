#include <iostream>

struct BinaryTree{
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

// The rule is Print -> Left -> Right. 
// This is typically used for making a physical copy of a tree.
void printInOrder(BinaryTree* node){
    if(node == nullptr){
        return;
    }
    printInOrder(node->left);
    std::cout << node->data << " ";

    printInOrder(node->right);
}

// Post-Order Traversal: The rule is Left -> Right -> Print. 
// This is used for safely deleting a tree from memory, 
// because you must destroy the children before you destroy the parent.
void printPostOrder(BinaryTree* node){
    if(node == nullptr) return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->data << " ";
    delete node;
}
int main(){
    BinaryTree* node_27 = new BinaryTree{27};
    BinaryTree* node_26 = new BinaryTree{26, nullptr, node_27};
    BinaryTree* node_25 = new BinaryTree{25};
    BinaryTree* node_22 = new BinaryTree{22, node_25, node_26};
    BinaryTree* node_20 = new BinaryTree{20};
    BinaryTree* node_15 = new BinaryTree{15, node_22, node_20};
    BinaryTree* node_1 = new BinaryTree{1};
    BinaryTree* node_3 = new BinaryTree{3, node_1};
    BinaryTree* node_5 = new BinaryTree{5, nullptr, node_3};

    BinaryTree* root = new BinaryTree{10, node_15, node_5};

    printInOrder(root);
    std::cout << std::endl;

    std::cout << "The root's data: " << root->data << std::endl;

   /* 
     * MEMORY DANGER: Undefined Behavior & Dangling Pointers
     * -----------------------------------------------------
     * The printPostOrder function successfully deletes the memory blocks.
     * However, 'delete' does not erase the pointer variable itself. 
     * The 'root' pointer still holds the old memory address (a dangling pointer).
     * Reading root->data now causes Undefined Behavior, fetching random trash 
     * left by the OS instead of crashing.
     * 
     * INDUSTRY FIX: Always manually clear the pointer after deleting to force 
     * a loud Segmentation Fault (crash) if accidentally accessed later.
     */
    printPostOrder(root);
    //Wrong!
    std::cout << "The root's data: " << root->data << std::endl;

    //Fix:
    root = nullptr; // The pointer is now officially empty
    //Now, the following will cause an exception:
    std::cout << "The root's data: " << root->data << std::endl;
}