#pragma once
#include "../BaseTask.h"

class TaskTemplate :
    public BaseTask
{
public:
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};

