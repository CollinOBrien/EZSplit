#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <sstream>

using namespace sf;
using namespace std;

//Stopwatch class inherits from the SFML Clock class
//Clock class has two functions
//getElapsedTime which will get the time elapsed after starting
//and restart which will restart the timer

class Timer : public Clock
{
public:
	void restartTime(RenderWindow window); //Restarts the stopwatch
private:
	int timeMS = 0; //Current time in milliseconds
	int seconds;
	int minutes;
	int hours;

};

void Timer::restartTime(RenderWindow window)
{
	timeMS = 0;
}