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
#include <list>
#pragma warning(disable : 4996)
using namespace std;

///////Color Ints
int GreenText = 10;
int CyanText = 11;
int YellowText = 14;
int RedText = 12;
int MagentaText = 13;
///////DataStructures
const int tasksLength = 30; Task tasks[tasksLength];
list<Task> myTasks;
///////Flag
bool isOn = true;
//TODO Test Bugs
//TODO REFACTOR CODE	
//TODO Fix DATA.csv in exe

//EntryPoint
int main()
{	
	SetTitle();
	LoadData();
	while (isOn)
	{
		Menu();
	}
	return 0;
}

void UpdateTask() {

	// print titles
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	list<Task>::iterator outputIt = myTasks.begin();
	int count = 0;
	do {
		Task TempTask;
		TempTask = *outputIt;
		TempTask.PrintTitles(count); count++;
		std::advance(outputIt, 1);
	} while (outputIt != myTasks.end());

	// Ask for index of item you wish to update
	outputIt = myTasks.begin();

	int input;
	std::string prompt = "Input index and press Enter..";
	std::cout << prompt << endl;
	cin >> input;
	input = IntegerValidation(input, prompt);

	if (input < count) {
		std::advance(outputIt, input);
		
	}
	else {
		std::cout << "Bad Value" << std::endl;
		cin.ignore();
		return;
	}
	cin.ignore();
	Task tempTask = *outputIt;

	std::cout << "1.	Title,	2. Description,			3.Company " << endl;
	std::cout << "4.	ETA,	5. ExpectedLength,		6.isComplete " << endl;
	prompt = "Input index to update property >>>\t";
	std::cout << prompt << endl;
	cin >> input;
	input = IntegerValidation(input, prompt);
	string text;
	int num;
	cin.ignore();
	switch (input) {
	case 1 :
		std::cout << "Enter task title: (string) >>>\t" << std::flush;
		std::getline(std::cin, text);
		tempTask.SetName(text);
		break;
	case 2 :
		std::cout << "Enter task Description: (string) >>>\t" << std::flush;
		std::getline(std::cin, text);
		tempTask.SetDescription(text);
		break;
	case 3 :
		std::cout << "Enter task Company: (string) >>>\t" << std::flush;
		std::getline(std::cin, text);
		tempTask.SetCompany(text);
		break;
	case 4 :
		prompt = "Enter task ETA: (INT) >>>\t";
		std::cout << prompt << std::flush;
		std::cin >> num;
		tempTask.SetETA(IntegerValidation(num,prompt));
		break;
	case 5 :
		prompt = "Enter task ExpectedLength: (INT) >>>\t";
		std::cout <<prompt << std::flush;
		std::cin >> num;
		tempTask.SetExpectedLength(IntegerValidation(num, prompt));
		break;
	case 6 :
		prompt = "Enter task isComplete: (INT) >>>\t";
		std::cout << prompt << std::flush;
		std::cin >> num;
		tempTask.SetIsComplete(IntegerValidation(num, prompt));
		break;
	default :
		std::cout << "BAD VALUE" << std::flush;
		cin.ignore();
		return;
		break;
	}

	*outputIt = tempTask;
	cin.ignore();
	cout << "Updated" << endl;

	
	// Ask for index of Heading you wish to update
	// founctions for all headings;

	return;
}

void SaveAndExit() {
	list<Task>::iterator outputIt = myTasks.begin();
	std::ofstream op("DATA.csv");
	do {
		Task TempTask;
		TempTask = *outputIt;
		op << TempTask.GetName() << ',' << TempTask.GetCompany() << ',' << TempTask.GetDescription() << ',' << TempTask.GetETA() << ',' << TempTask.GetExpectedLength() << ',' << TempTask.GetIsComplete() << std::endl;
		std::advance(outputIt, 1);
	} while (outputIt != myTasks.end());
	isOn = false;
	return;
}

void RemoveTask() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	list<Task>::iterator outputIt = myTasks.begin();
	int count = 0;
	do {
		Task TempTask;
		TempTask = *outputIt;
		TempTask.PrintTitles(count); count++;
		std::advance(outputIt, 1);
	} while (outputIt != myTasks.end());

	outputIt = myTasks.begin();

	int input;
	std::string prompt = "Input index and press Enter..";
	std::cout << prompt << endl;
	cin >> input;
	input = IntegerValidation(input, prompt);

	std::advance(outputIt, input);
	myTasks.erase(outputIt);
	cin.ignore();

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
	Task tempTask;
	//Display Index
	std::cout << "\n";
	std::cout << "Index > " << index << std::endl;

	//Set Title
	std::string Title;
	std::cout << "Enter task title: (string) >>>\t" << std::flush;
	std::getline(std::cin, Title);
	
	//std::cin >> Title;
	//std::cin.ignore();
	tempTask.SetName(Title);

	//Set Description
	std::string Description;
	std::cout << "Enter task description: (string) >>>\t" << std::flush;
	std::getline(std::cin, Description);
	tempTask.SetDescription(Description);

	//Set Company
	std::string Company;
	std::cout << "Enter task company: (string) >>>\t" << std::flush;
	std::getline(std::cin, Company);
	tempTask.SetCompany(Company);	

	//SetETA
	int ETA;
	std::string ETAPrompt = "Enter task ETA: (Date Format integer 0112) >>>\t";
	std::cout << ETAPrompt << std::flush;
	std::cin >> ETA;	
	tempTask.SetETA(IntegerValidation(ETA, ETAPrompt));
	std::cin.ignore();

	//SetExpectedLength
	int ExpectedLength;
	std::string ExpectedLengthPrompt = "Enter task Length in hours: (integer) >>>\t";
	std::cout << ExpectedLengthPrompt << std::flush;
	std::cin >> ExpectedLength;
	tempTask.SetExpectedLength(IntegerValidation(ExpectedLength, ExpectedLengthPrompt));
	std::cin.ignore();

	//Set isComplete 0 or 1
	int IsComplete;
	std::string IsCompletePrompt = "Enter task completion status: (1 for complete, 0 for pending) >>>\t";
	std::cout << IsCompletePrompt << std::flush;
	std::cin >> IsComplete;
	tempTask.SetIsComplete(IntegerValidation(IsComplete, IsCompletePrompt));
	std::cin.ignore();

	myTasks.push_back(tempTask);
	//Print all
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MagentaText);
	tempTask.Print();

	return;
}

int IntegerValidation(int input, std::string userPrompt) {

	while (std::cin.fail()) {
		std::cout << userPrompt << std::flush;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;
	}
	return input;
}
// Updated for List[X]
void ViewAllTasks() {

	int count = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CyanText);
	list<Task>::iterator outputIt = myTasks.begin();

	do {
		Task TempTask;
		TempTask = *outputIt;
		TempTask.PrintTitles(count); count++;
		std::advance(outputIt, 1);			
	} while (outputIt != myTasks.end());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

	std::string prompt = "Enter Index to view more information.";
	std::cout << prompt << std::endl;
	int input;
	std::cin >> input;
	input = IntegerValidation(input, prompt);

	outputIt = myTasks.begin();
	for (int i = 0; i < count; i++) {
		if (input == i) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MagentaText);
			std::advance(outputIt, i);
			Task TempTask = *outputIt;
			TempTask.Print();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		}
		else {
			std::cout << "Incorrect Index" << endl;
		}		
	}
	std::cin.ignore();
	return;
}
//Updated for List[X]
void LoadData() {

	string fileName = "DATA.csv";
	std::ifstream ip(fileName);
	if (!ip.is_open()) {
		 std::cout << "ERROR: File Open" << std::endl;
	 }
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

		 Task newTask;
		 newTask.SetName(_name);
		 newTask.SetCompany(_company);
		 newTask.SetDescription(_description);
		 newTask.SetETA(i_eta);
		 newTask.SetExpectedLength(i_expectedLength);
		 i_isComplete == 1 ? newTask.SetIsComplete(true) : newTask.SetIsComplete(false);

		if (newTask.GetName() != "") {
			 myTasks.push_back(newTask);
		 }
	 }
	 ip.close();
	 
	return;
}

void SortData() {
	//TODO WEIGHT LIST based on importance, write algorithm based on distribution of tasks via company and urgency
	return;
}

void Time() {
	time_t now = time(0);
	struct tm t = *localtime(&now);	
	std::cout << "Current time : " << t.tm_hour << "/" << t.tm_min << std::endl;
	return;
}

void SetTitle() {
	SetConsoleTitle(TEXT("Joey's 'Get After It' Management System"));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}



