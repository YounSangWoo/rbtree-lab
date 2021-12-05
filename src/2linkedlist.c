#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *nextNode;
}node;

node *CreateNode(int data);
node *insert_Node(node *Current, int data);
void delete_node(node *delete, node *head);
void PrintNodeFrom(node *from);

int main()
{
    node *node1 = CreateNode(100);
    node *node2 = insert_Node(node1, 200);
    node *node3 = insert_Node(node2, 300);
    node *node4 = insert_Node(node2, 400);

    PrintNodeFrom(node1);
    return 0;
}



node *CreateNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

//insert_Node is for after Current node
node *insert_Node(node *Current, int data)
{
    // 'after' node is the next node which for current node
    node *after = Current->nextNode;
    // create new node
    node *newNode = malloc(sizeof(node));

    // input the value to newNode
    newNode->data = data;
    newNode->nextNode = after;

    Current->nextNode = newNode;

    return newNode;
}

void delete_node(node *delete, node *head)
{
    node *next = head;
    if (delete == head)
    {
        free(delete);
        return;
    }

    // end here if next node is NULL
    while (next)
    {
        if (next->nextNode == delete)
        {
            next->nextNode = delete->nextNode;
        }
        next = next->nextNode;
    }
    free(delete);
}

void PrintNodeFrom(node *from)
{
    while (from)
    {
        printf("노드의 데이터:%d \n", from->data);
        from = from->nextNode;
    }
}