//wap to perform basic primitive operation of circular  queue using array in c

#include <stdio.h>
#include <stdlib.h>
#define maxsize 3

struct queue
{
    int cqueue[maxsize], front, rear;
} cq;

void enqueue();
void dequeue();
void display();

int main()
{
    int ch = 1;
    cq.front = maxsize-1;
    cq.rear = maxsize-1;

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
    if (cq.front == (cq.rear + 1) % maxsize)
    {
        printf("\n Queue overflow");
        return;
    }
    cq.rear=(cq.rear+1)%maxsize;
    printf("\n Enter new number: ");
    scanf("%d", &no);
    cq.cqueue[cq.rear] = no;
    printf("Element of queue are.\n");
    display();
}

void dequeue()
{
    int no;
    if (cq.front == cq.rear)
    {
        printf("\n Queue underflow");
        return;
    }
    cq.front=(cq.front+1)%maxsize;
    no = cq.cqueue[cq.front];
    printf("\n Dequeued element is %d ", no);
    
    display();
}

void display()
{
    if (cq.front == cq.rear)
    {
        printf("\n Queue is empty\n");
        return;
    }
   
    printf("\nQueue elements are: ");
    for (int T = (cq.front+1)%maxsize; T!= cq.rear; T=(T+1)%maxsize)
    {
        printf("\t%d ", cq.cqueue[T]);
    }
    printf("%d\t", cq.cqueue[cq.rear]);
}
