#include<iostream>
#include<math.h>
using namespace std;

class ThoiGian{
    private:
        int gio, phut, giay;
    public:
        ThoiGian(void);
        ThoiGian(const int& x);
        ThoiGian(int x, int y);
        ThoiGian(int x, int y, int z);
        ThoiGian operator + (const ThoiGian& x);
        friend ThoiGian operator + (const int& x, const ThoiGian& y);
        ThoiGian operator - (const ThoiGian& x);
        friend ThoiGian operator - (const int& x, const ThoiGian& y);
        bool operator <= (const ThoiGian& x);
        friend bool operator <= (const int& x, const ThoiGian& y);
        friend ostream& operator << (ostream& out, const ThoiGian& x);
};

ThoiGian::ThoiGian(void){
    gio = phut = giay = 0;
}
ThoiGian::ThoiGian(const int& x1){
    int x = abs(x1);
    gio = (x/3600)%24;
    phut = (x/60)%60;
    giay = x%60;
}
ThoiGian::ThoiGian(int x1, int y1){
    int x = abs(x1), y = abs(y1);
    giay = y%60;
    int nho  = 0;
    phut = (x + y/60)%60;
    gio = ((x + y/60)/60)%24;
}
ThoiGian::ThoiGian(int x1, int y1, int z1){
    int z = abs(z1), y = abs(y1), x = abs(x1); 
    giay = z%60;
    phut = (y + z/60)%60;
    gio = (x + (y + z/60)/60)%24;
}

ThoiGian ThoiGian::operator + (const ThoiGian& x){
    ThoiGian tem;
    int nho = 0;
    tem.giay = (giay + x.giay)%60;
    nho = (giay + x.giay)/60;
    tem.phut = (phut + x.phut + nho)%60;
    nho = (phut + x.phut + nho)/60;
    tem.gio = (gio + x.gio + nho) % 24;
    return tem;
}

ThoiGian operator + (const int& x, const ThoiGian& y){
    ThoiGian tem(x);
    return tem + y;
}

bool ThoiGian::operator <= (const ThoiGian& x){
    if(gio < x.gio) return true;
    if(gio == x.gio && phut < x.phut) return true;
    if(gio == x.gio && phut == x.phut && giay < x.giay) return true;
    if(gio == x.gio && phut == x.phut && giay == x.giay) return true;
    return false;
}

ThoiGian ThoiGian::operator - (const ThoiGian& x){
    ThoiGian tem;
    if(!(*this <= x)){
        int nho = 0;
        tem.giay = giay - x.giay;
        if(tem.giay < 0){
            tem.giay += 60;
            nho = 1;
        }
        tem.phut = phut - x.phut - nho;
        nho = 0;
        if(tem.phut < 0){
            nho = 1;
            tem.phut += 60;
        }
        tem.gio = gio - x.gio - nho;
    }
    return tem;
}

ThoiGian operator - (const int& x, const ThoiGian& y){
    ThoiGian tem(x);
    return tem - y;
}

bool operator <= (const int& x, const ThoiGian& y){
    ThoiGian tem(x);
    return tem <= y;
}

ostream& operator << (ostream& out, const ThoiGian& x){
    if(x.gio < 10) cout << "0" << x.gio;
    else out << x.gio;
    out << ":";
    if(x.phut < 10) out << "0" << x.phut;
    else out << x.phut;
    out << ":";
    if(x.giay < 10) out << "0" << x.giay;
    else out << x.giay;
    return out;
}

int main(){
    ThoiGian tg1; //00:00:00
    ThoiGian tg2(1212); //00:20:12
    ThoiGian tg3(125,45); //02:05:45
    ThoiGian tg4(12,239,-78); //16:00:18
    ThoiGian tg5 = tg2 + tg3; //02:25:57
    ThoiGian tg6 = 5000 + tg2; //01:43:32
    ThoiGian tg7 = tg4 - tg6; //14:16:46
    ThoiGian tg8 = 12300 - tg4; //00:00:00
    ThoiGian tg9, tg10;
    if (tg8 <= tg3)
    {
        tg9 = tg1 + tg2 + 36000; //10:20:12
    }
    ThoiGian tem(12345);
    cout << endl  << tem << endl;
    if (!(12345 <= tg5))
    {
        tg10 = tg5 + 12345; //05:51:42
    }
    cout << tg1 << endl << tg2 << endl << tg3 << endl << tg4 << endl;
    cout << tg5 << endl << tg6 << endl << tg7 << endl << tg8 << endl;
    cout << tg9 << endl << tg10 << endl;
    system("pause");
}