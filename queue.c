#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

struct queue
{
    int queue[maxsize], front, rear;
} q;

void enqueue();
void dequeue();
void display();

int main()
{
    int ch = 1;
    q.front = 0;
    q.rear = -1;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Terminate");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            exit(0);
        }
    }
    return 0;
}

void enqueue()
{
    int no;
    if (q.rear == maxsize - 1)
    {
        printf("\n Queue overflow");
        return;
    }
    q.rear++;
    printf("\n Enter new number: ");
    scanf("%d", &no);
    q.queue[q.rear] = no;
    printf("Element of queue are.\n");
    display();
}

void dequeue()
{
    int no;
    if (q.front > q.rear)
    {
        printf("\n Queue underflow");
        return;
    }
    no = q.queue[q.front];
    printf("\n Dequeued element is %d ", no);
    q.front++;
    display();
}

void display()
{
    if (q.front > q.rear)
    {
        printf("\n Queue is empty\n");
        return;
    }
    printf("\nQueue elements are: ");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("\t%d ", q.queue[i]);
    }
    printf("\n");
}
