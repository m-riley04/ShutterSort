#include "sorttimer.h"

SortTimer::SortTimer(std::chrono::milliseconds interval, std::function<void(Anchor)> func, Anchor anchor) {
	this->interval = interval;
	this->func = func;
	this->anchor = anchor;
}

void SortTimer::start() {
	active = true;

	thread = std::thread([=]()
		{
			while (active) {
				std::this_thread::sleep_for(interval);
				func(anchor);
			}
		});
}

void SortTimer::setFunction(std::function<void(Anchor)> func) {
	this->func = func;
}