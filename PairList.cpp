#include <iostream>

using namespace std;
struct node
{
    int data;
    node* next;
};
struct slist
{
    node* head;
    node* tail;
   
};
void initSlist(slist& l)
{
    l.head = l.tail = NULL;
}
node* createNode(int x)
{
    node* p = new node;
    p->data = x;
    p->next = NULL;
   
    return p;
}
void addTail(slist& l, node* p)
{
    if (p == NULL)
        return;
    else
    {
        if (l.head == NULL)
            l.head = l.tail = p;
        else
        {
            l.tail->next = p;
            l.tail = p;
        }
    }
}
void createList(slist& l)
{
    int n, x;
    cout << "Nhap n: \n";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        node* p = createNode(x);
        addTail(l, p);
    }
}
void printList(slist l)
{
    for (node* k = l.head; k != NULL; k = k->next)
        printf("\t%d", k->data);
}
node* searchX(slist l, int x)
{
    for (node* k = l.head; k != NULL; k = k->next)
    {
        if (k->data == x)
            return k;
    }
    return NULL;
}
void addListTail(slist& l, slist& l2)
{
 
        for (node* k = l2.head; k != NULL; k = k->next)
        {
            addTail(l, k);
        }
    
}
int main()
{
    slist l1,l2;
    initSlist(l1);
    createList(l1);
    printList(l1);
    initSlist(l2);
    createList(l2);
    printList(l2);
    addListTail(l1, l2);
    printList(l1);
    return 0;

}
