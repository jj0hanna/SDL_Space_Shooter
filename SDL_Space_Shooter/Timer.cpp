#include "Timer.h"
#include <iostream>

Timer* Timer::tInstance = NULL;

Timer* Timer::Instance()
{
	if (tInstance == NULL)
	{
		tInstance = new Timer();
	}
	return tInstance;
}

void Timer::Release()
{
	delete tInstance;
	tInstance = NULL;
}
Timer::Timer()
{
	if (SDL_Init(SDL_INIT_TIMER) < 0)
	{
		std::cout << "ERROR" << SDL_GetError << std::endl;
	}
	Reset();
	
	elapsedTicks = 0;
	deltaTime = 0.0f;
}

Timer::~Timer()
{
}

void Timer::Reset()
{
	prevTicksTest = SDL_GetPerformanceCounter();

}

float Timer::GetDeltaTime()
{
	return deltaTime;
}

void Timer::TimeScale(float t)
{
	timeScale = t;
}

float Timer::TimeScale()
{
	return timeScale;
}

void Timer::Update()
{
	
	Uint64 ticks = SDL_GetPerformanceCounter();
	deltaTime = (float)(ticks - prevTicksTest) / SDL_GetPerformanceFrequency();

	if (deltaTime > MAX_DELTA_TIME)
	{
		deltaTime = MAX_DELTA_TIME;
	}

	prevTicksTest = ticks;
}
