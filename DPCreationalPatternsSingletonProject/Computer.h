#pragma once
#include <iostream>
#include <mutex>

std::mutex m;

class OS
{
	static OS* osPtr;
	std::string name;

	OS(std::string name) : name{ name } {}
public:
	std::string& Name() { return name; }

	static OS* GetOs(std::string name)
	{
		std::lock_guard<std::mutex> l(m);
		if (!osPtr)
			osPtr = new OS(name);
		return osPtr;
	}
};

class Computer
{
	OS* os;
public:
	OS*& Os() { return os; }
	void Launch(std::string osName)
	{
		os = OS::GetOs(osName);
	}
};

