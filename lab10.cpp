#include<iostream>
#include<stdlib.h>
using namespace std;
template<class t>
class queue{
t q[100];
int rear;
public:queue(){
    rear=0;
}
void add(t);
void del();
void display();
};
template<class t>
void queue<t> ::add(t ele){
q[++rear]=ele;
}
template<class t>
void queue<t>::del(){
    if(rear==0)
    {
        cout<<"queue is empty,cant delete\n";
    }
    else{
        t ele=q[1];
        for(int i=1;i<=rear;i++)
        q[i]=q[i+1];
        rear--;
        cout<<"the value deleted fro queue is :"<<ele<<endl;
    }
}
template<class t>
void queue<t>::display(){
    if(rear==0)
    {
        cout<<"no contents to display\n";
    }
    else{
        cout<<"the contents in the queue are\n";
        for(int i=1;i<=rear;i++)
        cout<<q[i]<<"\t";
        
    }
}
int main(){
     queue<int> iq;
     queue<double> dq;
     int ch,choice,ele;
     double ele1;
     cout<<"1.int\n 2.doubles\n";
     cin>>ch; 
     do{
        cout<<"\nmenu\n1.insert\n2.delete\nenter your choice";
        cin>>choice;
        switch(choice){
            
            case 1:if(ch==1){
            cout<<"\nenter a int ele to int add\n";
            cin>>ele;
            iq.add(ele);
            iq.display();
            }
            else{
                cout<<"\nenter a double ele to int add\n";
            cin>>ele1;
            dq.add(ele1);
            dq.display();
            }
            break;

            case 2:if(ch==1){
            
            iq.del();
            iq.display();
            }
            else{
            
            dq.del();
            dq.display();}
            break;

        }
     }while(choice<3);
     return 0;
}
 