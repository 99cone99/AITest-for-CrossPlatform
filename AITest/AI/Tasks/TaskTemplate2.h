#pragma once
#include "../BaseTask.h"

class TaskTemplate2 :
    public BaseTask
{
public:
    TaskTemplate2(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};

