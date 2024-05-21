#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rotateRight(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node *rotateLeft(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void menu()
{
    printf("AVL Tree Menu:\n");
    printf("\t1. Insert Element\n");
    printf("\t2. Inorder Traversal\n");
    printf("\t3. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    struct Node *root = NULL;
    int choice, data;

    do
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Inorder traversal of AVL tree is: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
