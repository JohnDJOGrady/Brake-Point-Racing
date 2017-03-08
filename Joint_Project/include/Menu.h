#ifndef MENU_H
#define MENU_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Widget.h"
#include "GameState.h"
#include "Xbox360Controller.h"

enum class button	// Enum for the buttons
{
	Play,
	Garage,
	Options,
	Exit
};

class Menu
{
	const sf::Time TIME_PER_UPDATE;

public:
	Menu(sf::Font & font, GameState *gameState);
	~Menu();

	void update(GamePadState m_state, Xbox360Controller & m_controller, sf::Time deltaTime);
	void render(sf::RenderWindow & window);

	void checkButtonSelected(GamePadState m_state, Xbox360Controller m_controller);	// Function to check which button is selected
	void selectedButton(GamePadState m_state, Xbox360Controller m_controller);	// Function to check if the selected button is clicked


private:
	GameState *m_gameState;
	const int BUTTON_COUNT = 4;
	int m_currentBtn;

	bool m_timeStop;
	bool m_transitionStop;

	sf::Time m_time;

	sf::Texture m_backgroundTex;
	sf::Sprite m_backgroundSprite;

	sf::Font m_font;
	button m_buttonSelected = button::Play; // The button enum which starts on the play button

	std::string m_strings[4] = { "Race", "Garage", "Options", "Exit" };

	Button *m_buttons[4];
};
#endif // !MENU_H
