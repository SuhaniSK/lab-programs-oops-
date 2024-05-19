#include<iostream>
using namespace std;
class complex{
    int real,imag;
    public:void getdata(int a,int b);
    friend ostream& operator<<(ostream& out,complex& c);
    friend complex add(int,complex);
    friend complex add(complex,complex);
};
void complex:: getdata(int a,int b){
    real=a;
    imag=b;
}
ostream& operator<<(ostream& out,complex& c){
    out<<c.real<<"+"<<c.imag<<"i"<<endl;
    return out;
}
complex add(int n,complex c){
    complex result;
    result.real=n+c.real;
    result.imag=c.imag;
    return result;
}
complex add(complex c1,complex c2){
    complex result;
    result.real=c1.real+c2.real;
    result.imag=c1.imag+c2.imag;
    return result;
}
int main(){
    int n1,n2,n;
    complex c1,c2,c3,c4;
    cout<<"enter real and imaginary part for first complex number:\n";
    cin>>n1>>n2;
    c1.getdata(n1,n2);
     cout<<"enter real and imaginary part for second complex number:\n";
    cin>>n1>>n2;
    c2.getdata(n1,n2);
    cout<<"enter the integer part to be addded to the complex number:\n";
    cin>>n;
    c3=add(c1,c2);
    c4=add(n,c1);
    cout<<"the sum of two complex numbers is:\nc1:"<<c1<<"\nc2:"<<c2<<"\n="<<c3<<endl;
    cout<<"the sum of integer and complex number is:\nc1:"<<c1<<"\n+"<<n<<"\n="<<c4<<endl;
    return 0;
}