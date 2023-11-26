#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>



class Application
{
	private:
		

	public:
		void run();
};
bool sort_int(int target, int minRange, int maxRange);
bool sort_double(double target, double minRange, double maxRange);
bool sort_string(std::string target, std::string str);

#endif