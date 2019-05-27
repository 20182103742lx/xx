// xx.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include"iostream"
using namespace std;
class CMyDate {
private:
	int year;
	int month;
	int day;
	int check();
public:
	CMyDate();
	CMyDate(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
	CMyDate aadDate(CMyDate &od);//od3=od1.addDate(od2);
	CMyDate operator + (CMyDate &otemp);//od3=od1+od2;
	CMyDate operator + (const int &d);
};
CMyDate CMyDate :: operator + (CMyDate &otemp) {
	CMyDate temp;
	temp.setDate(year + otemp.year, month + otemp.month, day + otemp.day);
	return temp;

}
CMyDate CMyDate:: operator + (const int &d) {
	CMyDate temp;
	temp.setDate(year , month, day + d);
	return temp;
}
CMyDate CMyDate::aadDate(CMyDate &od) {
	CMyDate temp;
	temp.setDate(year + od.year, month + od.month, day + od.day);
	return temp;
}
CMyDate::CMyDate() {
	year = 2019;
	month = 1;
	day = 1;
}
CMyDate::CMyDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1) {
		month = 1;
		day = 1;
		cout << "设置了错误日期,已置1" << endl;
	}
}
int CMyDate::setDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	int temp;
	if (temp = check() == 1 || check() == -1) {
		month = 1;
		day = 1;
		cout << "设置了错误日期已置1" << temp << endl;
		return -1;
	}
	else if (temp == 2) {
		cout << "设置月份有错误" << endl;
	}
	return 0;
}
void CMyDate::displayDate() {
	cout << year << "年" << month << "月" << day << "日" << endl;
}
int CMyDate::check() {
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return 2;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else {
		if (flatYearDays[month - 1] < day || day < 1)
			return -1;
	}
	return 0;
}
int CMyDate::getYear() {
	return year;
}
int CMyDate::getMonth() {
	return month;
}
int CMyDate::getDay() {
	return day;
}
void CMyDate::addOneDay() {
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
		if (leapYearDays[month - 1] < day) {
			day = 1;
			month++;
		}
	}
	else {
		if (flatYearDays[month - 1] < day) {
			day = 1;
			month++;
		}
	}
	if (month > 12) {
		month = 1;
		year++;
	}
}
int main()
{
	CMyDate od1(2016, 5, 23), od2(1, 2, 24),od3;
	od3 = od1 + 100;
	od1.displayDate();
	od2.displayDate();
	od3.displayDate();
	return 0;
}
