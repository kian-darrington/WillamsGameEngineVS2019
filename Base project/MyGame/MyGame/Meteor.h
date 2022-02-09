#pragma once

#include "Engine/GameEngine.h"

class Meteor : public GameObject {
public:
	Meteor(sf::Vector2f pos);

	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
	int yMove = -10 + rand() % 20;
};

typedef std::shared_ptr<Meteor> MeteorPtr;