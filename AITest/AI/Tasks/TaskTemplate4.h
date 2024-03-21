#pragma once
#include "../BaseTask.h"

class TaskTemplate4 :
    public BaseTask
{
public:
    TaskTemplate4(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};

