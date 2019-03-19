#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class PatientAccount()
{
private:
	double fees;
	int days;
	double rate;
public:
	PatientAccount()
	{
		fees = 0;
		days = 0;
		rate = 50;
	}

	void setDays(int time)
	{
		days = time;
	}

	double getCharges()
	{
		return fees+=days*rate;
	}

	friend class Surgery();
	friend class Pharmacy();
}

class Surgery()
{
private:
	double heart = 500;
	double lungs = 400;
	double brain = 1000;
	double spine = 500;
	double eye = 300;

public:
	Surgery()
	{

	}
	void heartSurgery()
	{
		PatientAccount.fees += heart;
	}
	void lungSurgery()
	{
		PatientAccount.fees += lungs;
	}
	void brainSurgery()
	{
		PatientAccount.fees += brain;
	}
	void spineSurgery()
	{
		PatientAccount.fees += spine;
	}
	void eyeSurgery()
	{
		PatientAccount.fees += eye;
	}
}

class Pharmacy()
{
public:
	Pharmacy()
	{

	}
	void coldMedicine()
	{
		PatientAccount.fees += 10;
	}
	void allergyMedicine()
	{
		PatientAccount.fees += 5;
	}
	void greenHerb()
	{
		PatientAccount.fees += 20;
	}
	void redHerb()
	{
		PatientAccount.fees += 5;
	}
	void blueHerb()
	{
		PatientAccount.fees += 20;
	}
}

int main()
{
	bool cont = true;
	int choice;
	PatientAccount care = new PatientAccount();
	Surgery cut = new Surgery();
	Pharmacy med = new Pharmacy();

	while (cont)
	{
		cont = false;
		cout << "Welcome to C hospital, how can we help you?" << '\n';
		cout << "1. Surgery" << '\n' << "2. Medication" << '\n' << "3. Check out" << '\n'<<"Enter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			int temp;
			bool cont2 = true;
			while (cont2)
			{
				cont2 = false;
				cout << "Pick a surgery" << '\n';
				cout << "1. Heart Surgery" << '\n' << "2. Lung Surgery" << '\n' << "3. Spine Surgery" << '\n' << "4. Brain Surgery" << '\n' << "5. Eye Surgery" << '\n';
				cout << "Select a choice: ";
				cin >> temp;
				if (temp == 1)
					cut.heartSurgery();
				else if (temp == 2)
					cut.lungSurgery();
				else if (temp == 3)
					cut.spineSurgery();
				else if (temp == 4)
					cut.brainSurgery();
				else if (temp == 5)
					cut.eyeSurgery();
				else
				{
					cout << "Invalid input" << '\n';
					cont = true;
				}
			}
		}
		else if (choice == 2)
		{
			int temp;
			bool cont2 = true;
			while (cont2)
			{
				cont2 = false;
				cout << "Pick a medication" << '\n';
				cout << "1. Cold Medicine" << '\n' << "2. Allergy Medicine" << '\n' << "3. Green Herb" << '\n' << "4. Red Herb" << '\n' << "5. Blue Herb" << '\n';
				cout << "Select a choice: ";
				cin >> temp;
				if (temp == 1)
					med.coldMedicine();
				else if (temp == 2)
					med.allergyMedicine();
				else if (temp == 3)
					med.greenHerb();
				else if (temp == 4)
					med.redHerb();
				else if (temp == 5)
					med.blueHerb();
				else
				{
					cout << "Invalid input" << '\n';
					cont = true;
				}
			}
		}
		else if (choice == 3)
		{
			int time;
			cout << "How long have you been staying? ";
			cin >> time;
			care.setDays(time);
			cout << "You are charged for $" << care.getCharges();
		}
	}
}