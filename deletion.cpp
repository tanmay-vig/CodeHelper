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
    node *head, *tail; int sizel;
    linked_list()
    {
        head = NULL; tail = NULL; sizel =0;
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
        sizel = sizel+1;
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
    void deletion(int n)
    {
        node *temp = head , *temp1 = NULL;
        // If index is out of bound
        if ((n > sizel-1)||(n<0))
        {
            cout << "The index is out of bound \n";
        }
        // Deleting from the starting
        if (n==0)
        {
            temp = temp->next;
            head = temp;
        }
        // Deleting from the last
        else if (n==(sizel-1))
        {
            while (temp->next!=NULL)
            {
                temp1= temp;
                temp = temp->next;
            }
            temp1->next = NULL;
            tail = temp1;
        }
        // Deletion at a given place
        int counter = 0;
        while (temp!=NULL)
        {
            counter++;
            if (counter==n)
            {
                temp1->next = temp->next;
                temp = temp1;
            }
            temp1 = temp;
            temp = temp->next;
        }
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
    a.insert(7);   
    cout << "Printing the linked list : \n";
    a.print();
    int n;
    cout << "Enter the index : "; cin >> n;
    a.deletion(n);
    cout << "Printing the linked list after deletion :\n";
    a.print(); 
    return 0;
}
