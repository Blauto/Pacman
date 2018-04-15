#include "stdafx.h"
#include "Packman.h"

using namespace sf;
using namespace std;

Packman::Packman(float x, float y)
{
	positionX = x;
	positionY = y;

	texture.loadFromFile("C:/Users/bogusia/Source/Repos/Packman/Packman/Packman/packman.png");
	player.setTexture(texture);

	Vector2f textureSize{ texture.getSize() };
	Vector2f sizeVector{(float)(width), (float)height };
	Vector2f scaleVector( sizeVector.x / textureSize.x, sizeVector.y / textureSize.y );

	player.setScale(scaleVector);
	player.setPosition(positionX, positionY);
	player.setOrigin(width,height);
}

void Packman::update(Map* map)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {

		player.move(velocityVectorLeft);
		if (!map->check(&player)) {
			player.move(velocityVectorRight);
		} else {
			player.setRotation(180);
		}
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {

		player.move(velocityVectorRight);
		if (!map->check(&player)) {
			player.move(velocityVectorLeft);
		}
		else {
			player.setRotation(0);
		}
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {

		player.move(velocityVectorTop);
		if (!map->check(&player)) {
			player.move(velocityVectorBottom);
		} else {
			player.setRotation(270);
		}
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {

		player.move(velocityVectorBottom);
		if (!map->check(&player)) {
			player.move(velocityVectorTop);
		} else {
			player.setRotation(90);
		}
	}

}

void Packman::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->player, state);
}


