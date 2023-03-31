#include<iostream>
#include<math.h>
using namespace std;

class Ngay{
    private:
        int Ngays, Thang, Nam;
        static int NamKhongNhuan[13];
        static int NamNhuan[13];
    public:
        Ngay();
        Ngay(int, int, int);
        Ngay(int);
        Ngay(const Ngay&);
        friend ostream& operator << (ostream& out, const Ngay&);
        Ngay operator + (Ngay&);
        Ngay operator + (int);
        friend Ngay operator + (int x, Ngay& y);
        Ngay operator - (Ngay&);
        friend Ngay operator - (int, Ngay&);
        Ngay operator - (int);
        bool operator > (const Ngay& x);
};

int Ngay::NamKhongNhuan[13] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Ngay::NamNhuan[13] = {1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Ngay::Ngay(){
    Ngays = Thang = Nam = 1;
}

Ngay::Ngay(int a, int b, int c){
    Ngays = abs(a);
    Thang = b%12;
    Nam =  c + b/12;
}

Ngay::Ngay(const Ngay& x){
    this->Ngays = x.Ngays;
    Thang = x.Thang;
    Nam = x.Nam;
}

bool checkNamNhuan(int x){
    if(x%4 == 0 && x%100 != 0) return true;
    return false;
}
 
Ngay::Ngay(int x){
    Nam = 1;
    while(true){
        if(x < 365) break;
        if(checkNamNhuan(Nam) == true && x < 366) break;
        if(checkNamNhuan(Nam) == true){
            x = x - 366;
            Nam++;
        }
        else{
            x -= 365;
            Nam++;
        }
    }
    int tem = x;
    Thang = 1;
    for(int i = 1; i <= 12; i++){
        if(checkNamNhuan(Nam)){
            if(tem >= Ngay::NamNhuan[i]){
                tem -= Ngay::NamNhuan[i];
                Thang++;
            }
        }
        else {
            if(tem >= Ngay::NamKhongNhuan[i]){
                tem -= Ngay::NamKhongNhuan[i];
                Thang++;
            }
            else break;
        }
    }
    Ngays = tem;
}

ostream& operator << (ostream& out, const Ngay& x){
    out << x.Ngays << "/" << x.Thang << "/" << x.Nam;
}

Ngay Ngay::operator + (Ngay& x){
    Ngay tem;
    int a = Ngays + x.Ngays;
    int du;
    if(checkNamNhuan(this->Nam) && this->Thang == 2){
        tem.Ngays =
         a % Ngay::NamNhuan[this->Thang];
        du = a/Ngay::NamNhuan[this->Thang];
    }
    else{
        tem.Ngays = a % Ngay::NamKhongNhuan[this->Thang];
        du = a/Ngay::NamKhongNhuan[this->Thang];
    }
    a = Thang + x.Thang + du;
    du = a/12;
    tem.Thang = a%12;
    tem.Nam = this->Nam + x.Nam + du;
    return tem;
}

Ngay Ngay::operator + (int x){
    Ngay tem(x);
    return *this + tem;
}

Ngay operator + (int x, Ngay& y){
    Ngay tem(x);
    tem.Nam -= 1;
    tem.Thang -= 1;
    tem.Ngays -= 1;
    return tem + y;
}

Ngay Ngay:: operator - (Ngay& x){
    if(Nam < x.Nam){
        Ngay result(0,0,0);
        return result;
    }
    else if(Thang  < x.Thang && Nam == x.Nam){
        Ngay result(0,0,0);
        return result;
    }
    else if(Nam == x.Nam && Thang == x.Thang && Ngays < x.Ngays)
    {
        Ngay result(0,0,0);
        return result;
    }
    Ngay tem;
    if(Ngays < x.Ngays){
        tem.Ngays = Ngays + Ngay::NamKhongNhuan[Thang - 1] - x.Ngays;
        tem.Thang = -1;
    }
    else{
        tem.Ngays = Ngays -  x.Ngays;
        tem.Thang = 0;
    }
    if(Thang + tem.Thang < x.Thang){
        tem.Thang += (Thang + 12 - x.Thang);
        tem.Nam = -1;
    }
    else {
        tem.Thang += (Thang - x.Thang);
        tem.Nam = 0;
    }
    
    tem.Nam += (Nam - x.Nam);

    return tem;
}

Ngay Ngay::operator-(int x){
    Ngay tem(x);
    return *this - tem;
}

Ngay operator - (int x, Ngay& y){
    Ngay tem(x);
    return tem - y;
}

bool Ngay::operator > (const Ngay& x){
    if(Nam > x.Nam) return true;
    else if(Nam == x.Nam){
        if(Thang > x.Thang) return true;
        else if(Thang = x.Thang){
            if(Ngays > x.Ngays) return true;
        }
    }
    return false;
}

int main()
{
    Ngay n1; //1/1/1
    Ngay n2(02,10,2014); //2/10/2014
    Ngay n3(-10,16,2000); //10/04/2001
    Ngay n4(1000); //27/9/3
    Ngay n5 = n2 + n3; //12/2/4016
    Ngay n6 = n1 + 5000; //10/10/15
    Ngay n7 = 1234 + n4; //14/2/7
    Ngay n8 = 190 + n6 + n7; //2/7/23
    Ngay n9 = n8 - n6; //1/9/7
    Ngay n10 = 12000 - n9; //9/2/26
    if (n10 > n6)
    {
        n10 = n2 - 1000 + n6;
    }
    cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
    cout << n5 << endl << n6 << endl << n7 << endl << n8 << endl;
    cout << n9 << endl << n10 << endl;
    system("pause");
}
