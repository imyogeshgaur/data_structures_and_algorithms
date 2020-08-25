#include<iostream>
using namespace std;
struct yogesh 
{ 
    int value;
    yogesh *next;
};

void travere_linked_list(yogesh *head)
{
    yogesh *a = new yogesh();
    a = head;
    do
    {
        cout << a->value << "\n";
        a = a->next;
    } while (a != head);
}

yogesh *insertAtChoice(yogesh *head,int data,int index){
    yogesh *newnode = new yogesh();
    newnode->value=data;

    yogesh *ptr = head->next;
    for(int i=0;i<index-1;i++)
    {
        ptr = ptr->next;
    }
    newnode->next=ptr;
    ptr->next=head;
    return head;
}
int main()
{
    yogesh *first = new yogesh();
    yogesh *second = new yogesh();
    yogesh *third = new yogesh();
    yogesh *fourth = new yogesh();

    first->value = 1;
    first->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = fourth;

    fourth->value = 4;
    fourth->next = first;

    cout << "Linked List before insertion : \n";
    travere_linked_list(first);
    insertAtChoice(first,45,2);
    cout << "Linked List After insertion : \n";
    travere_linked_list(first);
return 0;
}