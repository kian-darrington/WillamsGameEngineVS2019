#include "Meteor.h"

const float BASE_SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos) {
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
}

void Meteor::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	pos.y -= yMove + (BASE_SPEED * msElapsed);
	if (pos.x < sprite_.getGlobalBounds().width * -1) {
		makeDead();
	}
	else {
		sprite_.setPosition(sf::Vector2f(pos.x - BASE_SPEED * msElapsed, pos.y));
	}
}