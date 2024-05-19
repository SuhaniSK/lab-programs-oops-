#include<iostream>
using namespace std;
template<class t>
void customswap(t& x,t& y){
    t temp;
    temp=x;
    x=y;
    y=temp;
}
template<class t1>
void quick(t1 a[],int low,int high){
    t1 key;
    int i,j;
      int flag=0;
    if(low<high){
    i=low+1;
    j=high; 
    key=a[low];
    while(!flag){
        while((a[i]<=key)&&(i<high)){
            i++;
        }
        while(a[j]>key){
            j--;
        }
        if(i<j){
            customswap(a[i],a[j]);
        }
        else{
            flag=1;
        }
    }
    customswap(a[low],a[j]);
    quick(a,low,high-1);
    quick(a,low+1,high);
    }
    return;
}
int main(){
    int i,n,choice,a[30];
    double b[30];
    do{
        cout<<"menu\n1.quick sort for integers\n2.quick sort for doubles\n3.exit\nenter your choice\n ";
        cin>>choice;
        switch(choice){
            case 1:cout<<"enter number of integer elements:\n";
            cin>>n;
            cout<<"enter "<<n<<" integer elements:\n";
            for ( i = 0; i <n; i++)
            {
                cin>>a[i];
                /* code */
            }
            quick(a,0,n-1);
            cout<<"the sorted order:\n";
            for(i=0;i<n;i++){
                 cout<<a[i]<<"\t";
            }
            cout<<endl;
        break;
        case 2:cout<<"enter number of double elements:\n";
            cin>>n;
            cout<<"enter "<<n<<" doubles elements:\n";
            for ( i = 0; i <n; i++)
            {
                cin>>b[i];
                /* code */
            }
            quick(b,0,n-1);
            cout<<"the sorted order:\n";
            for(i=0;i<n;i++){
                 cout<<b[i]<<"\t";
            }
            cout<<endl;
        break;
        case 3:cout<<"exiting the program\n";
        break;
        }
        }while(choice!=3);
        return 0;
}