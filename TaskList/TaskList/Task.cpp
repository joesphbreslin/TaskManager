#include "stdafx.h"
#include "Task.h"
#include <string>
#include <iostream>

//
Task::Task()
{
}

Task::~Task()
{
}

std::string Task::GetName() 
{
	return Task::Name;
}

void Task::SetName(std::string name)
{
	Task::Name = name;
}

std::string Task::GetDescription() 
{
	return Description;
}

void Task::SetDescription(std::string description) 
{
	Task::Description = description;
}

std::string Task::GetCompany() 
{
	return Task::Company;
}

void Task::SetCompany(std::string company) 
{
	Task::Company = company;
}

int Task::GetETA() 
{
	return Task::ETA;
}

void Task::SetETA(int eta) 
{
	Task::ETA = eta;
}

int Task::GetExpectedLength() 
{
	return Task::ExpectedLength;
}

void Task::SetExpectedLength(int expectedLength) 
{
	Task::ExpectedLength = expectedLength;
}

bool Task::GetIsComplete() {
	return Task::IsComplete;
}

void Task::SetIsComplete(bool isComplete) {
	Task::IsComplete = isComplete;
}



void Task::Print() {
	std::cout << std::endl;
	std::cout << "Task name:\t\t" << Task::Name << std::endl;
	std::cout << "Company:\t\t" << Task::Company << std::endl;
	std::cout << "Expected length(h):\t" << Task::ExpectedLength << std::endl;
	std::cout << "Due date:\t\t" << Task::ETA << std::endl;
	std::string status = Task::IsComplete == true ? "Complete" : "Pending";
	std::cout << "Completion status:\t" << status << std::endl;
	std::cout << "Description:\n\t\t\t" << Task::Description << std::endl;
	
}

