#include "TaskTemplate.h"
#include <iostream>

void TaskTemplate::EnterAction()
{
	// This code will run when this task is entered.
}
void TaskTemplate::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
}
void TaskTemplate::ExitingAction()
{
	// This code runs when the task is exited.
}

// REST ACTION

void TaskRest::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Rest" << std::endl;
}
void TaskRest::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Rest" << std::endl;
}
void TaskRest::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Rest" << std::endl;
}

// ATTACK ACTION

void TaskAttack::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Attack" << std::endl;
}
void TaskAttack::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Attack" << std::endl;
}
void TaskAttack::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Attack" << std::endl;
}

// RUN AWAY ACTION

void TaskRun::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Run" << std::endl;
}
void TaskRun::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Run" << std::endl;
}
void TaskRun::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Run" << std::endl;
}

// SEARCH ACTION

void TaskSearch::EnterAction()
{
	// This code will run when this task is entered.
	std::cout << "Entered Search" << std::endl;
}
void TaskSearch::RunningAction()
{
	// This is the main update loop for a task. Using the event system, send events for the character to react to.
	std::cout << "Running Search" << std::endl;
}
void TaskSearch::ExitingAction()
{
	// This code runs when the task is exited.
	std::cout << "Exited Search" << std::endl;
}