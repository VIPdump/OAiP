#include <Windows.h>
#include <algorithm>
#include "Students.h"

using namespace std;

bool isEmpty(fstream& fs)
{
	bool result;
	fs.open("myFile.txt");

	if (fs.peek() == EOF)
		result = true;
	else result = false;

	fs.close();
	return result;
}

void add(fstream& fs, Students& a)
{
	fs.open("myFile.txt", fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
		cout << "The file is not open";

	else fs.write((char*)&a, sizeof(Students));

	fs.close();
}

void show(fstream& fs, Students& buffer)
{
	int i = 1;

	fs.open("myFile.txt", fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
		cout << "The file is not open";

	else
	{
		while (fs.read((char*)&buffer, sizeof(Students)))
		{
			buffer.print(i);
			i++;
		}
	}

	fs.close();
}

void change(fstream& fs, Students& buffer, int& choice)
{
	fstream nfs;
	int i = 1;

	fs.open("myFile.txt", fstream::in | fstream::out | fstream::app);
	nfs.open("new.txt", fstream::in | fstream::out | fstream::app);


	if (!fs.is_open() && !nfs.is_open())
		cout << "The file is not open";

	else
	{
		while (fs.read((char*)&buffer, sizeof(Students)))
		{
			if (i == choice)
			{
				buffer.print(i);
				cout << endl;
				buffer.data();
				nfs.write((char*)&buffer, sizeof(Students));
			}
			else nfs.write((char*)&buffer, sizeof(Students));
			i++;
		}
	}

	fs.close();
	nfs.close();
	
	remove("myFile.txt");
	rename("new.txt", "myFile.txt");
}

void honors(fstream& fs, Students& buffer)
{
	int i = 1, choice;

	cout << "Write the group: ";
	cin >> choice;

	cout << "\nHonors Students:\n\n";

	fs.open("myFile.txt", fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
		cout << "The file is not open";

	else
	{
		while (fs.read((char*)&buffer, sizeof(Students)))
		{
			if (buffer.group == choice)
			{
				if (buffer.est_aver >= 9)
					buffer.print(i);
			}
			i++;
		}
	}

	fs.close();
}

int main()
{
	Students a, buffer;
	int choice;
	string temp;
	fstream fs;

	while(true)
	{
		cout << "What you choose: \n\t0 - To Exit" 
			"\n\t1 - To Show \n\t2 - To Add \n\t3 - To Change \n\t4 - To Clear Data \n\t5 - Honors Students\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;

		case 1:
			if (isEmpty(fs))
			{
				system("cls");
				cout << "File is empty";
				Sleep(2000);
				system("cls");
			}
			else
			{
				system("cls");
				show(fs, buffer);
				Sleep(3000);
			}
			break;

		case 2: 
			system("cls");
			a.data();
			add(fs, a);
			cout << endl << "Successfully aded";
			Sleep(850);
			system("cls");
			break;

		case 3: 
			system("cls");
			show(fs, buffer);
			cout << "What's the student number? ";
			cin >> choice; 
			system("cls");
			change(fs, buffer, choice);
			cout << endl;
			break;

		case 4:
			cout << "\nAre you sure? (Yes or No) ";
			cin >> temp;
			transform(temp.begin(), temp.end(), temp.begin(), tolower);
			if (temp == "yes")
			{
				remove("myFile.txt");
				system("cls");
				cout << "Data was clearned";
				Sleep(1550);
				system("cls");
			}
			else
			{
				cout << "Data wasn't clearned";
				Sleep(1550);
				system("cls");
			}
			break;

		case 5:
			system("cls");
			show(fs, buffer);
			honors(fs, buffer);
			Sleep(3000);
			break;

		default:
			system("cls");
			cout << "Try again";
			Sleep(750);
			system("cls");
		}
	}
	

	

	


}