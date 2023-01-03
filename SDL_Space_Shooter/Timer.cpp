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
	//timeScale = 1.0f;
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
	// elapesTicks = prevtics

	////elapsedTicks = SDL_GetPerformanceCounter() - prevTicksTest;
	//deltaTime = elapsedTicks * 0.001f;
	Uint64 ticks = SDL_GetPerformanceCounter();
	deltaTime = (float)(ticks - prevTicksTest) / SDL_GetPerformanceFrequency();
	////deltaTime = elapsedTicks * FRAME_PER_SEACOND;
	if (deltaTime > MAX_DELTA_TIME)
	{
		deltaTime = MAX_DELTA_TIME;
	}
	//
	//SDL_Delay(floor(16.666f - elapsedTicks)); // is this two the same? cap the fps to 60. Is this right?
	//SDL_Delay(FRAME_DELAY); // shuóuld have or not?
	// 
	//std::cout << "Current FPS: " << floor(16.666f - deltaTime) << std::endl;
	prevTicksTest = ticks;
	
	
}

//Timer& Timer::getTimerInstance()
//{
//	// TODO: insert return statement here
//}
//