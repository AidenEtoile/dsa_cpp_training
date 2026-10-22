#include <iostream>

struct Node{
    int data;
    Node* next;
};

// The while-loop traversal without a tail pointer.
void insertAtEnd(Node*& head, int value){
    
    Node* new_node = new Node{value, nullptr};

    if(head==nullptr){
        head = new_node;
        return;
    }

    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }

    current->next = new_node;
}

// The conditional deletion inside a loop using current and previous.
void deleteMultiples(Node*& head, int v1, int v2){
    
    Node* current = head;
    Node* previous = nullptr;

    while(current != nullptr){
        if(current->data % v1 == 0 || current->data % v2 == 0){
            Node* to_delete = current;

            if(previous == nullptr){
                current=current->next;
                head = current;
                delete to_delete;
            } else {
                previous->next = current->next;
                current = current->next;
                delete to_delete;
            }

        } else {

            previous = current;
            current = current->next;
        }
    }
}

// The 3-pointer "juggling" technique (prev, current, nextNode).
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while(current != nullptr){
        nextNode = current->next;
        current->next = prev;

        prev = current;
        current = nextNode;
    }

    head = prev;
}

//Printing f-tion:
void printList(Node* head){

    Node* current = head;

    while(current!=nullptr){
        std::cout << "[" << current->data << "]-->";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int main(){
    Node* node_4 = new Node{444, nullptr};
    Node* node_3 = new Node{333, node_4};
    Node* node_2 = new Node{222, node_3};
    Node* node_1 = new Node{111, node_2};

    Node* head = node_1;

    std::cout << "Original list: ";
    printList(head);

    insertAtEnd(head, 555);
    std::cout << "List after insertion: ";
    printList(head);

    deleteMultiples(head, 12, 9);
    std::cout << "The List after deleting multiples of 12 & 9:" << std::endl;
    printList(head);

    reverseList(head);
    std::cout << "The List after reversing:" << std::endl;
    printList(head);
}
