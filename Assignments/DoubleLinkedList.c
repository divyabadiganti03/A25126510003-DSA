#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Insert at beginning
void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at beginning.\n", value);
}
// Insert at end
void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at end.\n", value);
}
// Insert after a particular key
void insertAfterKey(int key, int value)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("%d inserted after %d.\n", value, key);
}
// Delete a node by value
void deleteValue(int value)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d not found in the list.\n", value);
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("%d deleted from the list.\n", value);
}
// Search for a value
void searchValue(int value)
{
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("%d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in the list.\n", value);
}
// Display the list in forward direction
void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Display the list in reverse direction
void displayReverse()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Reverse list: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
// Main function
int main()
{
    int choice, value, key;
    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a key\n");
        printf("4. Delete value\n");
        printf("5. Search value\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfterKey(key, value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchValue(value);
                break;
            case 6:
                display();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
