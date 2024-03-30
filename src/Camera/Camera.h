#include <SFML/Graphics.hpp>

sf::View Camera;
void GetCoordinate(float x,float y) { 
	Camera.setCenter(x, y);
}
void FreeView(float time) { 
	
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		Camera.move(1*time, 0);
	}
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		Camera.move(0, 1*time);
	}
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		Camera.move(-1*time, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		Camera.move(0, -1*time);
	}
 
}