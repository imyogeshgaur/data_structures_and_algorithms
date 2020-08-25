#include<iostream>
using namespace std;
struct yogesh 
{ 
    int value;
    yogesh *next;
};

yogesh *insertBeg(yogesh *head,int data){
    yogesh *newnode = new yogesh();
    newnode->value = data;
    
    if(head==NULL){
        newnode->next=newnode;
    }
    else
    {
      yogesh *a = head;
        while(a->next!=head){
              a = a->next;
        }
        newnode->next=a;
        a->next=head;
        return newnode;
    }
    
}

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
    insertBeg(first,34);
    cout << "Linked List After insertion : \n";
    travere_linked_list(first);
    return 0;
}