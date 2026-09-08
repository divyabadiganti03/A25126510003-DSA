#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int roll;
    struct Node *next;
};
struct Node *head = NULL;
void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Student Roll Numbers: ");
    while (temp != NULL)
    {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}
void insertBeginning()
{
    int roll;
    printf("Enter roll number: ");
    scanf("%d", &roll);
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
    printf("Inserted successfully\n");
    display();
}
void insertEnd()
{
    int roll;
    printf("Enter roll number: ");
    scanf("%d", &roll);
    struct Node *newNode;
    struct Node *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted successfully\n");
    display();
}
void search()
{
    int roll;
    struct Node *temp = head;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Roll number %d found\n", roll);
            return;
        }
        temp = temp->next;
    }
    printf("Roll number %d not found\n", roll);
}
void deleteNode()
{
    int roll;
    struct Node *temp = head;
    struct Node *prev = NULL;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->roll == roll)
    {
        head = head->next;
        free(temp);
        printf("Roll number deleted\n");
        display();
        return;
    }
    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Roll number %d not found\n", roll);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Roll number deleted\n");
    display();
}
int main()
{
    int choice;
    do
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search Roll Number\n");
        printf("4. Delete Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insertBeginning();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                search();
                break;
            case 4:
                deleteNode();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Program exited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
