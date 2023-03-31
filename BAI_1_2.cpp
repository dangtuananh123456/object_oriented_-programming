// #include<iostream>
// using namespace std;
// #include<fstream>
// #include<vector>

// class ArrPhanSo;

// class PhanSo{
//     private:   
//         int tu, mau;
//     public:
//         PhanSo(){
//             this->tu = 0;
//             this->mau = 1;
//         }
//         friend ostream& operator << (ostream& out, const PhanSo& x);
//         friend istream& operator >> (istream& in, PhanSo& x);
//         void setTu(int x){tu = x;}
//         void setMau(int x){mau = x;}
//         void Simply();
//         bool operator > (const PhanSo& x);
//         PhanSo& operator = (const PhanSo& x);
//         bool operator != (const PhanSo& x);
//         PhanSo operator + (const PhanSo& x);
//         PhanSo operator - (const PhanSo& x);
//         PhanSo operator * (const PhanSo& x);
//         PhanSo operator / (const PhanSo& x);
//         friend class ArrPhanSo;
// };

// bool PhanSo::operator > (const PhanSo& x){
//     return tu * x.mau > mau * x.tu; 
// }

// bool PhanSo::operator != (const PhanSo& x){
//     PhanSo tem = *this - x;
//     return tem.tu != 0;  
// }

// ostream& operator << (ostream& out, const PhanSo& x){
//     out << x.tu << "/" << x.mau;
//     return out;
// }
// istream& operator >> (istream& in, PhanSo& x){
//     cout << "nhap tu: "; in >> x.tu;
//     cout <<"nhap mau: "; in >> x.mau;
//     return in;
// }

// PhanSo& PhanSo::operator = (const PhanSo& x){
//     tu = x.tu;
//     mau = x.mau;
//     return *this;
// }

// int ucln(int a, int b){
//     if(b == 0) return a;
//     return ucln(a, a%b);
// }

// int bcnn(int a, int b){
//     return a*b/ucln(a, b);
// }

// void PhanSo::Simply(){
//     int tem = ucln(tu, mau);
//     tu = tu/tem;
//     mau = mau/tem;
// }

// PhanSo PhanSo::operator + (const PhanSo& x){
//     int tem = bcnn(mau, x.mau);
//     PhanSo kq;
//     kq.tu = tu*tem/mau + x.tu * tem/x.mau;
//     kq.mau = tem;
//     return kq;
// }
// PhanSo PhanSo::operator - (const PhanSo& x){
//     int tem = bcnn(mau, x.mau);
//     PhanSo kq;
//     kq.tu = tu*tem/mau - x.tu * tem/x.mau;
//     kq.mau = tem;
//     return kq;
// }
// PhanSo PhanSo::operator * (const PhanSo& x){
//     PhanSo kq;
//     kq.tu = tu * x.tu;
//     kq.mau = mau * x.mau;
//     kq.Simply();
//     return kq;
// }
// PhanSo PhanSo::operator / (const PhanSo& x){
//     PhanSo tem;
//     tem.tu = tu * x.mau;
//     tem.mau = mau* x.tu;
//     tem.Simply();
//     return tem;
// }

// class ArrPhanSo{
//     private:
//         PhanSo* List;
//         int sizeOflist;
//     public:
//         ArrPhanSo(){
//             List = NULL;
//             sizeOflist = 0;
//         }
//         friend ostream& operator << (ostream& out, ArrPhanSo& x);
//         friend istream& operator >> (istream& in, ArrPhanSo& x);
//         friend fstream& operator >> (fstream& file, ArrPhanSo& x);
//         void Sort();
//         PhanSo& operator [] (int i){
//             return List[i];
//         }
//         PhanSo CalSum();
// };

// ostream& operator << (ostream& out, ArrPhanSo& x){
//     for(int i = 0; i < x.sizeOflist; i++){
//         out << x[i] << " ";
//     }
//     return out;
// }

// istream& operator >> (istream& in, ArrPhanSo& x){
//     cout << "nhap so luong phan tu cua mang: ";
//     int n; in >> n;
//     x.sizeOflist = n;
//     x.List = new PhanSo[n];
//     cout << "nhap cac phan tu cua mang:\n";
//     for(int i = 0; i < n; i++){
//         in >> x.List[i];
//     }
//     return in;
// }
// void ArrPhanSo::Sort(){
//     for(int i = 0; i < sizeOflist - 1; i++){
//         PhanSo min = List[i];
//         int index = i;
//         for(int j = i + 1; j < sizeOflist; j++){
//             if(min > List[j]){ min = List[j]; index = j;}
//         }
//         if(min != List[i]) {swap(List[i], List[index]);}
//     }
// }

// PhanSo ArrPhanSo::CalSum(){
//     PhanSo result;
//     for(int i = 0; i < sizeOflist; i++){
//         result = result + List[i];
//     }
//     return result;
// }

// fstream& operator >> (fstream& file, ArrPhanSo& x){
//     vector<PhanSo> v;
//     PhanSo var;
//     while(!file.eof()){
//         int x;
//         file >> x;var.setTu(x);
//         //char ch; file >> ch;
//         file.seekg(1, ios_base::cur);
//         file >> x;
//         var.setMau(x);
//         v.push_back(var);
//     }

//     for(auto it : v) cout << it << "  ";

//     x.sizeOflist = v.size();
//     x.List = new PhanSo[x.sizeOflist];
//     for(int i = 0; i < x.sizeOflist; i++){
//         x[i] = v[i];
//     }
//     return file;
// }

// int main(){
//     ArrPhanSo arr;
//     fstream file_outin("ghimangphanso.txt");
//     file_outin >> arr;
//     cout << arr;
//     file_outin.close();
//     system("pause");
// }

// //4 1 2 3 2 5 6 7 3


#include<iostream>
#include<iomanip>
using namespace std;
#include<math.h>

class DonThuc{
    private:
        double coef;
        int deg;
    public:
        DonThuc(){
            this->coef = 0;
            this->deg = 0;
        }
        double GetCoef() const{
            return coef;
        }
        int GetDeg() const{
            return deg;
        }
        void SetDeg(int x){
            deg = x;
        }
        friend istream& operator >> (istream& in, DonThuc& x);
        friend ostream& operator << (ostream& out, const DonThuc& x);
        double calVal(double x);
        DonThuc operator + (const DonThuc& x);
        DonThuc operator - (const DonThuc& x);
        DonThuc operator * (const DonThuc& x);
        DonThuc operator / (const DonThuc& x);
};

istream& operator >> (istream& in, DonThuc& x){
    cout << "nhap he so cua don thuc: "; in >> x.coef;
    cout << "nhap so mu cua don thuc: "; in >> x.deg;
    return in;
}
ostream& operator << (ostream& out, const DonThuc& x){
    if(x.coef == 0){
        return out;
    }
    if((x.coef == 1 || x.coef == -1) && x.deg == 0){
        out << x.coef;
        return out;
    }
    if(x.coef == 1){}
    if(x.coef == -1 ) cout << "-";
    else if(x.coef == 1){}
    else  out << setprecision(3) << x.coef;
    if(x.deg == 0) return out;
    if(x.deg == 1) out << "x";
    else {
        out << "x^" << x.deg;
    }
    return out;
}

double DonThuc::calVal(double x){
    return coef*pow(x, deg);
}
DonThuc DonThuc::operator + (const DonThuc& x){
    DonThuc result;
    result.coef = x.coef + coef;
    result.deg = x.deg;
    return result;
}
DonThuc DonThuc::operator - (const DonThuc& x){
    DonThuc result;
    result.coef = coef - x.coef;
    result.deg = x.deg;
    return result;
}
DonThuc DonThuc::operator * (const DonThuc& x){
    DonThuc result;
    result.coef = coef * x.coef;
    result.deg = deg + x.deg;
    return result;
}
DonThuc DonThuc::operator / (const DonThuc& x){
    DonThuc result;
    result.coef = coef/x.coef;
    result.deg = deg - x.deg;
    return result;
}

class DaThuc{
    private:
        DonThuc* list;
        int size;
    public:
        DaThuc(){
            this->list = NULL;
            size = 0;
        }
        friend istream& operator >> (istream& in, DaThuc& x);
        friend ostream& operator << (ostream& out,DaThuc& x);
        double Calvalue(int x);
        DaThuc operator + (const DaThuc& x);
        DaThuc operator - (const DaThuc& x);
        DaThuc operator * (const DaThuc& x);
        DaThuc operator * (const DonThuc& x) const;
        DaThuc operator / (const DaThuc& x);
        DonThuc& operator [] (int i) const {
            return list[i];
        }
        DaThuc operator = (const DaThuc& x){
            size = x.size;
            list = new DonThuc[size];
            for(int i = 0; i < size; i++){
                (*this)[i] = x[i];
            }
            return *this;
        }
        bool operator >= (const DaThuc& x);
};

bool DaThuc::operator >= (const DaThuc& x){
    if(this->size < x.size) return false;
    return true;
}

istream& operator >> (istream& in, DaThuc& x){
    cout << "nhap bac cao nhat cua da thuc: ";
    int n; in >> n;
    x.list = new DonThuc[n + 1];
    x.size = n + 1;
    for(int i = 0; i < n + 1; i++){
        cout << "nhap don thuc bac " << i << ": " << endl;
        cin >> x[i];
    }
    return in;
}

ostream& operator << (ostream& out, DaThuc& x){
    for(int i = x.size - 1; i >= 0; i--){
        if(i == 0){
            if(x[i].GetCoef() > 0){
                out << "+" <<" ";
            }
            out << x[i] << endl;
            break;
        }
        if(i == x.size - 1){
            out << x[i] << " ";
        }
        else{
            if(x[i].GetCoef() < 0) out << x[i] << " ";
            else if(x[i].GetCoef() > 0) out << "+ " << x[i] << " ";
        }
    }
    return out;
}

double DaThuc::Calvalue(int x){
    double result = 0;
    for(int i = 0; i < size; i++){
        result += (*this)[i].calVal(x);
    }
    return result;
}

DaThuc DaThuc::operator + (const DaThuc& x){
    DaThuc result;
    const DaThuc* lon = (size > x.size) ? this : &x;
    const DaThuc* nho = (size < x.size) ? this : &x;
    int min_size = (size < x.size) ? size : x.size;
    result.size = lon->size;
    result.list = new DonThuc[result.size];
    for(int i = 0; i < min_size; i++){
        result[i] = (*this)[i] + x[i];
    }
    for(int i = min_size; i < lon->size; i++){
        result[i] = (*lon)[i];
    }
    return result;
}

DaThuc DaThuc::operator - (const DaThuc& x){
    DaThuc result;
    const DaThuc* lon = (size > x.size) ? this : &x;
    const DaThuc* nho = (size < x.size) ? this : &x;
    result.size = lon->size;
    result.list = new DonThuc[result.size];
    for(int i = 0; i < nho->size; i++){
        result[i] = (*this)[i] - x[i];
    }
    if(lon == &x){
        for(int i = nho->size; i < lon->size; i++){
            result[i] = result[i] - x[i];
        }
    }
    else{
        for(int i = nho->size; i < lon->size; i++){
            result[i] = (*this)[i];
        }
    }
    for(int i = lon->size - 1; i >= 0; i--){
        if(result[i].GetCoef() == 0){
            --result.size;
        }
        else{
            break;
        }
    }
    return result;
}

DaThuc DaThuc::operator * (const DaThuc& x){
    DaThuc result;
    result.size = size + x.size - 1;
    result.list = new DonThuc[result.size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < x.size; j++){
            result[i + j] = result[i + j] + (*this)[i] * x[j];
        }
    }
    return result;
}


DaThuc DaThuc::operator * (const DonThuc& x) const{
    DaThuc result;
    result.size = size + x.GetDeg();
    result.list = new DonThuc[result.size];
    for(int i = size - 1; i >= 0; i--){
        result[i + x.GetDeg()] = (*this)[i] * x;
    }
    for(int i = 0; i < x.GetDeg(); i++){
        result[i].SetDeg(i);
    }
    return result;
}

DaThuc DaThuc::operator / (const DaThuc& x){
    DaThuc result;
    if(!(*this >= x)) return result;
    result.size = size - x.size + 1;
    result.list = new DonThuc[result.size];
    DaThuc temp = *this;
    DaThuc tich;
    while(temp >= x){
        int i = temp.size;
        int j = x.size;
        const int index = i - j;
        result[index] = temp[i - 1] / x[j - 1];
        tich = x * result[index];
        temp = temp - tich;
    }
    for(int i = 0; i < result.size; i++){
        if(result[i].GetCoef() == 0 && result[i].GetDeg() == 0){
            result[i].SetDeg(i);
        }
    }
    return result;
}

int main(){
    DaThuc x;
    cin >> x;
    cout << x;
    DaThuc y;
    cin >> y;
    cout << endl;
    cout << y;
    cout << endl;
    DaThuc z;
    z = x / y;
    cout << z;
    cout << endl;
    system("pause");
}

// 3 1 0 1 1 0 2 2 3
// 2 2
// 2 1 0 2 1 2 2 
// 3 1 0 1 1 0 2 2 3

// 3 1 0 1 1 0 2 2 3
// 2 1 0 2 1 3 2 
// 0 1 0
// 0 2 0

// 2 3 
// 4 1
