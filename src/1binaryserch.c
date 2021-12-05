#include <stdio.h>
#include <stdlib.h>

typedef char data;
typedef struct Node
{
    char key;
    struct Node *left;
    struct Node *right;

} Node; //위 스트럭트 전체의 이름을 Node라고 부를 수있다.

// 이진트리 함수 만들기
Node *searchBST(Node *root, char x)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->key == x)
            return p;
        else if (p->key < x)
            p = p->right;
        else
            p = p->left;
    }
    return NULL;

} //반환타입 struct Node

Node *insertBST(Node *root, char x)
{
    Node *p = root;
    Node *parent = NULL;
    while (p != NULL)
    {
        parent = p;
        if (p->key == x)
        {
            printf("같은키가 있습니다.\n");
            return p;
        }

        else if (p->key < x)
            p = p->right;
        else
            p = p->left;

    } //탐색 실패

    // 새 노드 할당
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = x;
    newNode->left = newNode->right = NULL;

    // parent의 자식으로 새 노드 붙이기.
    if (parent != NULL)
    {
        if (parent->key < newNode->key)
            parent->right = newNode;
        else
            parent->left = newNode;
    }
    return newNode;
} //반환타입 struct Node*

Node *deleteBST(Node *root, char x)
{
    Node *p = root;
    Node *parent = NULL;
    while ((p != NULL) && (p->key != x))
    {
        parent = p;
        if (p->key < x)
            p = p->right;
        else
            p = p->left;

    } //탐색 실패
    if (p == NULL)
    {
        printf("찾는 노드가 없습니다.");
        return root;
    }
    //차수가 0인 노드의 delete
    if (p->left == NULL && p->right == NULL)
    {
        if (parent == NULL)
            root == NULL;
        else
        {
            if (parent->left == p)
                parent->left == NULL;
            else
                parent->right == NULL;
        }
    }
    else if (p->left == NULL || p->right == NULL)
    {
        //차수가 1인경우
        Node *child = (p->left != NULL) ? p->left : p->right;
        if (parent == NULL)
            root = child;
        else
        {
            if (parent->left == p)
                parent->left == child;
            else
                parent->right == child;
        }
    }
    else
    {
        //차수가 2인경우
        Node *succ_parent = p;
        Node *succ = p->right; //왼쪽 오른쪽 상관없으니 오른쪽으로 선택
        while (p->left != NULL)
        {
            succ_parent = succ;
            succ = succ->left;
        }
        p->key = succ->key;
        if (succ_parent->left == succ)
            succ_parent->left = succ->right;
        else
            succ_parent->right = succ->right;
        p = succ;
    }
    free(p);
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c", root->key);
    
}

int main()
{
    Node *root = insertBST(NULL, 'D');
    insertBST(root, 'I');
    insertBST(root, 'F');
    insertBST(root, 'A');
    insertBST(root, 'G');
    deleteBST(root, 'A');
    inorder(root);
    printf("\n");

    return 0;
}