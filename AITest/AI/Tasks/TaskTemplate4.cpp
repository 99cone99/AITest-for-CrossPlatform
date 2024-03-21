#include "TaskTemplate4.h"
#include <iostream>

void TaskTemplate4::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Search" << std::endl;
}


void TaskTemplate4::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Search" << std::endl;
}

void TaskTemplate4::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Search" << std::endl;
}
