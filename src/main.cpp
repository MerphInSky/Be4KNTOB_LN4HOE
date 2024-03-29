#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Start");
    window.setFramerateLimit(144); // 256 x 464 // 64 x 116

    sf::Image charimage; 
	charimage.loadFromFile("C:\\cmake-sfml-project-master\\src\\images\\chara.png");

	sf::Texture chartexture;
	chartexture.loadFromImage(charimage);

	sf::Sprite charsprite;
	charsprite.setTexture(chartexture);
    charsprite.setTextureRect(sf::IntRect(128,116,64,116));
	charsprite.setPosition(50, 25);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) { charsprite.move(-5, 0); charsprite.setTextureRect(sf::IntRect(0, 116, 64, 116)); } //добавили управление на клавиши W,S,A,D
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { charsprite.move(5, 0); charsprite.setTextureRect(sf::IntRect(0, 232, 64, 116)); } 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { charsprite.move(0, -5); charsprite.setTextureRect(sf::IntRect(0, 348, 64, 116)); } 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { charsprite.move(0, 5); charsprite.setTextureRect(sf::IntRect(0, 0, 64, 116)); }  
        window.clear();
        window.draw(charsprite);
        window.display();
    }
}
