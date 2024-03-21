#pragma once
#include <vector>
#include <map>
#include <string>

struct prioritiedValue
{
	bool mValue;
	int mPriority;
};

// ^^^ Needed so that tasks with multiple conditions that need to be met are done in the correct order.
// For example, opening a door. The AI needs a key (has_key=true) and to be near the door (near_door=true).
// Without priority the AI may choose to go to the door first, without the key, and get stuck forever.

class Blackboard
{
public:
	Blackboard();
	~Blackboard(); 

	bool GetWorldValue(std::string reference)
	{
		return mWorldValues[reference];
	}

	void SetWorldValue(std::string reference, bool value)
	{
		mWorldValues[reference] = value;
	}

	std::map<std::string, bool> GetFullWorldValueMap()
	{
		return mWorldValues;
	}

	virtual void UpdateBlackboard();

protected:
	std::map<std::string, bool> mWorldValues;
};

