#include <SFML/Graphics.hpp>
#include <iostream>
#include "Const.h"
#include "Character/Character.h"
#include "Map/Map.h"
#include "Camera/Camera.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Start");
    Camera.reset(sf::FloatRect(0, 0, 1920, 1080));
    window.setFramerateLimit(144); // 256 x 464 // 64 x 116
    float frame=0;
    Character chara("chara.png",500,500,64,116);
    sf::Image map_image;
	map_image.loadFromFile("C:\\cmake-sfml-project-master\\src\\images\\textures.jpg");
	sf::Texture map_texture;
	map_texture.loadFromImage(map_image);
	sf::Sprite map_sprite;
	map_sprite.setTexture(map_texture);
   /* sf::Image charimage; 
	charimage.loadFromFile("C:\\cmake-sfml-project-master\\src\\images\\chara.png");

	sf::Texture chartexture;
	chartexture.loadFromImage(charimage);

	sf::Sprite charsprite;
	charsprite.setTexture(chartexture);
    charsprite.setTextureRect(sf::IntRect(128,116,64,116));
	charsprite.setPosition(50, 25);   */

    sf::Time t1 = sf::microseconds(10000);
    sf::Time t2 = sf::milliseconds(10);
    sf::Time t3 = sf::seconds(0.01f);
    sf::Clock clock; 
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart(); 
        time = time/800; 
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        short run = 1;
        FreeView(time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) 
            {run = 2;}
        else  
            {run = 1;}
        
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
            chara.direction = 1; chara.speed = 0.1*run; 
            frame += 0.005*time;
            chara.charsprite.move(-0.1*time*run, 0);
            GetCoordinate(chara.GetX(), chara.GetY());
            window.setView(Camera);
            if (frame > 4) frame -= 4;
            chara.charsprite.setTextureRect(sf::IntRect(64 * int(frame), 116, 64, 116));
        }

 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)  )) {
            chara.direction = 0; chara.speed = 0.1*run; 
            frame += 0.005*time;
            chara.charsprite.move(0.1*time*run, 0);
            GetCoordinate(chara.GetX(), chara.GetY());
            
            if (frame > 4) frame -= 4;
                chara.charsprite.setTextureRect(sf::IntRect(64 * int(frame), 232, 64, 116));
            }
 
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)  )) {
            chara.direction = 3; chara.speed = 0.1*run; 
            frame += 0.005*time;
            chara.charsprite.move(0, -0.1*time*run);
            GetCoordinate(chara.GetX(), chara.GetY());
            
            if (frame > 4) frame -= 4;
                chara.charsprite.setTextureRect(sf::IntRect(64 * int(frame), 348, 64, 116));
            }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )) { 
            chara.direction = 2; chara.speed = 0.1*run; 
            chara.charsprite.move(0, 0.1*time*run);
            GetCoordinate(chara.GetX(), chara.GetY());
            
            frame += 0.005*time; 
        if (frame > 4) frame -= 4; 
            chara.charsprite.setTextureRect(sf::IntRect(64 * int(frame), 0, 64, 116));
 }
        chara.update(time);
        window.setView(Camera);
        window.clear();
		for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
		{                 //////////////////////// 45 x 48
			if (TileSet[i][j] == ' ')  map_sprite.setTextureRect(sf::IntRect(24, 293, 72, 338));
			if (TileSet[i][j] == 'T')  map_sprite.setTextureRect(sf::IntRect(600, 75, 644, 120));
			if ((TileSet[i][j] == 'h')) map_sprite.setTextureRect(sf::IntRect(134, 559, 169, 594));
            if ((TileSet[i][j] == 'g')) map_sprite.setTextureRect(sf::IntRect(393, 57, 441, 102));
            if ((TileSet[i][j] == 'L')) map_sprite.setTextureRect(sf::IntRect(0, 293, 49, 338));
            if ((TileSet[i][j] == 'R')) map_sprite.setTextureRect(sf::IntRect(48, 293, 96, 338));
            if ((TileSet[i][j] == 'U')) map_sprite.setTextureRect(sf::IntRect(24, 270, 72, 315));
            if ((TileSet[i][j] == 'D')) map_sprite.setTextureRect(sf::IntRect(24, 315, 72, 369));
            if ((TileSet[i][j] == 'Q')) map_sprite.setTextureRect(sf::IntRect(0, 270, 48, 315));
            if ((TileSet[i][j] == 'W')) map_sprite.setTextureRect(sf::IntRect(48, 270, 96, 315));
            if ((TileSet[i][j] == 'E')) map_sprite.setTextureRect(sf::IntRect(0, 315, 48, 360));
            if ((TileSet[i][j] == 'S')) map_sprite.setTextureRect(sf::IntRect(48, 315, 96, 360));
            if ((TileSet[i][j] == 'C')) map_sprite.setTextureRect(sf::IntRect(595, 69, 640, 116));
            if ((TileSet[i][j] == 'K')) map_sprite.setTextureRect(sf::IntRect(672, 528, 720, 575));
            if ((TileSet[i][j] == 'F')) map_sprite.setTextureRect(sf::IntRect(673, 575, 720, 625));
            if ((TileSet[i][j] == 'G')) map_sprite.setTextureRect(sf::IntRect(720, 575, 768, 625));
            if ((TileSet[i][j] == 'l')) map_sprite.setTextureRect(sf::IntRect(720, 528, 768, 575));
            if ((TileSet[i][j] == 'A')) map_sprite.setTextureRect(sf::IntRect(695, 71, 743, 121));
			map_sprite.setPosition(j * 45, i * 48);
			window.draw(map_sprite);
		}
        window.draw(chara.charsprite);
        window.display();
    }
}
