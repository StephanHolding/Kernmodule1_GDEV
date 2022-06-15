#pragma once
#include "Object.h"
#include "SFML/Audio.hpp"

class StartLights : public Object
{
public:

	class Stage
	{
	public:
		Stage(float waitTime, const std::string& fileName);

		float waitTime = 1.2;
		std::string fileName;
	};

	StartLights(const std::string& objectName, const CustomVector2& position);

	static bool startLightsFinished;

	void BeginStartLights();

private:

	std::vector<Stage> stages;
	int currentLoop = 0;
	float timer = 0;
	bool started = false;
	sf::Music music;


	virtual void Update(float deltaTime) override;

};

