// wap to perform basic primitive operation of stack

#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

struct stack
{
    int stack[maxsize], top;
} st;

void push();
void pop();
void display();
int main()
{
    int ch = 1;
    st.top = -1;
    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Terminate");
     printf("\nEnter your choice : ");
scanf("%d", &ch);



        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
void push()
{
    int no;
    if (st.top == maxsize - 1)
    {
        printf("\n Stack overflow");
        return;
    }
    st.top++;
    printf("\n Enter new number: ");
    scanf("%d", &no);
    st.stack[st.top] = no;
    printf("Element pushed to stack.\n");
    display();
}

void pop()
{
    int no;
    if (st.top == -1)
    {
        printf("\n Stack underflow");
        return;
    }
    no = st.stack[st.top];
    printf("\n Popped element is %d ", no);
    st.top--;
    display();
}

void display()
{
    if (st.top == -1)
    {
        printf("\n Stack is empty\n");
        return;
    }
    printf("\nStack elements are: ");
    for (int i = st.top; i >= 0; i--)
    {
        printf("\t%d ", st.stack[i]);
    }
    printf("\n");
}