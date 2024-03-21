#pragma once
#include "../BaseTask.h"

class TaskTemplate1 :
    public BaseTask
{
public:
    TaskTemplate1(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};

