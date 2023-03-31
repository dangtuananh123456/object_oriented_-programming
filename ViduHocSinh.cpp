#include<iostream>
#include<string.h>
using namespace std;

class HS{
    private:
        char* hoTen;
    public:
        HS(void);
        HS(const char* ht);
        HS(const HS& hs);
        ~HS(void);
        const HS& operator = (const HS& hs);
};

HS::HS(void){
    hoTen = NULL;
}
HS::HS(const char* ht){
    int len = strlen(ht);
    hoTen = new char[len + 1];
    strcpy(hoTen, ht);
}

HS:: HS(const HS& hs){
    cout << "copy contructor ...." << endl;
    int len = strlen(hs.hoTen);
    hoTen = new char[len + 1];
    strcpy(hoTen, hs.hoTen);
}
HS::~HS(void){
    if(hoTen != NULL){
        delete[] hoTen;
        hoTen = NULL;
    }
}

const HS& HS::operator = (const HS& hs){
    cout << "opetator = ...." << endl;
    if(hoTen != NULL){
        delete[] hoTen;
    }
    int len = strlen(hs.hoTen);
    hoTen = new char[len + 1];
    strcpy(hoTen, hs.hoTen);
    return *this;
}

int main(){
    HS hs1("sdfdgfg");
    cout << "hs2(hs1)" << endl;
    HS hs2(hs1);
    cout << endl << "hs3 = hs1 " << endl;
    HS hs3 = hs1;
    cout << endl << "hs2 = hs3" << endl;
    hs2 = hs3;
    cout << endl;
    system("pause");
}