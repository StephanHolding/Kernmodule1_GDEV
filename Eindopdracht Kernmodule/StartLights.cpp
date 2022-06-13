#include "StartLights.h"

StartLights::StartLights(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{
	stages.push_back(Stage(0, "sprites/lights_0.png"));
	stages.push_back(Stage(0.8, "sprites/lights_1.png"));
	stages.push_back(Stage(1.4, "sprites/lights_2.png"));
	stages.push_back(Stage(1.6, "sprites/lights_3.png"));
	stages.push_back(Stage(1.5, "sprites/lights_4.png"));
	stages.push_back(Stage(1.5, "null"));
	startLightsFinished = false;
}

void StartLights::BeginStartLights()
{
	music.openFromFile("audio/music.ogg");
	music.play();
	started = true;
}

void StartLights::Update(float deltaTime)
{
	if (started)
	{
		timer += deltaTime;

		if (timer >= stages.at(currentLoop).waitTime)
		{
			if (currentLoop != stages.size() - 1)
			{
				LoadSprite(stages.at(currentLoop).fileName);

				currentLoop++;
				timer = 0;
			}
			else
			{
				started = false;
				startLightsFinished = true;
				draw = false;
			}
		}
	}
}

bool StartLights::startLightsFinished = false;

StartLights::Stage::Stage(float waitTime, std::string fileName)
{
	this->waitTime = waitTime;
	this->fileName = fileName;
}
