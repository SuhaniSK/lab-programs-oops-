#include<iostream>
using namespace std;
class employee{
char emp_name[20],emp_id[20];
float basic,da,it,gsal,net_sal;
public:void getdata();
void netsal();
void display();
};
void employee::getdata(){
    cout<<"enter employee id:\n";
    cin>>emp_id;
    cout<<"enter employee name:\n";
    cin>>emp_name;
    cout<<"enter employess basic salary:\n";
    cin>>basic;
}
void employee::netsal(){
    da=.52*basic;
    gsal=da+basic;
    it=.3*gsal;
    net_sal=gsal-it;
}
void employee::display(){
    cout<<"\nemployee id:"<<emp_id<<"\nemployee name:"<<emp_name<<"\nemployee net salary:"<<net_sal<<endl;
}
int main(){
    int i,n;
    cout<<"enter number of employees:\n";
    cin>>n;
    employee e[n];
    for(i=0;i<n;i++){
        e[i].getdata();
        e[i].netsal();
    }
    for(i=0;i<n;i++){
        e[i].display();
    }
    return 0;
}