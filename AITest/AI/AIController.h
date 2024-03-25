#pragma once
#include <algorithm>

#include "BaseGoal.h"
#include "BaseTask.h"
#include "Blackboard.h"
#include "Blackboards/BlackboardTemplate.h"
#include "Tasks/TaskTemplate.h"

class AIController
{
public:
	AIController(Blackboard* inputBlackboard, std::vector <BaseGoal*> goalList, std::vector <BaseTask*> taskList);
	~AIController();

	void UpdateController();
	void SetCurrentGoal();
	void UpdateTaskList();

private:
	Blackboard* mCurrentBlackboard;
	BaseTask* mCurrentTask;
	BaseGoal* mCurrentGoal;
	std::vector<BaseTask*> mTaskList; // Entire task list 
	std::vector<BaseGoal*> mGoalList; // Entire goal list
	std::vector<BaseTask*> mCurrentTaskPlan; // The current list of tasks to be executed
};

