#pragma once

#include "Managers/userData.h"
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

class Game;

class Character : public sf::Drawable, public sf::Transformable
{
public:

	Character(Game& game);

#pragma region GETTER/SETTER

	sf::Sprite GetMainSprite() { return m_mainSprite; };
	void SetMainSprite(sf::Sprite sprite) { m_mainSprite = sprite; };

	sf::Sprite GetSecondSprite() { return m_secondSprite; };
	void SetSecondSprite(sf::Sprite sprite) { m_secondSprite = sprite; };

	void SetSpriteAlpha(sf::Sprite& sprite, float alphaValue);

	float GetThrusterAlphaValue() { return m_secondSpriteAlphaValue; };

	float GetHealth(){return m_health; };
	void SetHealth(float health) { m_health = health; };

	b2Body* GetBody() { return m_body; };

	#pragma endregion
	#pragma region GAME METHODS
	
	void Init(sf::Vector2u winsize);
	void Update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void Move(b2Vec2 b2Vec2);

	void MaxThrusterAlphaValue();
	void LowerThrusterAlphaValue();
	void ResetColor();

	void SetDamage(float damage);

	#pragma endregion

protected:

	#pragma region SMFL

	//Ship
	sf::Texture m_mainTexture;
	std::string m_mainSpriteAdress;
	sf::Sprite m_mainSprite;
	//Thruster
	sf::Texture m_secondTexture;
	std::string m_secondSpriteAdress;
	sf::Sprite m_secondSprite;
	sf::Texture m_thirdTexture;
	std::string m_thirdSpriteAdress;
	sf::Sprite m_thirdSprite;

	float m_secondSpriteAlphaValue = 0;
	float m_thirdSpriteAlphaValue = 0;
	#pragma endregion
	#pragma region BOX2D

	b2Body* m_body = nullptr;
	Game& m_game;
	UserData* m_userData = new UserData(UserDataType::ROCKET);

	#pragma endregion
	#pragma region CHARACTERISTICS

	//Life 
	float m_health = 100;

	#pragma endregion
	
};