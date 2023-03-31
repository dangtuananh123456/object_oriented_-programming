#include<iostream>
using namespace std;
#define MAXLEN 100

class SoNguyenLon{
    private:
        int mangSo[MAXLEN];
        int soCS;
        static SoNguyenLon snlMax;
    public:
        SoNguyenLon(void);
        SoNguyenLon(const int& cs, const int& scs);
        SoNguyenLon(const unsigned int& n);
        SoNguyenLon(const SoNguyenLon& snl);
        ~SoNguyenLon(void);
        SoNguyenLon operator + (const SoNguyenLon& snl);
        SoNguyenLon operator - (const SoNguyenLon& snl);
        bool operator > (const SoNguyenLon& snl);
        const SoNguyenLon& operator = (const SoNguyenLon& snl);
        friend SoNguyenLon operator + (const unsigned int& n, const SoNguyenLon& snl );
        friend SoNguyenLon operator - (const unsigned int& n, const SoNguyenLon& snl );
        friend ostream& operator << (ostream& out, const SoNguyenLon& snl);
        static SoNguyenLon SNLMax();
};
SoNguyenLon SoNguyenLon::snlMax;
SoNguyenLon::SoNguyenLon(void){
    soCS = 1;
    mangSo[soCS - 1] = 0;
    if(*this > snlMax){
        snlMax = *this;
    }
}
SoNguyenLon::SoNguyenLon(const int& cs, const int& scs){
    int csR = cs;
    if(csR < 1) csR =  1;
    if(csR > 9) csR = 9;
    soCS = abs(scs);
    if(soCS < 1) soCS = 1;
    if(soCS > MAXLEN)  soCS = MAXLEN;
    for(int i = 0; i < soCS; i++){
        mangSo[i] = csR;
    }
    if(*this > snlMax){
        snlMax = *this;
    }
}
SoNguyenLon::SoNguyenLon(const unsigned int& n){
    unsigned int tem = n;
    soCS = 0;
    while(tem > 9){
        mangSo[soCS++ ] = tem %10;
        tem /= 10;
    }
    mangSo[soCS++] = tem;
    if(*this > snlMax) snlMax = *this;
}
SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl){
    soCS = snl.soCS;
    for(int i = 0; i < soCS; i++){
        mangSo[i] = snl.mangSo[i];
    }
}
SoNguyenLon::~SoNguyenLon(void){}

SoNguyenLon SoNguyenLon::operator + (const SoNguyenLon& snl){
    SoNguyenLon snlKQ;
    const SoNguyenLon *snlSCSMax = (soCS > snl.soCS) ? this : &snl;
    const SoNguyenLon *snlSCSMin = (soCS < snl.soCS) ? this : &snl;
    int soCSMin = (soCS > snl.soCS) ? snl.soCS : soCS;
    int nho = 0;
    for(int i = 0; i < snlSCSMin->soCS; i++){
        snlKQ.mangSo[i] = nho + mangSo[i] + snl.mangSo[i];
        nho = snlKQ.mangSo[i] / 10;
        snlKQ.mangSo[i] %= 10;
    }
    for(int i = snlSCSMin->soCS; i < snlSCSMax->soCS; i++){
        snlKQ.mangSo[i] = nho + snlSCSMax->mangSo[i];
        nho = snlKQ.mangSo[i] / 10;
        snlKQ.mangSo[i] %= 10;
    }
    snlKQ.soCS = snlSCSMax->soCS;
    if(nho  > 0){
        snlKQ.mangSo[snlKQ.soCS++] = nho;
    }
    if(snlKQ > snlMax) snlMax = snlKQ;
    return snlKQ;
}
bool SoNguyenLon::operator > (const SoNguyenLon& snl){
    if(soCS > snl.soCS) return true;
    if(soCS < snl.soCS) return false;
    for(int i = soCS - 1; i >= 0; i--){
        if(mangSo[i] == snl.mangSo[i]) continue;
        if(mangSo[i] > snl.mangSo[i]) return true;
        else return false;
    }
    return false;
}
SoNguyenLon SoNguyenLon::operator - (const SoNguyenLon& snl){
    SoNguyenLon snlKQ;
    int nho = 0, i;
    if(*this > snl){
        for(i = 0; i < snl.soCS; i++){
            snlKQ.mangSo[i] = mangSo[i] - snl.mangSo[i] - nho;
            nho = 0;
            if(snlKQ.mangSo[i] < 0){
                nho = 1;
                snlKQ.mangSo[i] += 10;
            }
        }
        for(; i < soCS; i++){
            snlKQ.mangSo[i] = mangSo[i] - nho;
            nho = 0;
            if(snlKQ.mangSo[i] < 0){
                nho = 1;
                snlKQ.mangSo[i] += 10;
            }
        }
        snlKQ.soCS = soCS;
        while(snlKQ.mangSo[snlKQ.soCS - 1] == 0){
            snlKQ.soCS--;
        }
    }
    return snlKQ;
}
const SoNguyenLon& SoNguyenLon::operator = (const SoNguyenLon& snl){
    soCS = snl.soCS;
    for(int i = 0; i < soCS; i++){
        mangSo[i] = snl.mangSo[i];
    }
    return *this;
}
SoNguyenLon operator + (const unsigned int& n, const SoNguyenLon& snl ){
    SoNguyenLon tem(n);
    SoNguyenLon kq = tem + snl;
    if(kq > SoNguyenLon::snlMax) SoNguyenLon::snlMax = kq;
    return kq;
}
SoNguyenLon operator - (const unsigned int& n, const SoNguyenLon& snl ){
    SoNguyenLon tem(n);
    return tem - snl;
}
ostream& operator << (ostream& out, const SoNguyenLon& snl){
    for(int i = snl.soCS - 1; i >= 0; i--){
        out << snl.mangSo[i];
    }
    return out;
}
SoNguyenLon SoNguyenLon::SNLMax(){
    return snlMax;
}

int main(){
    SoNguyenLon snl1;
    SoNguyenLon snl2(1234567);
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 456675765 - snl2;
    SoNguyenLon snl7 =  snl4 - snl3 + 123456789;
    cout << snl1 << endl;
    cout << snl2 << endl;
    cout << snl3 << endl;
    cout << snl4 << endl;
    cout << snl5 << endl;
    cout << snl6 << endl;
    cout << snl7 << endl;
    cout << endl;
    cout << "SoNguyenLon Max:" << endl;
    cout << SoNguyenLon::SNLMax();
    cout << endl;
    system("pause");
}