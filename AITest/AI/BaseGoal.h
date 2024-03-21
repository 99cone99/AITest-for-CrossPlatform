#pragma once
#include <vector>
#include <map>
#include <string>
#include "Blackboard.h"

class BaseGoal
{
public:
	BaseGoal() {}
	~BaseGoal() {}

	void SetPrecondition(std::string reference, bool value, int priority)
	{
		prioritiedValue precon;
		precon.mValue = value;
		precon.mPriority = priority;
		mPreconditions[reference] = precon;
	}
	bool GetPrecondition(std::string reference)
	{
		return mPreconditions[reference].mValue;
	}
	std::map<std::string, prioritiedValue> GetFullPreconditionMap()
	{
		return mPreconditions;
	}

	void SetObjective(std::string reference, bool value, int priority)
	{
		prioritiedValue prioValue;
		prioValue.mValue = value;
		prioValue.mPriority = priority;
		mGoal = std::make_pair(reference, prioValue);
	}
	std::pair<std::string, prioritiedValue> GetObjective()
	{
		return mGoal;
	}

private:
	std::map<std::string, prioritiedValue> mPreconditions;
	std::pair<std::string, prioritiedValue> mGoal;
};