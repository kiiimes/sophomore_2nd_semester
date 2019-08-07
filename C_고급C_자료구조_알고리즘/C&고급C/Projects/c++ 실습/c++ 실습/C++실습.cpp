#include<iostream>
#include<string>

using namespace std;

class Baseball {
private:
	string name;                     // 야구선수명
	string team;                     // 소속팀
	int annual;                      // 연봉

public:
	Baseball();                      // 기본생성자(초기화작업)
	Baseball(char* p,char* t,int a); // 인수3개생성자(대입작업)
	string GetTeam(Baseball player); // 소속팀리턴함수
 
	void Setannual(int a);           // 연봉변경함수
	void Setname(char* p);           // 선수명변경함수
	void Disp();                     // 출력함수
	void printNameP();               // 프로그래머 이름 출력함수
};

Baseball::Baseball() {
	this -> name = "이름없음";
	this -> team = "소속팀없음";
	this -> annual = 0;
}

Baseball::Baseball(char* p,char* t,int a) {
	this -> name = p;
	this -> team = t;
	this -> annual = a;
}

string Baseball::GetTeam(Baseball player) {
	return player.team;
}

void Baseball::Setannual(int a) {
	cout << this -> name << "선수의 연봉을 " << this -> annual << "억에서 " << a << "억으로변경." << endl;
	this -> annual = a;
}

void Baseball::Setname(char* p) {
	cout << this -> name << "선수를 " << p << "선수로변경." << endl;
	this -> name = p;
}

void Baseball::Disp() {
	cout << "선수명: " << this -> name << endl;
	cout << "소속팀: " << this -> team << endl;
	cout << "연  봉: " << this -> annual << "억" << endl;
	cout << endl;
}

void printNameP() {
	cout << "---------------------------" << endl;
	cout << "  Programmer Name : 성열우" << endl;
	cout << "---------------------------" << endl;
}

int main() {

 Baseball s1("장원삼 ","삼성 라이온즈",15);
 Baseball s2("양의지 ","두산 베어스",23);
 Baseball s3("손아섭 ","롯데 자이언츠",32);
 Baseball s4("이택근 ","넥센 히어로즈",43);
 Baseball s5("정근우 ","한화 이글스",51);
 Baseball s6("차우찬 ","삼성 라이온즈",17);

 s1.Disp(); // 장원삼 삼성 라이온즈 15
 s2.Disp(); // 양의지 두산 베어스   23
 s3.Disp(); // 손아섭 롯데 자이언츠 32
 s4.Disp(); // 이택근 넥센 히어로즈 43
 s5.Disp(); // 정근우 한화 이글스   51
 s6.Disp(); // 차우찬 삼성 라이온즈 17

 s1.Setname("차우찬 ");
 cout << endl;
 s6.Disp();
 printNameP();

 return 0;

} 
