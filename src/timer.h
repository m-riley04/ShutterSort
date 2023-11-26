#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>


class Timer
{
protected:
	std::thread thread;
	bool active = false;
	std::chrono::milliseconds interval;
	std::function<void()> func;

public:
	Timer();
	Timer(std::chrono::milliseconds interval, std::function<void()> func);
	~Timer();
	virtual void start();
	void stop();

	void setFunction(std::function<void()> func);
	virtual void setInterval(std::chrono::milliseconds interval);
};