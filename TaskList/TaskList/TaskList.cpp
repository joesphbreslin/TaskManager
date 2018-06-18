// TaskList.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include "stdafx.h"
#include "Task.h"
#include "Functions.h"
#include <time.h>
#include <fstream>
#pragma warning(disable : 4996)
/*
1. Add Task 
2. Update Task
3. View Tasks
4. Remove Task
5. Save and Exit */
using namespace std;
const int tasksLength = 30; Task tasks[tasksLength];
bool isOn = true;

int main()
{
	OpeningTitle();
	LoadData();
	while (isOn)
	{
		Menu();
	}
	
    return 0;
}

void Menu() {
	Time();
	int input;
	std::cout << "Type index and enter to select menu option >" << std::endl;
	std::cout << std::endl;
	std::cout << "1.\t" << "Add task" << std::endl;
	std::cout << "2.\t" << "Update task" << std::endl;
	std::cout << "3.\t" << "View all tasks" << std::endl;
	std::cout << "4.\t" << "Remove task" << std::endl;
	std::cout << "5.\t" << "Save and exit" << std::endl;
	std::cout << ">>>\t" << std::flush; std::cin >> input;

	switch (input) {
	case 0:
		break;
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
		break;
	}
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
	std::string Title;
	std::cout << "Index > " <<index << " Enter task title: >>>\t" << std::flush;
	std::cin >> Title;
	tasks[index].SetName(Title);
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

void SaveAndExit() {
	isOn = false;
	return;
}
void LoadData() {
	 std::ifstream ip("DATA.csv");
	 if (!ip.is_open()) {
		 std::cout << "ERROR: File Open" << std::endl;
	 }
	 int count = 0;
	 while (!ip.eof()) {
		 std::string _name, _company, _description, _ETA, _expectedLength, _isComplete;
		 getline(ip, _name, ',');
		 getline(ip, _company, ',');
		 getline(ip, _description, ',');
		 getline(ip, _ETA, ',');
		 getline(ip, _expectedLength, ',');
		 getline(ip, _isComplete, '\n');

		 std::string::size_type sz;
		 int i_eta = stoi(_ETA, &sz);
		 int i_expectedLength = stoi(_expectedLength, &sz);
		 int i_isComplete = stoi(_isComplete, &sz);

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



