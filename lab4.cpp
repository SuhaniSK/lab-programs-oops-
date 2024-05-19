#include<iostream>
using namespace std;
struct list{
    int data;
    struct list *next;
};
typedef struct list node;
class linkedlist{
    node *first;
    public:linkedlist(void){
        first=NULL;
    }
    void insertnode(int ele);
    void delnode();
    void display();
};
void linkedlist::insertnode(int ele){
    node *newnode=new node;
    newnode->next=first;
    newnode->data=ele;
    first=newnode;
}
void linkedlist:: delnode(){
    node *temp=first;
    if(first==NULL){
     cout<<"the linked list is empty\n";
    }
    else{
        cout<<"the elemnt deleted is:"<<first->data<<endl;
        first=first->next;
        delete temp;
    }
}
void linkedlist::display(){
    if(first==NULL){
    cout<<"the linked list is empty\n";
}
else{
    cout<<"the contents in the linked list are:\n";
    node *temp=first;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
}
int main(){
    int ele,choice;
    linkedlist obj;
    do{
        cout<<"menu\n1.insert\n2.delete\n3.display\n4.exit\nenter your choice:\n";
        cin>>choice;
        switch(choice){
            case 1:cout<<"enter element to insert:\n";
            cin>>ele;
            obj.insertnode(ele);
            break;
            case 2:obj.delnode();
            break;
            case 3:obj.display();
            break;
            case 4:cout<<"exiting the program\n";
            break;
            default:cout<<"enter valid choice\n";
            break;
            }
    }while(choice!=4);
    return 0;
}