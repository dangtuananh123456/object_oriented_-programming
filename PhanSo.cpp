#include<iostream>
using namespace std;
#include<fstream>
#include<vector>

class ArrPhanSo;

class PhanSo{
    private:   
        int tu, mau;
    public:
        PhanSo(){
            this->tu = 0;
            this->mau = 1;
        }
        friend ostream& operator << (ostream& out, const PhanSo& x);
        friend istream& operator >> (istream& in, PhanSo& x);
        void setTu(int x){tu = x;}
        void setMau(int x){mau = x;}
        void Simply();
        bool operator > (const PhanSo& x);
        PhanSo& operator = (const PhanSo& x);
        bool operator != (const PhanSo& x);
        PhanSo operator + (const PhanSo& x);
        PhanSo operator - (const PhanSo& x);
        PhanSo operator * (const PhanSo& x);
        PhanSo operator / (const PhanSo& x);
        friend class ArrPhanSo;
};

bool PhanSo::operator > (const PhanSo& x){
    return tu * x.mau > mau * x.tu; 
}

bool PhanSo::operator != (const PhanSo& x){
    PhanSo tem = *this - x;
    return tem.tu != 0;  
}

ostream& operator << (ostream& out, const PhanSo& x){
    out << x.tu << "/" << x.mau;
    return out;
}
istream& operator >> (istream& in, PhanSo& x){
    cout << "nhap tu: "; in >> x.tu;
    cout <<"nhap mau: "; in >> x.mau;
    return in;
}

PhanSo& PhanSo::operator = (const PhanSo& x){
    tu = x.tu;
    mau = x.mau;
    return *this;
}

int ucln(int a, int b){
    if(b == 0) return a;
    return ucln(a, a%b);
}

int bcnn(int a, int b){
    return a*b/ucln(a, b);
}

void PhanSo::Simply(){
    int tem = ucln(tu, mau);
    tu = tu/tem;
    mau = mau/tem;
}

PhanSo PhanSo::operator + (const PhanSo& x){
    int tem = bcnn(mau, x.mau);
    PhanSo kq;
    kq.tu = tu*tem/mau + x.tu * tem/x.mau;
    kq.mau = tem;
    return kq;
}
PhanSo PhanSo::operator - (const PhanSo& x){
    int tem = bcnn(mau, x.mau);
    PhanSo kq;
    kq.tu = tu*tem/mau - x.tu * tem/x.mau;
    kq.mau = tem;
    return kq;
}
PhanSo PhanSo::operator * (const PhanSo& x){
    PhanSo kq;
    kq.tu = tu * x.tu;
    kq.mau = mau * x.mau;
    kq.Simply();
    return kq;
}
PhanSo PhanSo::operator / (const PhanSo& x){
    PhanSo tem;
    tem.tu = tu * x.mau;
    tem.mau = mau* x.tu;
    tem.Simply();
    return tem;
}

class ArrPhanSo{
    private:
        PhanSo* List;
        int sizeOflist;
    public:
        ArrPhanSo(){
            List = NULL;
            sizeOflist = 0;
        }
        friend ostream& operator << (ostream& out, ArrPhanSo& x);
        friend istream& operator >> (istream& in, ArrPhanSo& x);
        friend fstream& operator >> (fstream& file, ArrPhanSo& x);
        void Sort();
        PhanSo& operator [] (int i){
            return List[i];
        }
        PhanSo CalSum();
};

ostream& operator << (ostream& out, ArrPhanSo& x){
    for(int i = 0; i < x.sizeOflist; i++){
        out << x[i] << " ";
    }
    return out;
}

istream& operator >> (istream& in, ArrPhanSo& x){
    cout << "nhap so luong phan tu cua mang: ";
    int n; in >> n;
    x.sizeOflist = n;
    x.List = new PhanSo[n];
    cout << "nhap cac phan tu cua mang:\n";
    for(int i = 0; i < n; i++){
        in >> x.List[i];
    }
    return in;
}
void ArrPhanSo::Sort(){
    for(int i = 0; i < sizeOflist - 1; i++){
        PhanSo min = List[i];
        int index = i;
        for(int j = i + 1; j < sizeOflist; j++){
            if(min > List[j]){ min = List[j]; index = j;}
        }
        if(min != List[i]) {swap(List[i], List[index]);}
    }
}

PhanSo ArrPhanSo::CalSum(){
    PhanSo result;
    for(int i = 0; i < sizeOflist; i++){
        result = result + List[i];
    }
    return result;
}

fstream& operator >> (fstream& file, ArrPhanSo& x){
    vector<PhanSo> v;
    PhanSo var;
    while(!file.eof()){
        int x;
        file >> x;var.setTu(x);
        //char ch; file >> ch;
        file.seekg(1, ios_base::cur);
        file >> x;
        var.setMau(x);
        v.push_back(var);
    }

    for(auto it : v) cout << it << "  ";

    x.sizeOflist = v.size();
    x.List = new PhanSo[x.sizeOflist];
    for(int i = 0; i < x.sizeOflist; i++){
        x[i] = v[i];
    }
    return file;
}

int main(){
    ArrPhanSo arr;
    fstream file_outin("ghimangphanso.txt");
    file_outin >> arr;
    cout << arr;
    file_outin.close();
    system("pause");
}

//4 1 2 3 2 5 6 7 3

