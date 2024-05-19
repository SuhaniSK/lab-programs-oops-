#include<iostream>
#include<math.h>
using namespace std;
class octal{
int count,oct[10];
public:octal(int x);
int operator+(int k);
friend ostream& operator<<(ostream& out,octal a);
};
octal::octal(int x){
    int rem,i=0,j;
    int a[10];
    while(x!=0)
    {
        rem=x%8;
        a[i++]=rem;
        x=x/8;
    }
    count=i;
    j=count-1;
    for(i=0;i<count;i++)
    {
        oct[i]=a[j];
        j--;
    }

}
int octal::operator+(int k){
    int x=0,j=count-1;
    for(int i=0;i<count;i++)
    {   
        x+=oct[j]*pow(8,i);
        j--;

    }
    return (x+k);
}
ostream& operator<<(ostream& out,octal a)
{
    for(int i=0;i<a.count;i++)
    {
        out<<a.oct[i];
    }
    return out;
}
int main(){
    int x,k;
    cout<<"enter x\n";
    cin>>x;
    octal h=octal(x);
    cout<<"the octal of "<<x<<" is "<<h<<endl;
    cout<<"enter k";   
     cin>>k;
    int y=h+k;
    cout<<"the value of y is "<<y<<endl;
    return 0;
}
/*  
#include<iostream>
#include<math.h>
using namespace std;
class octal{
    int count,oct[10];
    public:octal(int x){
    int a[10],i=0,j,rem;
    while(x!=0){
       rem=x%8;
       a[i++]=rem;
       x=x/8; 
    }
    count=i;
    j=count-1;
    for(int i=0;i<count;i++){
        oct[i]=a[j];
        j--;
    }
    }
    int operator+(int k);
    friend ostream& operator<<(ostream& out,octal& o);
};
int octal::operator+(int k){
    int x=0,j=count-1;
    for(int i=0;i<count;i++){
        x+=oct[j]*pow(8,i);
        j--;
    }
    return x+k;
}
ostream& operator<<(ostream& out,octal& o){
    for(int i=0;i<o.count;i++)
    {
        out<<o.oct[i];
    }
    return out;
}
int main(){
    int x,k;
    cout<<"enter the decimal value of x for octal:\n";
    cin>>x;
    octal h=octal(x);
    cout<<"the octal value for the given decimal is: "<<h<<endl;
    cout<<"enter k (decimal value ) to add:\n";
    cin>>k;
    int y=h+k;
    cout<<"the decimal number when decimal is added to octal number:"<<h<<" + decimal: "<<k<<" is: "<<y<<endl;

    return 0;
}
*/
