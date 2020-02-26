#include <iostream>
#include "waitingList.h"
using namespace std;




int main()
{
	string name, info, input, phone;
	int a, num;
	WaitingList m_list[10];

	//set a loop to return to the main menu and print out the status og the waiting list
	while (true)
	{
		cout << endl << "Index.ListName.(How many people are waiting)" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << "  " << i + 1 << "     " << m_list[i].getName() << "(" << m_list[i].getSize() << ")" << endl << endl;
		}

		//enter 0 to end the program
		cout << endl << "please select a waitinglist to edit or quit(0)" << endl << endl;
		cin >> a;
		if (a == 0)
			break;
		a--;

		cout << endl << "select function：\n 1.set name of list.\n 2.Add infomation.\n 3.remove customer.\n 4.show the whole list.\n 5.search customer. \n 6.reset the waiting list" << endl << endl;
		int n;
		cin >> n;

		//select the operation
		switch (n)
		{
		case 1:
			m_list[a].setName(name);
			break;
		case 2:
			cout << endl << "please enter the number of the customer you want to put in the waiting list:" << endl;
			cin >> num;
			cout << endl << "please enter customers information:" << endl;
			m_list[a].Add(num, a, info, phone);
			break;
		case 3:
			cout << endl << "this customer is:";
			m_list[a].Remove(a, num);
			break;
		case 4:
			cout << endl << "the list is:\n";
			m_list[a].showWaitingList(a);
			break;
		case 5:
			cout << endl << "enter the person you want to find:" << endl;
			cin >> input;
			m_list[a].search(a, input);
			break;
		case 6:
			cout << endl << "enter the new name of the list:" << endl;
			m_list[a].Reset(a, name);
			break;

		}
	}
	return 0;
}



