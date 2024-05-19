#include<iostream>
#include<string.h>
using namespace std;
class publication{
    public:
    string title;
    publication(){
    title="IEEEOOP";
    }
    void print(){
        cout<<"the tiltle:"<<title<<endl;
    }


};
class book:public publication{
    public:float an;
    book(){
    an=687.3;
    }
    void print(){
        publication::print();
        cout<<"the accession number; "<<an<<endl;
        
    }
};
class mag:public publication{
    public :int vol;
    mag(){vol=1;}
void print(){
    cout<<"the volume is :"<<vol<<endl;
}};
class journal:public mag,book{
public:
void print(){
    
    book::print();
    mag::print();
    }
};
int main()
{
    journal IEE;
    IEE.print();
    return 0;
}