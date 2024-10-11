#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int x);

struct Node* createNode(int new_data) {
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the
// list
struct Node* insertAtFront(struct Node* head, int new_data) {
  
    // Create a new node with the given data
    struct Node* new_node = createNode(new_data);

    // Make the next of the new node point to the current
    // head
    new_node->next = head;

    // Return the new node as the new head of the list
    return new_node;
}


// Function to insert a new node after a given node
struct Node* insertAfter(struct Node* head, int key,
                         int newData) {
    struct Node* curr = head;

    // Iterate over Linked List to find the key
    while (curr != NULL) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    // If curr becomes NULL means, given key is not found
    if (curr == NULL)
        return head;

    // Allocate new node by given data and point
    // the next of newNode to curr's next &
    // point current next to newNode
    struct Node* newNode = createNode(newData);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Iterative function to insert a new node with value 
// newData before the node with the given key
struct Node* insertBeforeKey(struct Node* head, int key,
                             int newData) {
  
    // Special case: if the key is at the head
    if (head == NULL) {
        return NULL;
    }
    if (head->data == key) {
        struct Node* newNode = createNode(newData);
        newNode->next = head;
        return newNode;
    }

    // Initialize current and previous pointers
    struct Node* curr = head;
    struct Node* prev = NULL;

    // Traverse the list to find the key
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the key was found
    if (curr != NULL) {
        struct Node* newNode = createNode(newData);
        prev->next = newNode;
        newNode->next = curr;
    }

    return head;
}

// Function to insert a node at a specific position in the
// linked list
struct Node* insertAtPosition(struct Node* head,
                              int position, int data) {
    struct Node* newNode = createNode(data);

    // If inserting at the beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL;
         ++i) {
        current = current->next;
    }

    // If the position is out of bounds
    if (current == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function appends a new node at the end and returns the
// head.
struct Node* insertAtEnd(struct Node* head, int new_data)
{
    // Create a new node
    struct Node* new_node = createNode(new_data);

    // If the Linked List is empty, make
    // the new node as the head and return
    if (head == NULL) {
        return new_node;
    }

    // Store the head reference in a temporary variable
    struct Node* last = head;

    // Traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next pointer of the last node
    // to point to the new node
    last->next = new_node;

    // Return the head of the list
    return head;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

int main(){
     int choice =0;  
     struct Node* node;
     struct Node* head
     int new_data,key,newData,position,data;

    while(choice != 8)   
    {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.createnode\n");
        printf("2.insert at front\n");
        printf("3.Insert after\n");
        printf("4.insertBeforeKey\n"); 
        printf("5.insertAtPosition\n");
        printf("6.insertAtEnd\n");
        printf("7.printList\n");
        printf("8.exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            createNode(new_data);      
            break;  
            case 2:  
            insertAtFront(head,new_data);         
            break;  
            case 3:  
            insertAfter(head,key,newData);       
            break;  
            case 4:  
            insertBeforeKey(head,key,newData);       
            break;  
            case 5:  
            insertAtPosition(head,position,data);        
            break;  
            case 6:  
            insertAtEnd(head,new_data);          
            break;  
            case 7:  
            printList(node);         
            break;   
            case 8:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
