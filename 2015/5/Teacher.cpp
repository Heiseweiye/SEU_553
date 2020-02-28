#include "Teacher.h"
#include <string>
#include <iostream>
using namespace std;

Teacher::Teacher(int number, string name, string sex, Date birthday, Date hireDate) {
	this->number = number;
	this->name = name;
	this->sex = sex;
	this->birthday = birthday;
	this->hireDate = hireDate;
}
Teacher::Teacher(const Teacher& t) {
	number = t.number;
	name = t.name;
	birthday = t.birthday;
	hireDate = t.hireDate;
}

// �������������еڶ�����Ʒ�������������bool���ͣ���ֱ���ں�����
// ����Ҫ�������Ϣ�������
bool Teacher::isRetire(int year) const {
	if (sex == "male")				
		return (year - birthday.getYear() >= 55);		// ���Դ��ڵ���55������
	else
		return (year - birthday.getYear() >= 60);		// Ů�Դ��ڵ���60������
}

// �˺���ֻ����������isRetire�������µĽ�һ���ж�
bool Teacher::isKeepHire(int year) const {
	if (isRetire(year) && sex == "female") {			// �������������������Ů�Բ���Ҫ�ϸ��һ����
		return (year - hireDate.getYear() < 35);		// �жϹ����Ƿ�ﵽ35�꣬δ�ﵽ����Ƹ
	}												
	else
		return false;
}
void Teacher::printInfo() const {
	cout << "name:" << name << endl
		<< "number:" << number << endl << endl;
}
string Teacher::getName() const {
	return name;
}
