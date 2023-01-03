#ifndef _TIMER_H
#define _TIMER_H

#include "Timer.h"
#include "SDL.h"

class Timer
{
public:
	//static Timer* Instance; cant use static?
	
	static Timer* Instance();
	static void Release();

	void Reset();

	float GetDeltaTime();
	void TimeScale(float t);
	float TimeScale();
	void Update();

	const float FPS = 60;
	const float FRAME_PER_SEACOND = FPS/1000.0f;
	const float FRAME_DELAY = FPS/1000.0f;
	const float MAX_DELTA_TIME = 1.5f;
	//static Timer& getTimerInstance();
	//
	//Timer(Timer const&) = delete; // makes so we cant copy objectinstance
	//void operator=(Timer const&) = delete; // remove assigment operator to singelton



private:
	Timer();
	~Timer();

	static Timer* tInstance;

	int prevTicksTest;
	int elapsedTicks;

	float deltaTime;
	float timeScale;
	
};
#endif
