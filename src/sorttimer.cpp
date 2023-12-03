#include "sorttimer.h"

SortTimer::SortTimer() {}

SortTimer::SortTimer(std::chrono::milliseconds interval, std::function<void(Anchor)> func, Anchor anchor) {
	this->interval = interval;
	this->func = func;
	this->anchor = anchor;
}

SortTimer::~SortTimer() {}

void SortTimer::start() {
	if (active != true) {
		active = true;

		thread = std::thread([=]()
			{
				while (active) {
					std::this_thread::sleep_for(interval);
					func(anchor);
				}
			});
	} else {
		std::cout << "ERROR: Timer is already started." << std::endl;
	}
}

void SortTimer::setFunction(std::function<void(Anchor)>& func) {
    this->func = func;
}

void SortTimer::setAnchor(Anchor& anchor) {
	this->anchor = anchor;
