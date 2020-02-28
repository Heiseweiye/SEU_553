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
bool Teacher::isRetire(int year) const {
	if (sex == "male")				
		return (year - birthday.getYear() >= 55);		// ���Դ��ڵ���55������
	else
		return (year - birthday.getYear() >= 60);		// Ů�Դ��ڵ���60������
}
bool Teacher::isKeepHire(int year) const {
	if (isRetire(year) && sex == "female") {			// �������������������Ů�Բ���Ҫ�ϸ��һ����
		return (year - hireDate.getYear() < 35);		// �жϹ����Ƿ�ﵽ35�꣬δ�ﵽ����Ƹ
	}
	else
		return false;
}
void Teacher::printInfo() const {
	cout << "number: " << number << endl
		<< "name: " << name << endl
		<< "sex: " << sex << endl;
	cout << "birthday: ";
	birthday.printInfo();
	cout << endl;
	cout << "hire date: ";
	hireDate.printInfo();
	cout << endl;
}
string Teacher::getName() const {
	return name;
}
