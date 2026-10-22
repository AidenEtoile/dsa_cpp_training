#include <iostream>
struct Node{
    int data;
    Node* next;
};

// Return the exact middle node in a single pass.
Node* getMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Floyd's Algorithm to return true if the fast pointer laps the slow pointer.
bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast) return true;
    }
    return false;
}

void print_list(Node* head){
    Node* current = head;
    int counter = 0;
    while(current!=nullptr){
        if(counter>0 && current==head){
            std::cout << std::endl;
            return;
        } 
        std::cout <<"["<<current->data<<"]-->";
        current = current->next;
        counter++;
    }
    std::cout<<"NULL"<<std::endl;
}

int main(){
    //Testing returning the exact middle node in a single pass.
    Node* node_1 = new Node();
    Node* node_2 = new Node();
    Node* node_3 = new Node();

    node_1->data = 111;
    node_1->next = node_2;

    node_2->data = 222;
    node_2->next = node_3;

    node_3->data = 333;

    Node* head_1 = node_1;
    Node* to_display = getMiddle(head_1);
    std::cout << "Middle Node : {" << to_display->data << ", " << to_display->next << "}" << std::endl;

    std::cout << "The list is : ";
    print_list(head_1);
   
    //Testing Floyd's Algorithm to return true if the fast pointer laps the slow pointer.
    Node* nd_3 = new Node{3, nullptr};
    Node* nd_2 = new Node{2, nd_3};
    Node* nd_1 = new Node{1, nd_2};
    nd_3->next = nd_1;

    Node* head_2 = nd_1;

    std::cout << "The circular list: ";
    print_list(head_2);

    std::cout << "Is it circular? - "<< (hasCycle(head_2)? "true" : "false") <<std::endl;
}