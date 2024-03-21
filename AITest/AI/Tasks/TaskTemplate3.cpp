#include "TaskTemplate3.h"
#include <iostream>

void TaskTemplate3::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Run" << std::endl;
}


void TaskTemplate3::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Run" << std::endl;
	
}

void TaskTemplate3::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Run" << std::endl;
}
