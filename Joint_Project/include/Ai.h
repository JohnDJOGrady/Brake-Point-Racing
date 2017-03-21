#ifndef AI_H
#define AI_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Node.h"
#include <Thor\Vectors.hpp>
#include "BTMath.h"
#include <Thor\Math.hpp>
#include <Thor\Shapes.hpp>
#include <Thor\Vectors.hpp>
#include "ResourceManager.h"

class Ai
{
public:
	Ai();
	Ai(std::vector<std::unique_ptr<Node>> & nodes, sf::Vector2f & position);
	~Ai();

	void update(double dt);
	void render(sf::RenderWindow & window);

	sf::Vector2f m_position;

private:

	const int NODE_TOLERANCE = 40.0f;

	sf::Texture m_carTex;
	sf::Sprite m_carSprite;

	float const MAX_FORCE = 10.0f;
<<<<<<< HEAD
	float const MAX_SPEED = 26.75f;
=======
	float const MAX_SPEED = 25.0f;
>>>>>>> cf1e810e1d5d0f95e85ee06315d9782f7c49ebfe

	int m_currentNode;

	sf::Vector2f m_velocity;
	
	float m_rotation;
	float m_speed;

	sf::Vector2f m_steering;

	sf::Vector2f m_followPath();

	std::vector<std::unique_ptr<Node>> &m_nodes;
	std::vector<sf::CircleShape> m_circles;

	const double PI = atan(1) * 4;
	const double DEG_TO_RAD = PI / 180.0f;
};
#endif // !AI_H