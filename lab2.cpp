#include<iostream>
using namespace std;
class student{
    char usn[20],name[20];
    float m1,m2,m3,avg;
    public:void getdata();
    void display();
};
void student::getdata(){
    cout<<"enter student usn:\n";
    cin>>usn;
    cout<<"enter student name:\n";
    cin>>name;
    cout<<"enter three test marks:\n";
    cin>>m1>>m2>>m3;
}
void student::display(){
    float min;
    if((m1<=m2)&&(m1<=m3)){
        min=m1;
    }
    else if((m2<=m3)&&(m2<=m1)){
        min= m2;
    }
   else{
    min=m3;
}
avg=(m1+m2+m3-min)/2.0;
cout<<"student usn:"<<usn<<"\n student name:"<<name<<"\n avg marks:"<<avg<<endl;
}
int main(){
    int i,n;
    cout<<"enter number of students:\n";
    cin>>n;
    student obj[n];
    for(i=0;i<n;i++){
    obj[i].getdata();
    }
    cout<<"student data\n";
    for(i=0;i<n;i++){
        obj[i].display();
    }
    return 0;

}
