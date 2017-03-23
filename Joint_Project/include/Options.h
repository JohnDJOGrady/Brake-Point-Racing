#ifndef OPTIONS_H
#define OPTIONS_H

/// <summary>
/// Author: John O'Grady, Jack O'Kelly
/// Version: 1.0
/// Created: 08/03/2017
/// </summary>

#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "Widget.h"
#include "ResourceManager.h"
#include "SFML\Audio.hpp"
#include "SFML\Audio\SoundSource.hpp"

enum class optionsSelection	// Enum for the buttons
{
	Option1,
	Option2,
	Option3
};

class Options
{
public:

	Options(sf::Font font, GameState *gameState, sf::Sound &music);	// Constructor for the options object
	~Options();	// Deconstructor for the options object

	/// <summary>
	/// Update method that updates the options object based on
	/// Current GameState, the controller object, and the music
	/// </summary>
	void update(GamePadState m_state, Xbox360Controller & m_controller, sf::Sound &music);
	
	/// <summary>
	/// Render method that renders the options object
	/// Dependent on the current Render Window
	/// </summary>
	void render(sf::RenderWindow & window);



private:
	GameState *m_gameState;		// A pointer to the current gamestate

	void checkButtonSelected(GamePadState m_state, Xbox360Controller m_controller, sf::Sound &music);	// Function to check which button is selected
	void selectedButton(GamePadState m_state, Xbox360Controller m_controller, sf::Sound &music);	// Function to check if the selected button is clicked

	optionsSelection m_buttonSelected = optionsSelection::Option1; // The button enum which starts on the first option

	// Strings for the buttons
	std::string m_exitString = "Back";
	std::string m_volString = "Volume:";
	std::string m_muteString = "Mute:";

	sf::Font m_font;	// Stores the font

	// Widget objects
	Button *m_exitButton;
	Slider *m_volSlider;
	RadioButton *m_screenRadio;
	Label *m_volLabel;
	Label *m_muteLabel;

	sf::Sound vol;	// Stores the volume

	float m_volume;	// A float variable for the volume as a usable value
	int m_volDif;	// The decrementation/incrementation value of the slider

	Widget *widgets[5];	// Array of widgets

	sf::Texture m_radioTex;	// Stores a texture
	
	// Button and slider variables
	int m_sliderValue;
	int m_currentBtn = 0;
	const int BUTTON_COUNT = 3;
};
#endif // !OPTIONS_H
