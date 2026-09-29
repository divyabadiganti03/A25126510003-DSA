#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
/* Create a new node */
struct Node *createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
/* Insert at beginning */
void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    printf("Element inserted\n");
}
/* Insert at end */
void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    printf("Element inserted\n");
}
/* Insert after a given key */
void insertAfter(int key, int value)
{
    struct Node *temp;
    struct Node *newNode;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    do
    {
        if (temp->data == key)
        {
            newNode = createNode(value);
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            if (temp == tail)
                tail = newNode;
            printf("Element inserted\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Key not found\n");
}
/* Delete a value */
void deleteValue(int value)
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    do
    {
        if (temp->data == value)
        {
            /* Only one node */
            if (head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                if (temp == tail)
                    tail = temp->prev;
            }
            free(temp);
            printf("Element deleted\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Element not found\n");
}
/* Search for a value */
void searchValue(int value)
{
    struct Node *temp;
    int position = 1;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    do
    {
        if (temp->data == value)
        {
            printf("Element found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    printf("Element not found\n");
}
/* Display forward */
void displayForward()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Forward: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
/* Display backward */
void displayBackward()
{
    struct Node *temp;
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = tail;
    printf("Backward: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}
/* Main function */
int main()
{
    int choice, value, key;
    while (1)
    {
        printf("\n----- CIRCULAR DOUBLY LINKED LIST -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after key\n");
        printf("4. Delete value\n");
        printf("5. Search value\n");
        printf("6. Display forward\n");
        printf("7. Display backward\n");
        printf("8. Exit\n");
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
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfter(key, value);
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
                displayForward();
                break;
            case 7:
                displayBackward();
                break;
            case 8:
                printf("Program terminated\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
