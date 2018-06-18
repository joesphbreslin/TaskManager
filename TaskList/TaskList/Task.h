#pragma once
#include <string>
#include <iostream>

class Task
{

public:	
	Task();
	~Task();

	std::string GetName();
	void SetName(std::string name);

	std::string GetDescription();
	void SetDescription(std::string decription);

	std::string GetCompany();
	void SetCompany(std::string company);

	int GetETA();
	void SetETA(int eta);

	int GetExpectedLength();
	void SetExpectedLength(int expectedLength);

	bool GetIsComplete();
	void SetIsComplete(bool isComplete);

	void Print();

private:
	std::string Name;
	std::string Description;
	std::string Company;
	int ETA;
	int ExpectedLength;
	bool IsComplete = false;



};

