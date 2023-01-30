#pragma once
class SingletonSimple
{
	static SingletonSimple* singletonSimple;

	SingletonSimple() {}
	SingletonSimple(const SingletonSimple&) = delete;
	SingletonSimple& operator=(SingletonSimple&) = delete;
public:
	static SingletonSimple* GetInstance()
	{
		if (!singletonSimple)
			singletonSimple = new SingletonSimple();
		return singletonSimple;
	}
};



