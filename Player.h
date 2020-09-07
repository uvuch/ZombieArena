#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
  private:
	const float START_SPEED = 400;
	const float START_HEALTH = 100;
	 
	Vector2f m_Position;	// Where is the player
	Sprite m_Sprite;		// Of course, we will need a sprite
	Texture m_Texture;		// And a texture
	// !!Watch this space – Interesting changes here soon!! 
	 
	Vector2f m_Resolution;	// What is the screen resolution 
	IntRect m_Arena;		// What size is the current arena
							
	int m_TileSize;			// How big is each tile of the arena 
	 
	// Which direction(s) is the player currently moving in 
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	 
	int m_Health;			// How much health has the player got? 
	int m_MaxHealth;		// What is the maximum health the player can have 
	Time m_LastHit;			// When was the player last hit 
	float m_Speed;			// Speed in pixels per second 
	 
  public:
	Player();

	void spawn(IntRect arena, Vector2f resolution, int tileSize);
	void resetPlayerStats();								  // Call this at the end of every game
	bool hit(Time timeHit);									  // Handle the player getting hit by a zombie
	Time getLastHitTime();									  // How long ago was the player last hit
	FloatRect getPosition();								  // Where is the player
	Vector2f getCenter();									  // Where is the center of the player
	float getRotation();									  // What angle is the player facing
	Sprite getSprite();										  // Send a copy of the sprite to the main function
	
	// The next four functions move the player
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	// Stop the player moving in a specific direction
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	
	void update(float elapsedTime, Vector2i mousePosition);	  // We will call this function once every frame
	void upgradeSpeed();									  // Give the player a speed boost
	void upgradeHealth();									  // Give the player some health
	void increaseHealthLevel(int amount);					  // Increase the maximum amount of health the player can have
	int getHealth();										  // How much health has the player currently got?
};

