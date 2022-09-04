// Reversing the linked list 
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class linked_list
{
    public:
    node *head, *tail;
    linked_list()
    {
        head = NULL; tail = NULL;
    }
    void insert(int n)
    {
        node *temp = new node;
        temp->data = n ;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;tail = temp;
        }
        else
        {
            tail->next=temp;
            tail = temp;
        }
    }
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    void reverse()
    {
        node *cur = head , *prev=NULL ,*temp=NULL;
        while (cur!=NULL)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head = prev;
    }
};
int main ()
{
    linked_list a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    cout << "Printing the linked list : \n";
    a.print();
    a.reverse();
    cout << "Reversed array : \n";
    a.print();
    return 0;
}