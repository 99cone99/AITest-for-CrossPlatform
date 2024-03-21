#include "AIController.h"

AIController::AIController(Blackboard* inputBlackboard, std::vector<BaseGoal*> goalList, std::vector<BaseTask*> taskList)
{
	mCurrentBlackboard = inputBlackboard;
	mGoalList = goalList;
	mTaskList = taskList;
}

AIController::~AIController()
{
	for (auto taskToBeDeleted : mTaskList)
	{
		delete(taskToBeDeleted);
	}

	for (auto goalToBeDeleted : mGoalList)
	{
		delete(goalToBeDeleted);
	}

	delete(mCurrentBlackboard);

	// Delete all tasks, goals and the blackboard
}

void AIController::UpdateController()
{
	mCurrentBlackboard->UpdateBlackboard();

	SetCurrentGoal(); // Searches through all of the goals and sets the highest priority goal possible as its current objective
	UpdateTaskList(); // Takes the goal and finds a task that satisfys its objective, takes that task as the new goal and continues until it has a path it can complete

	if (mCurrentTask != mCurrentTaskPlan.back()) // If the task has changed (Might not work, should do though) then run the old tasks Exit and the new tasks Enter before running.
	{
		if (mCurrentTask != nullptr)
			mCurrentTask->ExitingAction();
		mCurrentTask = mCurrentTaskPlan.back(); // Stops the task from updating the actual object if its not been changed
		mCurrentTask->EnterAction();
	}
	
	mCurrentTask->RunningAction();
}

bool sortByPriorityS(std::pair<std::string, prioritiedValue> a, std::pair<std::string, prioritiedValue> b)
{
	return (a.second.mPriority < b.second.mPriority); // Allows the sort command to sort by a prioritiedValue's priority
}

bool sortByPriorityB(std::pair<BaseGoal*, prioritiedValue> a, std::pair<BaseGoal*, prioritiedValue> b)
{
	return (a.second.mPriority < b.second.mPriority); // Allows the sort command to sort by a prioritiedValue's priority
}

void AIController::SetCurrentGoal() // 115255
{
	std::vector<std::pair<BaseGoal*, prioritiedValue>> goalCheckList;
	//BaseGoal* highestPrioGoal{};
	int highestPrio = -1;

	for (auto goalBeingChecked : mGoalList) // This section just takes all goals that can be done from the world state and puts them into a vector to be sorted later
	{
		bool tempSet = true;
		for (auto preconditionBeingChecked : goalBeingChecked->GetFullPreconditionMap())
		{
			if (mCurrentBlackboard->GetWorldValue(preconditionBeingChecked.first) != preconditionBeingChecked.second.mValue) // Checking whether the goals should be accomplished
			{
				tempSet = false;
			}
		}
		if (tempSet)
		{
			goalCheckList.push_back(std::make_pair(goalBeingChecked, goalBeingChecked->GetObjective().second));
		}
	}

	/*for (auto goalPrioChecked : goalCheckList)
	{
		if (goalPrioChecked->GetObjective().second.mPriority < highestPrio)
		{
			highestPrioGoal = goalPrioChecked;
			highestPrio = goalPrioChecked->GetPriority();
		}
	}*/

	// Old code for sorting by priority ^^^
	

	std::sort(goalCheckList.begin(), goalCheckList.end(), sortByPriorityB); // Sorts the vector by their priority.
	mCurrentGoal = goalCheckList.front().first; // If the sorting thing here doesn't work then you have to re-add a priority int to BaseGoal
	goalCheckList.clear();
}

void AIController::UpdateTaskList()
{
	std::pair<std::string, prioritiedValue> goalCondition = mCurrentGoal->GetObjective();
	std::vector<BaseTask*> taskCheckList;
	std::vector<std::pair<std::string, prioritiedValue>> preconditionStack; // Used to keep track of the priority of the next conditions to be added to the condition stack
	std::vector<std::pair<std::string, prioritiedValue>> conditionStack; // Used to keep track of the priority of the next conditions to be added to the condition stack

	// mCurrentTaskPlan - is the current task stack that will be actually executed

	conditionStack.push_back(goalCondition); // Put the current goal's condition onto the stack to find a task that can do it

	do
	{
		std::pair<std::string, prioritiedValue> currentCondition = conditionStack.back();

		// Start of "pathfinding"

		for (auto taskBeingChecked : mTaskList) // Find a task that when executed will fulfull the current condition
		{
			for (auto effectBeingChecked : taskBeingChecked->GetFullEffectMap())
			{
				if (effectBeingChecked.first == currentCondition.first && effectBeingChecked.second.mValue == currentCondition.second.mValue)
				{
					taskCheckList.push_back(taskBeingChecked);
				}
			}
		}

		// This part below and above should be a temporary fix for effort valuing and pathfinding
		// It doesn't really check anything based on total path effort but just picks the lowest effort tast as it iterates.
		// Can be swapped out later (With the code section above) relatively easily with some sort of pathfinding algorithm if needed - Dan

		BaseTask* lowestEffortTask = taskCheckList.front();
		for (auto taskBeingEffortChecked : taskCheckList)
		{
			if (taskBeingEffortChecked->GetEffort() < lowestEffortTask->GetEffort())
				taskBeingEffortChecked = lowestEffortTask;
		}

		mCurrentTaskPlan.push_back(lowestEffortTask);
		conditionStack.pop_back();

		// End of effort + "Pathfinding"


		// This section onwards shouldn't be changed unless you can make it more efficient 

		if (lowestEffortTask->GetFullPreconditionMap().empty() != true) // If the task being completed doesn't have any conditions then just move on
		{
			for (auto currentPrecondition : lowestEffortTask->GetFullPreconditionMap()) // If it does then add them to the precondition stack, to be sorted by their priority and then added to the actual condition stack
			{
				if (mCurrentBlackboard->GetWorldValue(currentPrecondition.first) != currentPrecondition.second.mValue)
				{
					preconditionStack.push_back(currentPrecondition);
				}
			}

			std::sort(preconditionStack.begin(), preconditionStack.end(), sortByPriorityS); // Sorts the vector by their priority.

			size_t conditionLoopIterator = preconditionStack.size();

			for (size_t i = 0; i < conditionLoopIterator; i++) // Shove all of the conditions onto the stack to be iterated and found tasks that could complete them
			{
				conditionStack.push_back(preconditionStack.back());
				preconditionStack.pop_back();
			}
		}

		preconditionStack.clear();

	} while (conditionStack.empty() != true); // Continue this stack as long as there are conditions to be found
}