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

class TaskRest :
    public BaseTask
{
public:
    TaskRest(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};


class TaskAttack :
    public BaseTask
{
public:
    TaskAttack(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};

class TaskRun :
    public BaseTask
{
public:
    TaskRun(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};

class TaskSearch :
    public BaseTask
{
public:
    TaskSearch(int effort)
    {
        mEffortValue = effort;
    }
    void EnterAction();
    void RunningAction();
    void ExitingAction();
};



