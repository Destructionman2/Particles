#include "Engine.h"  //Re-Adjust file opening if needed

Engine::Engine()
{
	m_Window.create(sf::VideoMode::getDesktopMode(), "Particles!");
}

void Engine::run()
{
    sf::Clock clock;

    // Construct a local Particle to be used for the unit testing
    std::cout << "Starting Particle unit tests..." << std::endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    std::cout << "Unit tests complete. Starting engine..." << std::endl;

    // Game loop
    while (m_Window.isOpen())
    {
        sf::Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input()
{
    sf::Event event;
    switch (event.type)
    {
    case sf::Event::Closed:
        m_Window.close();
        break;
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Escape)
            m_Window.close();
        break;
    case sf::Event::MouseButtonPressed:
        if(event.mouseButton.button == sf::Mouse::Left)
            for (int i = 0; i < 5; i++)
            {
                Particle tempParticle(m_Window, numPoints, sf::Mouse::getPosition(m_Window));
                m_particles.push_back(tempParticle);
            }
        break;
    default:
        break;
    }
}

void Engine::update(float dtAsSeconds)
{
    for (auto it = m_particles.begin(); it != m_particles.end();)
    {
        if (it->getTTL() > 0.0f)
        {
            it->Particle::update(dtAsSeconds);
            it++;
        }
        else
        {
            it = m_particles.erase(it);
        }
    }
}

void Engine::draw()
{
    m_Window.clear();
    for (int i = 0; i < m_particles.size(); i++)
    {
        m_Window.draw(m_particles.at(i));
    }
    m_Window.display();
}