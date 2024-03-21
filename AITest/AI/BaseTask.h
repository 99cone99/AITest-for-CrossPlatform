#pragma once
#include <vector>
#include <map>
#include <string>
#include "Blackboard.h"

class BaseTask
{
public:
	BaseTask() 
	{
		mEffortValue = 0;
	}
	~BaseTask() {}

	virtual void EnterAction();
	virtual void RunningAction();
	virtual void ExitingAction();

	int GetEffort()
	{
		return mEffortValue;
	}

	void SetPrecondition(std::string reference, bool value, int priority)
	{
		prioritiedValue precon;
		precon.mValue = value;
		precon.mPriority = priority;
		mPreconditions[reference] = precon;
	}
	prioritiedValue GetPrecondition(std::string reference)
	{
		return mPreconditions[reference];
	}
	std::map<std::string, prioritiedValue> GetFullPreconditionMap()
	{
		return mPreconditions;
	}

	void SetEffect(std::string reference, bool value, int priority)
	{
		prioritiedValue effect;
		effect.mValue = value;
		effect.mPriority = priority;
		mEffects[reference] = effect;
	}
	bool GetEffect(std::string reference)
	{
		return mEffects[reference].mValue;
	}
	std::map<std::string, prioritiedValue> GetFullEffectMap()
	{
		return mEffects;
	}

protected:
	int mEffortValue;
	std::map<std::string, prioritiedValue> mEffects;
	std::map<std::string, prioritiedValue> mPreconditions;
};