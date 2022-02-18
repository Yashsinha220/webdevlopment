#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int _data, node *_next)
    {
        this->data = _data;
        this->next = _next; // creating the constrructor for the data entry
    }
    node(int _data)
    {
        this->data = _data;
        this->next = NULL;
    }
};

void insertionatstart(node *&head, int data) // this will return the first point
{
    // node *temp= new node(data, head);
    // return temp;
    // or
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
void insertionatlast(node *&head, int data)
{
    // creating the new pointer
    node *p = head;              // for the track
    node *temp = new node(data); // for the insertion
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;    // pointiong the p to the temp
    temp->next = NULL; // pointing the temp to the null
}
void printlinkedlist(node *&head) // passing the refrence
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertmiddle(node *ptr, int data)
{
    node *temp = new node(data);
    temp->next = ptr->next; // first pointing the next of the temp to the ptr next
    ptr->next = temp;       // pointing the ptr to the temp
}
void insertatposition(int position, int data, node *head)
{
    node *p = head;
    int count = 1;
    while (count < position - 1)
    {
        p = p->next;
        count++;
    }
    node *nodetoinsert = new node(data);
    nodetoinsert->next = p->next;
    p->next = nodetoinsert;
}
int main()
{
    node *head = new node(13); // creating the node for the implementaion of the linked list
    node *second = new node(12);
    head->next = second;
    second->next = nullptr;

    printlinkedlist(head);
    cout << endl;
    insertionatstart(head, 11);
    insertionatstart(head, 123);
    printlinkedlist(head);
    cout << endl;
    insertionatlast(head, 780);
    insertionatlast(head, 1238);
    printlinkedlist(head);
    cout << endl;
    insertmiddle(second, 678);
    printlinkedlist(head);
    cout << endl;
    insertatposition(3, 900, head);
    printlinkedlist(head);

    return 0;
}