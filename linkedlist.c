// wap to perform basic operation of singly linear linked list

#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert_begin();
void insert_last();
void insert_pos();
void delete_begin();
void delete_last();
void delete_pos();

struct Node
{
    int data;
    struct Node *next;
};


struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a singly linear linked list
void create()
{
    int data, choice;
    struct Node *newNode, *temp;

    do
    {
        printf("Enter data for the new node: ");
        scanf("%d", &data);
        newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        printf("Do you want to continue adding nodes? (1/0): ");
        scanf("%d", &choice);
    } while (choice != 0);
}

// Function to display the linked list
void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("Linked list elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
void insert_begin()
{
    int data;
    struct Node *newNode;

    printf("Enter data for the new node: ");
    scanf("%d", &data);
    newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning successfully\n");
}

// Function to insert a node at the end of the linked list
void insert_last()
{
    int data;
    struct Node *newNode, *temp;

    printf("Enter data for the new node: ");
    scanf("%d", &data);
    newNode = createNode(data);
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
    printf("Node inserted at the end successfully\n");
}

// Function to insert a node at a specific position in the linked list
void insert_pos()
{
    int data, pos, i;
    struct Node *newNode, *temp;

    printf("Enter position to insert node: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        insert_begin();
        return;
    }
    printf("Enter data for the new node: ");
    scanf("%d", &data);
    newNode = createNode(data);
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d successfully\n", pos);
}

// Function to delete the first node from the linked list
void delete_begin()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning successfully\n");
}

// Function to delete the last node from the linked list
void delete_last()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Node deleted from the end successfully\n");
        return;
    }
    struct Node *second_last = head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
    printf("Node deleted from the end successfully\n");
}

// Function to delete a node from a specific position in the linked list
void delete_pos()
{
    int pos, i;
    struct Node *temp, *prev;

    printf("Enter position to delete node: ");
    scanf("%d", &pos);
    if (pos < 1 || head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    temp = head;
    prev = NULL;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d successfully\n", pos);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nSingly Linear Linked List Operations:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            insert_last();
            break;
        case 5:
            insert_pos();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            delete_last();
            break;
        case 8:
            delete_pos();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}