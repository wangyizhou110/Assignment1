#include "waitingList.h"



// add information  and phone number of the customers in the list
void WaitingList::Add(int& num, int a, string info, string phone)
{
	for (int i = 0; i < num; i++)
	{
		cout << endl << "enter the name" << endl;
		cin >> info;
		m_list[a].push_back(info);

		cout << endl << "enter the phone" << endl;
		cin >> phone;
		num_list[a].push_back(phone);
		size++;
	}
}

//remove the information and phone number of the first customer in the list
//print the customer's information
void WaitingList::Remove(int a, int& num)
{
	string info = m_list[a].front();
	m_list[a].pop_front();

	string phone = num_list[a].front();
	num_list[a].pop_front();

	cout << info << "," << phone << endl;
	size--;
}

//reset the waiting list, clear the information of the list and reset the name 
void WaitingList::Reset(int a, string name)
{
	cin >> name;
	m_name = name;
	m_list[a].clear();
	num_list[a].clear();
	size = 0;
}

//show the whole list of the waiting people 
void WaitingList::showWaitingList(int a)
{
	int i = 0;
	string waitingNUM[10];
	//remember the position of each phone number in the list and put them in a counting array
	for (it = num_list[a].begin(); it != num_list[a].end(); it++)
	{
		waitingNUM[i] = *it;
		i++;
	}
	int j = 1;
	//print the information and phone number of the people which have same position in their list
	for (auto v : m_list[a])
	{
		cout << j << "     " << v << "      " << waitingNUM[j - 1] << "\n";
		j++;
	}
}

// count the how many people are waiting in the list
int WaitingList::getSize()
{
	return size;
}

//Find a person's place in the list, enter his name based on it, and print out all his information
void WaitingList::search(int a, string input)
{
	int i = 0;
	string waitingNUM[10];
	for (it = num_list[a].begin(); it != num_list[a].end(); it++)
	{
		waitingNUM[i] = *it;
		i++;
	}
	int j = 1;
	for (auto v : m_list[a])
	{
		if (v == input)
		{
			cout << j << "       " << v << "," << waitingNUM[j - 1] << endl;
			break;
		}
		j++;
	}
}


