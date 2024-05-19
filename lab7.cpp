#include<iostream>
using namespace std;
class date{
    int dd,mm,yy;
    public:void read(){
        cin>>dd>>mm>>yy;
    }
    int operator-(date);
    date operator+(int);
    friend ostream& operator <<(ostream& out,date& d);
};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int date ::operator-(date d2){
    date res;
    int nod,noly=0,temp=d2.yy;
    for(temp;temp<yy;temp++)
    if(temp%4==0)
    noly++;
    /*temp=yy;
    for(temp;temp>d2.yy;temp--)
    if(temp%4==0)
    no1y++;
    */
    res.dd=dd-d2.dd;
    if(res.dd<0)
    {
        res.dd=dd+a[mm];
        res.mm=mm--;
    }
    res.mm=mm-d2.mm;
    if(res.mm<0)
    {
        res.mm=mm+12;
        res.yy=yy--;
    }
    res.yy=yy-d2.yy;
    if(res.yy<0)
    return -1;
    nod=res.dd+(res.yy*365);
    int months=d2.mm;
    for(int i=1;i<=res.mm;i++)
    nod+=a[months++];
    nod+=noly;
    return nod;
}
date date::operator+(int ndays){
    date d;
    d.dd=dd;d.mm=mm;d.yy=yy;
    for(int i=1;i<=ndays;i++){
        d.dd++;
        if(d.yy%4==0){
        if(d.dd>b[d.mm]){
            d.dd=1;
            d.mm++;
        }
    }
    else{
        if(d.dd>a[d.mm]){
            d.dd=1;
            d.mm++;
        }
    }
    if(d.mm>12){
        d.mm=1;
        d.yy++;
    }
}
return d;
}
ostream& operator<<(ostream& out, date& d) {
    out << d.dd << "/" << d.mm << "/" << d.yy;
    return out;
}

int main() {
    date d1, d2;
    int ndays;

    cout << "Enter two dates, where Date 1 should be greater than Date 2:\n";
    cout << "Enter DATE 1 (dd mm yyyy): ";
    d1.read();
    cout << "Enter DATE 2 (dd mm yyyy): ";
    d2.read();

    int difference = d1 - d2;
    cout << "In DATE 1 (" << d1 << ") and DATE 2 (" << d2 << "), the number of days between them is => " << difference << endl;

    cout << "Enter the number of days to be added to DATE 1: ";
    cin >> ndays;

    date result_date = d1 + ndays;
    cout << "DATE 1 after adding " << ndays << " days:\n" << result_date << endl;

    return 0;
}
/*
#include<iostream>
using namespace std;
class date{
    int dd,mm,yy;
    public:void getdate(){
        cin>>dd>>mm>>yy;
    }
    date operator+(int ndays);
    int operator-(date d2);
    friend ostream& operator<<(ostream& out,date& d);
};
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
ostream& operator<<(ostream& out,date& d){
    out<<d.dd<<"/"<<d.mm<<"/"<<d.yy;
    return out;
 }
 date date::operator+(int ndays){
date res;
res.dd=dd;res.mm=mm;res.yy=yy;
for(int i=1;i<=ndays;i++){
    res.dd++;
    if(yy%4==4){
        if(res.dd>b[res.mm]){
            res.dd=1;
            res.mm++;
        }
    }
    else{
        if(res.dd>a[res.mm]){
            res.dd=1;
            res.mm++;
        }
    }
    if(res.mm>12){
        res.mm=1;
        res.yy++;
    }
}
return res;
 }
 int date::operator-(date d2){
    int nod,temp,noly;
    date res;
    temp=d2.yy;
    for(temp;temp<=yy;temp++){
    if(temp%4==0){
      noly++;
    }
 }
 res.dd=dd-d2.dd;
 if(res.dd<0){
    res.dd=dd+a[mm];
    res.mm=mm--;
 }
 res.mm=mm-d2.mm;
 if(res.mm<0){
    res.mm=mm+12;
    res.yy=yy--;
 }
 res.yy=yy-d2.yy;
 if(res.yy<0){
    return -1;
 }
 nod=res.dd+365*(res.yy);
 nod+=noly;
 int months=d2.mm;
 for(int i=1;i<=res.mm;i++){
    nod+=a[months++];
 }
 return nod;
 }
 
 int main(){
    date d1,d2,d3;
    int daystoadd,ndays;
    cout<<"enter date 1(dd/mm/yyyy) which has to be greater than date 2:\n";
    d1.getdate();
     cout<<"enter date (dd/mm/yyyy)\n";
    d2.getdate();
    ndays=d1-d2;
    cout<<"the number of days between date 1 ("<<d1<<") and date 2 ("<<d2<<") is:"<<ndays<<"days\n";
    cout<<"enter number of days to add to date 1\n";
    cin>>daystoadd;
    d3=d1+daystoadd;
    cout<<"the resultant date after adding "<<daystoadd<<"days is:"<<d3<<endl;
    return 0;
 }
*/