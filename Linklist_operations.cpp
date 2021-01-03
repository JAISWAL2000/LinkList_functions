#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
//create a new node

Node* getNode(int data)
{

    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// APpend an element at the end
Node* append_attend(int data,Node *head)
{
    Node* app_tail = head;
    while(app_tail->next)
    {

        app_tail = app_tail ->next;
    }
    app_tail ->next = getNode(data);
    return head;
}

//Print the data of the linklist
void printlinklist(Node* head)
{
 while(head!=NULL)
    {
        cout<<head->data<<"\n";
        head = head->next;
    }

}
// Delete a node
Node *delete_node(int d ,Node *head)
{
    while(head->next != NULL)
    {
        if((head->next)->data == d)
        {
            if(head ->next ->next == NULL)
            {
                head->next =NULL;
            }
            else
            {
                head->next = head ->next->next;
            }
        }
        head = head ->next;
    }
    return head;
}
int main()
{
    Node* head = NULL,*temp =NULL;
    int data;
    cout<<"enter the value of Head node \n";
    cin>>data;
    head = getNode(data);
    int c;
    cout<<"Enter the number of node \n";
    cin>>c;

    Node *curr = head;
    while(c--)
    {
        cin>>data;
        temp = getNode(data);
        curr -> next = temp;
        curr = temp;

    }

    printlinklist(head);
    cout<<"Enter the data you want to append at the last \n";
    cin>>data;
    head =  append_attend(data,head);
    cout<<"After appending value "<<data<<"\n";
    printlinklist(head);
    cout<<"Enter the data you want to delete \n";
    cin>>data;
    head = delete_node(data,head);
    printlinklist(head);


    return 0;
}
