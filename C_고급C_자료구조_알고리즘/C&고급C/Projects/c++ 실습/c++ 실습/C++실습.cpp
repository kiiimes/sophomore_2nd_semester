#include<iostream>
#include<string>

using namespace std;

class Baseball {
private:
	string name;                     // �߱�������
	string team;                     // �Ҽ���
	int annual;                      // ����

public:
	Baseball();                      // �⺻������(�ʱ�ȭ�۾�)
	Baseball(char* p,char* t,int a); // �μ�3��������(�����۾�)
	string GetTeam(Baseball player); // �Ҽ��������Լ�
 
	void Setannual(int a);           // ���������Լ�
	void Setname(char* p);           // ���������Լ�
	void Disp();                     // ����Լ�
	void printNameP();               // ���α׷��� �̸� ����Լ�
};

Baseball::Baseball() {
	this -> name = "�̸�����";
	this -> team = "�Ҽ�������";
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
	cout << this -> name << "������ ������ " << this -> annual << "�￡�� " << a << "�����κ���." << endl;
	this -> annual = a;
}

void Baseball::Setname(char* p) {
	cout << this -> name << "������ " << p << "�����κ���." << endl;
	this -> name = p;
}

void Baseball::Disp() {
	cout << "������: " << this -> name << endl;
	cout << "�Ҽ���: " << this -> team << endl;
	cout << "��  ��: " << this -> annual << "��" << endl;
	cout << endl;
}

void printNameP() {
	cout << "---------------------------" << endl;
	cout << "  Programmer Name : ������" << endl;
	cout << "---------------------------" << endl;
}

int main() {

 Baseball s1("����� ","�Ｚ ���̿���",15);
 Baseball s2("������ ","�λ� ���",23);
 Baseball s3("�վƼ� ","�Ե� ���̾���",32);
 Baseball s4("���ñ� ","�ؼ� �������",43);
 Baseball s5("���ٿ� ","��ȭ �̱۽�",51);
 Baseball s6("������ ","�Ｚ ���̿���",17);

 s1.Disp(); // ����� �Ｚ ���̿��� 15
 s2.Disp(); // ������ �λ� ���   23
 s3.Disp(); // �վƼ� �Ե� ���̾��� 32
 s4.Disp(); // ���ñ� �ؼ� ������� 43
 s5.Disp(); // ���ٿ� ��ȭ �̱۽�   51
 s6.Disp(); // ������ �Ｚ ���̿��� 17

 s1.Setname("������ ");
 cout << endl;
 s6.Disp();
 printNameP();

 return 0;

} 
