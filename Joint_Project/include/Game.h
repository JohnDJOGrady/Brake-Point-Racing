#ifndef GAME_H
#define GAME_H

#include "SFML\Graphics.hpp"
#include "Xbox360Controller.h"
#include "Widget.h"
#include "Menu.h"
#include "Options.h"
#include "Play.h"
#include "Splash.h"
#include <iostream>

enum GameState
{
	SPLASH,
	MENU,
	PLAY,
	OPTIONS,
	CREDITS
};

class Game
{
public:
	Game(sf::Font & font);
	~Game();

	void run();

	void checkGameStateChange();

private:

	void update(sf::Time deltaTime);
	void render(sf::RenderWindow & window);
	
	GameState m_screen = GameState::SPLASH;

	sf::RenderWindow m_window;
	sf::Font m_font;

	GameState m_currentGameState;

	Xbox360Controller m_controller;

	Splash *m_splashScreen;
	Menu *m_menuScreen;
};
#endif // !GAME_H