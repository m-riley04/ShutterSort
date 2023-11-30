#pragma once
#include "timer.h"
#include "anchor.h"
class SortTimer :
    public Timer
{
    Anchor anchor;
    std::function<void(Anchor)> func;

public:
    SortTimer(std::chrono::milliseconds interval, std::function<void(Anchor)> func, Anchor anchor);
    void start();
    void setFunction(std::function<void(Anchor)> func);
    void setAnchor(Anchor& anchor);
};

