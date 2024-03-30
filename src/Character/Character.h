#pragma once
#include <SFML/Graphics.hpp>
class Character { 
private:
    float x,y;
public:
    float w, h, dx, dy, speed ;
    int direction ; 
    sf::String filename; 
    sf::Image charimage;
    sf::Texture chartexture;
    sf::Sprite charsprite;
    Character(sf::String F, float X, float Y, float W, float H){
    dx=0;dy=0;speed=0;direction=0;
    filename = F;
    w = W; h = H;
    charimage.loadFromFile("C:\\cmake-sfml-project-master\\src\\images\\" + filename);
    chartexture.loadFromImage(charimage);
    charsprite.setTexture(chartexture);
    x = X; y = Y;
    charsprite.setTextureRect(sf::IntRect(0, 0, w, h)); 
    }
    void update(float time)
    {
        switch (direction)
        {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed; break;
            case 3: dx = 0; dy = -speed; break;
    }
 
    x += dx*time;
    y += dy*time;
 
    speed = 0;
    charsprite.setPosition(x,y);
    }
    float GetX(){	
		return x;
	}
	float GetY(){	 	
		return y;
	}
};
