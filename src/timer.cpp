#include "timer.h"

Timer::Timer() {}

Timer::Timer(std::chrono::milliseconds interval, std::function<void()> func) 
	: interval(interval), func(func) {}

Timer::~Timer() {}

void Timer::start() {
	active = true;

	thread = std::thread([=]()
	{
		while (active) {
			std::this_thread::sleep_for(interval);
			func();
		}
	});
}

void Timer::stop() {
	active = false;
	if (thread.joinable()) { thread.join(); }
}

void Timer::setInterval(std::chrono::milliseconds interval) {
	this->interval = interval;
}

void Timer::setFunction(std::function<void()> func) {
	this->func = func;
}