#include "BlackboardTemplate.h"
#include <iostream>




void BlackboardTemplate::UpdateBlackboard()
{
	// Here is where you'll update your blackboards world values.
	// You can create more systems for information gathering, such as sight or hearing.
	char input;
	std::cin >> input;
	if (input == 'a')
	{
		mWorldValues["Is_Hurt"] = !mWorldValues["Is_Hurt"];
	}
	if (input == 'b')
	{
		mWorldValues["Can_See_Player"] = !mWorldValues["Can_See_Player"];

	}
	if (input == 'c')
	{
		mWorldValues["Is_Player_Alive"] = !mWorldValues["Is_Player_Alive"];
	}
	if ()
	{

	}

	for (auto worldvalue : mWorldValues)
	{
		std::cout << worldvalue.first << " " << std::to_string(worldvalue.second) <<  std::endl;
	}
}