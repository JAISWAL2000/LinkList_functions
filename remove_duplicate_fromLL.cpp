using namespace std;
#include<iostream>
struct Node
{
    int data;
    struct Node *next;
};

/* WAP to remove duplicate element from Linklist
1.while i=head to NULL
2.While j =i to NULL
3.if found node -> next happend again remove it.
*/
Node* getNode(int data)
{

    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printlinklist(Node* head)
{
    int counter =1;
 while(head!=NULL)
    {   cout<<counter++<<". ";
        cout<<head->data<<"\n";
        head = head->next;
    }

}void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main()

{
    int temp;
    int c,data;
    cout<<"Enter the number of node \n";
    cin>>c;
    c--;
    Node *head = new Node();
    cout<<"enter the node \n";
    cin>>data;
    head = getNode(data);
    Node *curr = head;
    Node* temp1 = NULL;
    while(c--)
    {
        cin>>data;
        temp1 = getNode(data);
        curr -> next = temp1;
        curr = temp1;

    }
    printlinklist(head);

    removeDuplicates(head);
    cout<<"Linklist after removing duplicate elements\n";
    printlinklist(head);
    return 0;
}
