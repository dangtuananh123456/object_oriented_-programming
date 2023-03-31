#include<iostream>
using namespace std;

class SoPhuc{
    private:
        int thuc, ao;
    public:
        SoPhuc();
        SoPhuc(int t, int a);
        SoPhuc operator + (const  int&);
        friend SoPhuc operator + (const int&, const SoPhuc&);
        friend ostream& operator << (ostream&, const SoPhuc&);
};

SoPhuc::SoPhuc(){
    thuc = ao = 0;
}
SoPhuc::SoPhuc(int t, int a){
    thuc = t;
    ao = a;
}
SoPhuc SoPhuc::operator + (const  int& a){
    SoPhuc temp = *this;
    temp.thuc += a;
    return temp;
}

SoPhuc operator + (const int& a, const SoPhuc& s){
    SoPhuc tem;
    tem.thuc = a + s.thuc;
    tem.ao = s.ao;
    return tem; 
}
ostream& operator << (ostream& out, const SoPhuc& s){
    out << s.thuc << "+" <<s.ao << "i";
    return out; 
}
int main(){
    SoPhuc sp1(3, 5);
    SoPhuc sp2 = sp1.operator+(10);
    SoPhuc sp3  = sp1 + 10;
    SoPhuc  sp4 = 10 + sp1;
    cout << sp1 << endl << sp2 << endl << sp3 << endl << sp4 << endl;
    system("pause");
}