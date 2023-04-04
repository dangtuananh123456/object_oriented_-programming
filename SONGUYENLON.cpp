#include<iostream>
#include<math.h>
#include<fstream>
#include<vector>
using namespace std;
class SonguyenLon{
	private:
		vector<unsigned char> lCS;
		void Pow10(const int& n);
	public:
		SonguyenLon(void);
		SonguyenLon(const int& cs, const int& scs);
		SonguyenLon(const unsigned long& n);
		SonguyenLon(const SonguyenLon& snl);
		~SonguyenLon(void);
		int SoCS();
		SonguyenLon operator + (SonguyenLon snl);
		SonguyenLon operator - (SonguyenLon snl);
		SonguyenLon operator * (SonguyenLon snl);
		bool operator > (SonguyenLon& snl);
		const SonguyenLon& operator = (const SonguyenLon& snl);
		SonguyenLon& operator += (SonguyenLon snl);
		friend SonguyenLon operator + (const unsigned int& n, const SonguyenLon& snl);
		friend SonguyenLon operator - (const unsigned int& n, const SonguyenLon& snl);
		friend ostream& operator << (ostream& os, SonguyenLon& snl);
		void PhatSinh();
		friend void GhiFile(ofstream& file, SonguyenLon& snl);
		friend void  DocVaTinhTong(ifstream& file);
};

void SonguyenLon::Pow10(const int& n){
	for(int i = 0; i < n; i++){
		lCS.insert(lCS.begin(), 0);
	}
}

SonguyenLon::SonguyenLon(void){
	lCS.push_back(0);
}

SonguyenLon::SonguyenLon(const int& cs, const int& scs){
	int csR = cs;
	if(csR < 1) csR = 1;
	if(csR > 9) csR = 9;
	int  so = abs(scs);
	if(so < 1) so =  1;
	for(int i = 0; i < so; i++){
		lCS.push_back(csR);
	}
}

SonguyenLon::SonguyenLon(const unsigned long& n){
	unsigned long tem = n;
	while(tem > 9){
		lCS.push_back(tem%10);
		tem /= 10;
	}
	lCS.push_back(tem%10);
}

SonguyenLon::SonguyenLon(const SonguyenLon& snl){
	lCS =  snl.lCS;
}

SonguyenLon::~SonguyenLon(void){
	
}

int SonguyenLon::SoCS(){
	return lCS.size();
}

bool SonguyenLon::operator > (SonguyenLon& snl){
	if(lCS.size() > snl.lCS.size()) return true;
	if(lCS.size() < snl.lCS.size()) return false;
	for(int i = -1; i > -lCS.size(); --i){
		if(lCS[i] == snl.lCS[i]) continue;
		if(lCS[i] > snl.lCS[i]) return true;
		return false;
	}
	return false;
}

const SonguyenLon& SonguyenLon::operator = (const SonguyenLon& snl){
	lCS = snl.lCS;
	return *this;
}

SonguyenLon& SonguyenLon::operator += (SonguyenLon snl){
	int soCSMin = (SoCS() < snl.SoCS()) ? SoCS() : snl.SoCS();
	int nho = 0, temp;
	unsigned char* pTemp;
	for(int i = 0; i < soCSMin; i++){
		pTemp = &lCS[i];
		*pTemp += snl.lCS[i] + nho;
		nho = *pTemp/10;
		*pTemp %= 10;
	}
	if(SoCS() == soCSMin){
		for(int i = soCSMin; i < snl.SoCS(); i++){
			temp = snl.lCS[i] + nho;
			lCS.push_back(temp%10);
			nho = temp/10;
		}
	}
	else{
		for(int i = soCSMin;  i < SoCS(); i++){
			pTemp = &lCS[i];
			*pTemp += nho;
			nho = *pTemp/10;
			*pTemp %= 10;
			if(nho == 0) break;
		}
	}
	if(nho > 0) lCS.push_back(1);
	return *this;
} 

SonguyenLon SonguyenLon::operator + (SonguyenLon snl){
	SonguyenLon snlKQ;
	snlKQ.lCS.clear();
	SonguyenLon* snlSCSMax = (SoCS()  > snl.SoCS()) ? this : &snl;
	SonguyenLon* snlSCSMin = (SoCS()  < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;
	for(int i = 0; i < snlSCSMin->SoCS(); i++){
		temp = lCS[i]  + snl.lCS[i] + nho;
		snlKQ.lCS.push_back(temp %10);
		nho = temp/10;
	}
	for(int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); i++){
		temp = snlSCSMax->lCS[i] + nho;
		snlKQ.lCS.push_back(temp %10);
		nho = temp/10;
	}
	if(nho > 0){
		snlKQ.lCS.push_back(1);
	}
	return snlKQ;
}  

SonguyenLon SonguyenLon::operator - (SonguyenLon snl){
	SonguyenLon snlkq;
	snlkq.lCS.clear();
	int nho = 0, i, temp;
	if(SoCS() >= snl.SoCS()){
		for(i = 0; i < snl.SoCS(); i++){
			temp = lCS[i] - snl.lCS[i] - nho;
			nho = 0;
			if(temp < 0){
				temp += 10;
				nho = 1;
			}
			snlkq.lCS.push_back(temp);
		}
		for(; i < SoCS(); i++){
			temp = lCS[i] - nho;
			nho = 0;
			if(temp < 0){
				temp += 10;
				nho = 1;
			}
			snlkq.lCS.push_back(temp);
		}
		while(snlkq.lCS[snlkq.lCS.size() - 1] == 0){
			snlkq.lCS.pop_back();
		}
	}
	return snlkq;
} 

SonguyenLon SonguyenLon::operator * (SonguyenLon snl){
	SonguyenLon snlkq, *psnlTemp;
	SonguyenLon *snlSCSMax =  (SoCS() > snl.SoCS()) ? this : &snl;
	SonguyenLon *snlSCSMin =  (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;
	for(int i = 0; i < snlSCSMin->SoCS(); i++){
		psnlTemp = new SonguyenLon;
		psnlTemp->lCS.clear();
		nho = 0;
		for(int j = 0; j < snlSCSMax->SoCS(); j++){
			temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[i] + nho;
			psnlTemp->lCS.push_back(temp%10);
			nho = temp/10;
		}
		if(nho > 0) psnlTemp->lCS.push_back(nho);
		psnlTemp->Pow10(i);
		snlkq += *psnlTemp;
		delete psnlTemp;
	}
	return snlkq;
}

SonguyenLon operator + (const unsigned int& n, const SonguyenLon& snl){
	SonguyenLon snltemp(n);
	SonguyenLon snlkq = snltemp + snl;
	return snlkq;
}

SonguyenLon operator - (const unsigned int& n, const SonguyenLon& snl){
	SonguyenLon snltem(n);
	return snltem - snl;
}

ostream&  operator << (ostream& os, SonguyenLon& snl){
	for(int i = snl.SoCS() - 1; i >= 0; i--){
		os << (int)snl.lCS[i];
	}
	return os;
}

void SonguyenLon::PhatSinh(){
	for(int i = 0; i < 10; i++){
		lCS.clear();
		int size = rand()% 16 + 15;
		for(int j = 0; j < size; j++){
			lCS.push_back(rand() % 9 + 1);
		}
		cout << *this;
		cout << endl;
	}
}

void GhiFile(ofstream& file, SonguyenLon& snl){
	file << snl << endl;
}

void DocVaTinhTong(ifstream& file){
	SonguyenLon result, tem;
	string x;
	tem.lCS.clear();
	while(!file.eof()){
		file >> x;
		for(int i = 0; i < x.length(); i++){
			tem.lCS.insert(tem.lCS.begin(), x[i] - 48);
		}
		cout << tem  << endl;
		result += tem;
		tem.lCS.clear();
	}
	cout << "Tong cac snl trong file: " << result << endl;
}



int main(){
	ofstream  file("ghifile.txt", ios::out|ios::app);
	ifstream file_in("snl.txt", ios::in);
	DocVaTinhTong(file_in);
	cout << endl;
	SonguyenLon x(5, 15);
	SonguyenLon y(6, 10);
	SonguyenLon z = x * y;
	cout << x << endl << y << endl << z << endl;
	//phat sinh 10 so nguyen lon
	x.PhatSinh();
	//ghi so nguyen lon ra file
	GhiFile(file, x);
	GhiFile(file, y);
	GhiFile(file, z);
	file_in.close();
	file.close();
	system("pause");
}
