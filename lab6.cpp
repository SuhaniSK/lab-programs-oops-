#include<iostream>
using namespace std;
class stack{
    int a[10],top,size;
    public:stack(int n){
        top=-1;
        size=n;
    }
    friend ostream& operator<<(ostream& out,stack& s);
    friend stack operator +(stack s1,int ele);
    friend stack operator --(stack s);
    friend int  isempty(stack s);
    friend int isfull(stack s);
};
ostream& operator<<(ostream& out,stack& s){
    if(isempty(s)){out<<"the stack is empty,popped from stack\n";
        }
        else{
    out<<"the elements in the stack are:\n";
    for(int i=0;i<=s.top;i++){
    out<<s.a[i]<<"\t";
    }
    out<<endl;
   
}
 return out;
 }
stack operator +(stack s1,int ele){
    s1.a[++s1.top]=ele;
    return s1;
}
stack operator --(stack s){
    cout<<"the element popped from stack: "<<s.a[s.top--]<<endl;
    return s;
}
int  isempty(stack s){
if(s.top==-1){
    return  1;
}
else
{
    return 0;
}
}
int  isfull(stack s){
if(s.top==s.size-1){
    return  1;
}
else
{
    return 0;
}
}
int main(){
    int choice,size,ele;
    cout<<"enter size of the stack:\n";
    cin>>size;
    stack s(size);
    do{
        cout<<"menu\n1.push\n2.pop\n3.display\n4.exit\nenter your choice:\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
        if(isfull(s)){
            cout<<"the stack is full,cant push\n";
            }
        else{
        cout<<"enter the element to push into stack:\n";
        cin>>ele;
        s=s+ele;
        cout<<s;
        }
            break;
        case 2:if(isempty(s)){
            cout<<"the stack is empty,cant pop from stack\n";
        }
        else{
            s=--s;
            }
        break;
        case 3:cout<<s;
        break;
        case 4:cout<<"exiting the program\n";
        break;
        default:cout<<"invalid choice\n";
            break;
        }
    }while(choice!=4);
    return 0;
}