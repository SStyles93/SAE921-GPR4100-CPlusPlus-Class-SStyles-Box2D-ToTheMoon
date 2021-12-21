#pragma once
#include <fstream>
#include <vector>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window//Event.hpp"
#include "SFML/Audio.hpp"
#include "box2d/b2_world.h"

#include "Managers/textureManager.h"
#include "Managers/contactListener.h"
#include "Managers/trailManager.h"

#include "character.h"
#include "boundary.h"
#include "star.h"
#include "trail.h"


class Game {

public:
	
	Game();

	#pragma region GAME METHODS
	
	void Init();
	void Loop();

	void SetDamageToRocket(float damages);
	void DestroyTrail(int idTrail);

#pragma endregion
	#pragma region GETTER/SETTER

	b2World& GetWorld() { return m_world; }; 

#pragma endregion
	#pragma region CONVERSION METHODS

	static b2Vec2 pixelsToMeters(sf::Vector2f pixels);
	static b2Vec2 pixelsToMeters(sf::Vector2u pixels);
	static float pixelsToMeters(float pixels);
	static sf::Vector2f metersToPixels(b2Vec2 meters);
	static const float pixelsMetersRatio;

#pragma endregion

private:

	#pragma region Physical

	// World
	b2Vec2 m_gravity;
	b2World m_world;

	//Game Elements
	std::vector<Boundary> m_boundaries;
	std::vector<Star> m_stars;
	int m_starsCount = 0;
	
	//Character
	Character m_character;
	
	//Managers
	TrailManager m_trailManager;
	ContactListener m_contacts;
	

#pragma endregion
	#pragma region Graphical

	//Window
	sf::RenderWindow m_window;

	//Time Values
	sf::Clock m_clock1;
	sf::Time m_deltaTime1;
	sf::Clock m_clock2;
	sf::Time m_deltaTime2;

	//Music
	sf::Music m_music;
	//Sound
	sf::SoundBuffer m_bufferThruster;
	sf::SoundBuffer m_bufferCrash;
	sf::Sound m_soundThruster;
	sf::Sound m_soundCrash;

	//Text
	sf::Font m_font;
	sf::Text m_scoreText;
	sf::Text m_lifeText;
	sf::Text m_gameOverText;

	//Start Screen
	sf::Texture m_startScreenTexture;
	sf::Sprite m_startScreenSprite;

#pragma endregion
	#pragma region GameVariables

	//Higher the levelDuration is, longer and easier the game will be.
	float m_levelDuration = 0.25f;
	
	//Defines the range [min - max] of the random trail scaling
	float m_minTrailScaleValue = 1.0f;
	float m_maxTrailScaleValue = 3.0f;
	
	//Game States
	bool m_gameOver = false;
	bool m_gameStarted = false;

	//Score managment
	sf::Clock m_scoreClock;
	sf::Time m_elapsed;
	sf::Time m_scoreTime;
	float m_highestScore = 0;
	float m_score = 0;

#pragma endregion

};