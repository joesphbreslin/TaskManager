// TaskList.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include "stdafx.h"
#include "Task.h"
#include "Functions.h"
#include <time.h>
#include <fstream>
#include <sstream>
#include <Windows.h>
#pragma warning(disable : 4996)
using namespace std;
/*
1. Add Task 
2. Update Task
3. View Tasks
4. Remove Task
5. Save and Exit */

///////Color Ints
int GreenText = 10;
int CyanText = 11;
int YellowText = 14;
int RedText = 12;
int MagentaText = 13;


const int tasksLength = 30; Task tasks[tasksLength];
bool isOn = true;

int main()
{
	SetConsoleTitle(TEXT("Joey's 'Get After It' Management System"));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	OpeningTitle();
	LoadData();
	while (isOn)
	{
		Menu();
	}
	
    return 0;
}

void SaveAndExit() {
	std::ofstream op("DATA.csv");
	int i = 0;	
	while (tasks[i].GetName() != ""){
		op << tasks[i].GetName() << ',' << tasks[i].GetCompany() << ',' << tasks[i].GetDescription() << ',' << tasks[i].GetETA() << ',' << tasks[i].GetExpectedLength() << ',' << tasks[i].GetIsComplete() << std::endl;
		i++;
	}
	isOn = false;
	return;
}

void Menu() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	Time();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GreenText);
	std::cout << "Type index and enter to select menu option >" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	std::cout << "1. Add task\t" << "2. Update task\t" << "3.View tasks\t" << "4. Remove task" << std::endl;
	std::cout << "5. Save and exit" << std::endl;
	std::cout << ">>>\t" << std::flush; 

	string str;
	std::getline(std::cin, str);
	stringstream ss;
	ss << str;
	int input;
	ss >> input;

	switch (input) {
	case 1:
		AddNewTask();
		break;
	case 2:
		UpdateTask();
		break;
	case 3:
		ViewAllTasks();
		break;
	case 4:
		RemoveTask();
		break;
	case 5:
		SaveAndExit();
		break;
	default:
		Default();
		break;
	}
	return;
}

void Default() {
	std::cout << "Wrong Value..." << endl;
	return;
}

void AddNewTask() {
	int index;
	for (int i = 0; i < tasksLength; i++) {
		if (tasks[i].GetName() == "") {
			index = i;
			break;
		}
	}
	//Display Index
	std::cout << "\n";
	std::cout << "Index > " << index << std::endl;

	//Set Title
	std::string Title;
	std::cout << "Enter task title: (string) >>>\t" << std::flush;
	std::cin >> Title;
	std::cin.ignore();
	tasks[index].SetName(Title);

	//Set Description
	std::string Description;
	std::cout << "Enter task description: (string) >>>\t" << std::flush;
	std::getline(std::cin, Description);
	tasks[index].SetDescription(Description);

	//Set Company
	std::string Company;
	std::cout << "Enter task company: (string) >>>\t" << std::flush;
	std::getline(std::cin, Company);
	tasks[index].SetCompany(Company);

	
	//SetETA
	int ETA;
	std::cout << "Enter task ETA: (Date Format integer 0112) >>>\t" << std::flush;
	std::cin >> ETA;
	tasks[index].SetETA(ETA);
	std::cin.ignore();

	//SetExpectedLength
	int ExpectedLength;
	std::cout << "Enter task Length in hours: (integer) >>>\t" << std::flush;
	std::cin >> ExpectedLength;
	tasks[index].SetExpectedLength(ExpectedLength);
	std::cin.ignore();

	//Set isComplete 0 or 1
	int IsComplete;
	std::cout << "Enter task completion status: (1 for complete, 0 for pending) >>>\t" << std::flush;
	std::cin >> IsComplete;
	tasks[index].SetIsComplete(IsComplete);	
	std::cin.ignore();

	//Print all
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MagentaText);
	tasks[index].Print();
	return;
}

void UpdateTask() {
	return;
}

void ViewAllTasks() {
	int count = 0;
	while (tasks[count].GetName() != "") {
		tasks[count].Print();
		count++;
	}
	return;
}

void RemoveTask() {
	return;
}


void LoadData() {
	 std::ifstream ip("DATA.csv");
	 if (!ip.is_open()) {
		 std::cout << "ERROR: File Open" << std::endl;
	 }
	 int count = 0;
	 while (!ip.eof()) {
		 int i_eta = 0, i_expectedLength = 0, i_isComplete = 0;
		 std::string _name, _company, _description, _ETA, _expectedLength, _isComplete;

		 getline(ip, _name, ',');
		 getline(ip, _company, ',');
		 getline(ip, _description, ',');
		 getline(ip, _ETA, ',');
		 getline(ip, _expectedLength, ',');
		 getline(ip, _isComplete, '\n');

		 std::stringstream c_eta(_ETA); 
		 std::stringstream c_expectedLength(_expectedLength); 
		 std::stringstream c_isComplete(_isComplete); 
		 c_eta >> i_eta;
		 c_expectedLength >> i_expectedLength;
		 c_isComplete >> i_isComplete;

		 tasks[count].SetName(_name);
		 tasks[count].SetCompany(_company);
		 tasks[count].SetDescription(_description);
		 tasks[count].SetETA(i_eta);
		 tasks[count].SetExpectedLength(i_expectedLength);
		 i_isComplete == 1 ? tasks[count].SetIsComplete(true) : tasks[count].SetIsComplete(false); 
		// tasks[count].Print();
		 count += 1;
	 }
		/* cout << _name << _company << _description <<_ETA <<_expectedLength<<_isComplete << endl;*/ 	 
	 ip.close();

	return;
}

void SortData() {
	return;
}

void Time() {
	time_t now = time(0);
	struct tm t = *localtime(&now);	
	std::cout << "Current time : " << t.tm_hour << "/" << t.tm_min << std::endl;
	return;
}

void OpeningTitle() {

}



