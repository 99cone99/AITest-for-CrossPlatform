#include "TaskTemplate2.h"
#include <iostream>

void TaskTemplate2::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Attack" << std::endl;
}


void TaskTemplate2::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Attack" << std::endl;
}

void TaskTemplate2::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Attack" << std::endl;
}
