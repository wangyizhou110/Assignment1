#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;


//There are 10 lists for waiting people and 10 lists for the phone number 
class WaitingList
{
private:
	list<string> m_list[10];
	list<string> num_list[10];
	list<string>::iterator it;
	string m_name;  //name of a waiting list
	int size = 0;
public:
	string getName()
	{
		return m_name;
	}
	//get the name of the waiting list
	void setName(string name)
	{
		cout << endl << "please enter the name of the list：" << endl;
		cin >> name;
		m_name = name;
	}
	void Add(int& num, int a, string name, string phone);
	void Remove(int a, int& num);
	void Reset(int a, string name);
	void showWaitingList(int a);
	int getSize();
	void search(int a, string input);
};

#endif 
