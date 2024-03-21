#include <iostream>
#include "AI/AIController.h"
using namespace std;

int main()
{
    Blackboard* blackboard = new BlackboardTemplate();
    blackboard->SetWorldValue("Is_Hurt", false);
    blackboard->SetWorldValue("Can_See_Player", false);
    blackboard->SetWorldValue("Is_Player_Alive", true);

    vector<BaseGoal*> listOfGoals;
    vector<BaseTask*> listOfTasks;

    BaseGoal* Rest = new BaseGoal();
    Rest->SetPrecondition("Can_See_Player", false, 0);
    Rest->SetPrecondition("Is_Hurt", true, 0);
    Rest->SetObjective("Is_Hurt", false, 0);
    listOfGoals.push_back(Rest);

    BaseGoal* Kill_Player = new BaseGoal();
    Kill_Player->SetPrecondition("Can_See_Player", true, 0);
    Kill_Player->SetPrecondition("Is_Hurt", false, 0);
    Kill_Player->SetObjective("Is_Player_Alive", false, 0);
    listOfGoals.push_back(Kill_Player);

    BaseGoal* Escape = new BaseGoal();
    Escape->SetPrecondition("Can_See_Player", true, 0);
    Escape->SetPrecondition("Is_Hurt", true, 0);
    Escape->SetObjective("Can_See_Player", false, 0);
    listOfGoals.push_back(Escape);

    BaseGoal* Roam = new BaseGoal();
    Roam->SetPrecondition("Can_See_Player", false, 0);
    Roam->SetPrecondition("Is_Hurt", false, 0);
    Roam->SetObjective("Can_See_Player", true, 0);
    listOfGoals.push_back(Roam);

    int effort = 1;
    BaseTask* RestTask = new TaskTemplate1(effort);
    RestTask->SetEffect("Is_Hurt", false, 0);
    listOfTasks.push_back(RestTask);

    BaseTask* AttackTask = new TaskTemplate2(effort);
    AttackTask->SetEffect("Is_Player_Alive", false, 0);
    AttackTask->SetPrecondition("Can_See_Player", true, 0);
    listOfTasks.push_back(AttackTask);

    BaseTask* RunTask = new TaskTemplate3(effort);
    RunTask->SetEffect("Can_See_Player", false, 0);
    RunTask->SetPrecondition("Can_See_Player", true, 0);
    listOfTasks.push_back(RunTask);

    BaseTask* SearchTask = new TaskTemplate4(effort);
    SearchTask->SetEffect("Can_See_Player", true, 0);
    SearchTask->SetPrecondition("Can_See_Player", false, 0);
    listOfTasks.push_back(SearchTask);

    // Effect and the Goals precondition doesn't need a priority

    AIController* controller = new AIController(blackboard, listOfGoals, listOfTasks);

    while (true)
    {
        controller->UpdateController();
    }
}