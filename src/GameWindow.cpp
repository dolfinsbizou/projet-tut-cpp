#include "GameWindow.h"

void GameWindow::create(int tileSize, int width, int height)
{
	m_toRectifyRatio = false;
	m_tileSize = tileSize;
	m_width = width;
	m_height = height;
	cout << "** Creating a window with a size of " << width << "*" << height << " tiles (" << tileSize << "px)" << endl; 
	sf::RenderWindow::create(sf::VideoMode(width*tileSize, height*tileSize), string("Bomberman - v") + string(G_VERSION));
}

void GameWindow::create(int width, int height)
{
	GameWindow::create(DEFAULT_TILE_SIZE, width, height);
}

int GameWindow::getTileSize()
{
	return m_tileSize;
}

int GameWindow::getWidth()
{
	return m_width;
}

int GameWindow::getHeight()
{
	return m_height;
}

void GameWindow::rectifyRatio()
{
	float aspectX = getSize().x / (float)m_width,
		  aspectY = getSize().y / (float)m_height;

	if(aspectX<aspectY)
	{
		setSize(sf::Vector2u(getSize().x, aspectX*m_height));
	}
	else if(aspectY<aspectX)
	{
		setSize(sf::Vector2u(aspectY*m_width, getSize().y));
	}
}

void GameWindow::manageEvents(sf::Event &event, void *args)
{
	switch(event.type)
	{
		case sf::Event::Closed:
			close();
			break;
		case sf::Event::Resized:
			m_toRectifyRatio = true;
			break;
		default:
			break;
	}	
	
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_toRectifyRatio)
	{
		rectifyRatio();
		m_toRectifyRatio = false;
	}
}
