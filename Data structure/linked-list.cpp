#include <iostream>
#include <malloc.h>

typedef struct node
{
    int data;
    node * next;
}node;

//输入任意位置链表节点指针n，在尾部添加数据i，返回尾部指针
node * node_append(node * n, int i)
{
    node * now = n;
    while (now->next!=NULL) //查找尾节点
    {
        now = now->next;
    }
    now->next = (node *) malloc(sizeof(node));
    now = now->next;
    now->data = i;

    return now;
}

//在链表n开头添加数据i，返回第一个节点的指针
node * node_add_start(node * n, int i)
{
    node * now = (node *) malloc(sizeof(node));
    now->data = i;
    now->next = n;
    
    return now;
}

//在链表节点n后插入新节点，储存数据i，返回插入节点指针
node * node_insert(node * n, int i)
{
    node * now = (node *) malloc(sizeof(node));
    now->next = n->next; //迁移节点指针
    n->next = now;
    now->data = i;

    return now;
}

//从链表节点n开始搜索数据i，成功返回节点指针，失败返回NULL
node * node_search(node * n, int i)
{
    node * now = n;
    while (now->next!=NULL||now->data!=i) //查找尾节点
    {
        now = now->next;
    }

    if (now->next==NULL)
    {
        return NULL;
    }else if (now->data==i)
    {
        return now;
    }
    return NULL;
}

int main()
{
    return 0;
}
