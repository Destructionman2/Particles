#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "Particle.h"
using namespace sf;
using namespace std;

const int numPoints = rand() % (50 - 25 + 1) + 25;

class Engine
{
private:
	// A regular RenderWindow
	RenderWindow m_Window;

	//vector for Particles
	vector<Particle> m_particles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};