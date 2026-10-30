#include <iostream>

struct BinaryTree{
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

BinaryTree* insert(BinaryTree* tree, int value){
    if (tree == nullptr){
        return new BinaryTree{value, nullptr, nullptr};
    }

    if(value < tree->data){
        tree->left = insert(tree->left, value);
    }
    else if(value > tree->data){
        tree->right = insert(tree->right, value);
    }

    return tree;
}

void printInOrder(BinaryTree* root){
    if(root == nullptr){
        return;
    }

    printInOrder(root->left);
    std::cout<<root->data<<" ";

    printInOrder(root->right);
}

int main(){
    BinaryTree* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);

    std::cout<<"Printed In Order: ";
    printInOrder(root);
    std::cout<<std::endl;
}