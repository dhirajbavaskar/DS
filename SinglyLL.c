#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int new_data)
{
    // Allocate memory for a new node
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));

    // Initialize the node's data
    new_node->data = new_data;

    // Set the next pointer to NULL
    new_node->next = NULL;

    // Return the newly created node
    return new_node;
}

// Function to insert a new node at the beginning of the list
struct Node* insertAtFront(struct Node* head, int new_data)
{
    // Create a new node with the given data
    struct Node* new_node = createNode(new_data);

    // Make the next of the new node point to the current
    // head
    new_node->next = head;

    // Return the new node as the new head of the list
    return new_node;
}



// Delete the head node and return the new head
struct Node* deleteHead(struct Node* head) {
  
    // Check if the list is empty
    if (head == NULL)
        return NULL;

    // Store the current head in a 
      // temporary variable
    struct Node* temp = head;

    // Move the head pointer to the next node
    head = head->next;

    // Free the memory of the old head node
    free(temp);

    return head;
}

// Function to remove the last node of the linked list
struct Node* removeLastNode(struct Node* head)
{
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // If the list has only one node, delete it and return
    // NULL
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Find the second last node
    struct Node* second_last = head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    // Delete the last node
    free(second_last->next);

    // Change next of second last
    second_last->next = NULL;

    return head;
}

// Function to delete a node at a given position
struct Node* deleteNode(struct Node* head, int position)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Base case if linked list is empty
    if (temp == NULL)
        return head;

    // Case 1: Head is to be deleted
    if (position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: Node to be deleted is in middle
    // Traverse till given position
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        printf("Data not present\n");
    }

    return head;
}

void printList(struct Node* head)
{
    // Start from the head of the list
    struct Node* curr = head;

    // Traverse the list
    while (curr != NULL) {
        // Print the current node's data
        printf(" %d", curr->data);

        // Move to the next node
        curr = curr->next;
    }

    // Print a newline at the end
    printf("\n");

     while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create the linked list 2->3->4->5
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);

    // Print the original list
    printf("Original Linked List:");
    printList(head);

    // Insert a new node at the front of the list
    printf("After inserting Nodes at the front:");
    int data = 1;
    head = insertAtFront(head, data);


    // Print the updated list
    printList(head);

    int position = 2;
    head = deleteNode(head, position);

    printf("List after deletion: ");
    printList(head);

    // Cleanup remaining nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
