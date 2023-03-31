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
