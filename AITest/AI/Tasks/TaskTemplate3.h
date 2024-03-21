#pragma once
#include "../BaseTask.h"

class TaskTemplate3 :
    public BaseTask
{
public:
    TaskTemplate3(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};

