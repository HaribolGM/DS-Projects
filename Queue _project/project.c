#include <stdio.h>
#include <stdlib.h>
#define max 100
int stack[max], top = -1;
int pop()
{
    return stack[top--];
}
void push(int x)
{
    if (top == max - 1)
    {
        printf("\nStack is Full");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void enqueue(int x)
{
    push(x);
}
void display()
{
    int i;
    printf("\nThe elements in queue :");
    for (i = 0; i <= top; i++)
    {
        printf("\n%d", stack[i]);
    }
}

int dequeue()
{
    int data, res;
    if (top == -1)
    {
        printf("\nQueue is Empty");
    }
    else if (top == 0)
        return pop();
    data = pop();
    res = dequeue();
    push(data);
    return res;
}
int main()
{
    int choice, n, i, data, t;

    printf("\t**IMPLEMENTATION OF QUEUE USING STACK**");
    do
    {
        printf("\n\n1. Enqueue\n2. Dequeue \n3. Display \n4. Exit");
        printf("\n\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of elements :");
            scanf("%d", &n);
            printf("\nEnter %d elements :", n);
            i = 0;
            while (i < n)
            {
                scanf("%d", &data);
                enqueue(data);
                i++;
            }
            break;
        case 2:
            t = dequeue();
            printf("\nDeleted element :%d", t);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (choice != 0);

    return 0;
}