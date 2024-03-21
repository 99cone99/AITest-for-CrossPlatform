#include "TaskTemplate1.h"
#include <iostream>

void TaskTemplate1::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Rest" << std::endl;
}


void TaskTemplate1::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Rest" << std::endl;
}

void TaskTemplate1::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Rest" << std::endl;
}
