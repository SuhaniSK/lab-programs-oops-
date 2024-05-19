 #include<iostream>
 using namespace std;
 class Matrix{
    int row,column,a[10][10];
    public:Matrix(int m=0,int n=0):row(m),column(n){}
    void get_matrix(void);
    Matrix operator +(Matrix m2);
    int operator ==(Matrix m2);
    Matrix operator -(Matrix m2);
    friend ostream& operator<<(ostream& out,Matrix& m);
};
void Matrix:: get_matrix(void){
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++){
        cout<<"["<<i<<","<<j<<"]:";
        cin>>a[i][j];}
    }
}
Matrix Matrix:: operator +(Matrix m2){
    Matrix m3(row,column);
    for(int i=0;i<row;i++){
    for(int j=0;j<column;j++)
    {
        m3.a[i][j]=a[i][j]+m2.a[i][j];
    }

}
return m3;
}
Matrix Matrix:: operator -(Matrix m2){
    Matrix m3(row,column);
    for(int i=0;i<row;i++){
    for(int j=0;j<column;j++)
    {
        m3.a[i][j]=a[i][j]-m2.a[i][j];
    }
    }
return m3;
}
 int Matrix::operator ==(Matrix m2){
    if(m2.row==row &&m2.column==column)
    {
        return 1;
    }
    else {
        return 0;
    }

 }
 ostream& operator<<(ostream& out,Matrix& m){
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.column;j++)
        {
            cout<<m.a[i][j]<<"\t";
        }
        printf("\n");
    }
    return out;
 }
 int main(){
    int m,n,p,q;
    cout<<"enter size of matrix 1\n";
    cin>>m>>n;
    Matrix m1(m,n);
    cout<<"enter size of matrix 12\n";
    cin>>p>>q;
    Matrix m2(p,q);
    if(m1==m2)
    {
        cout<<"enter elements for matrix 1:\n"; 
        m1.get_matrix();
        cout<<"enter elements for matrix 2:\n";
        m2.get_matrix();
        Matrix m3(m,n),m4(m,n);
        m3=m1+m2;
        m4=m1-m2;
        cout<<"the sum matrix of \n"<<"m1:"<<m1<<"+ m2:"<<m2<<"\n is:"<<m3<<endl;
        cout<<"the difference matrix of \n"<<"m1:"<<m1<<"\n- m2:"<<m2<<"\n is:"<<m4<<endl;

    }
    else{
        cout<<"not compatible\n";
    }
return 0;
 }









    