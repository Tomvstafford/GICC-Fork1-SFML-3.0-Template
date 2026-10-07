
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
	: window(game_window),
	font("../Data/Fonts/OpenSans-Bold.ttf"),
	titleText(font, "Whack-a-mole", 50),
	playText(font, "Play", 30),
	exitText(font, "Exit", 30),
	scoreText(font, "Score: 0", 20)

{
	srand(time(NULL));

}

Game::~Game()
{


}

// We call this once after the game class is instantiated
bool Game::init()
{
	background.setTexture(backgroundTexture);
	bird.setTexture(birdTexture);
	bird.setScale({ 0.5f, 0.5f });
	return true;

	if (!backgroundTexture.loadFromFile("../Data/Images/Whackamole Worksheet/background.png"))
	{
		std::cout << "Failed to load background texture" << std::endl;
		return false;
	}

	if (!birdTexture.loadFromFile("../Data/Images/Whackamole Worksheet/bird.png"))
	{
		std::cout << "Failed to load bird texture" << std::endl;
		return false;
	}
	if (!font.openFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		return false;
	}
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{
	if (menuActive == true)
	{
		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		if (playText.getGlobalBounds().contains(mousePos))
		{
			playButtonHovered = true;
			playText.setFillColor(sf::Color::Green);
		}
		else
		{
			playButtonHovered = false;
			playText.setFillColor(sf::Color::White);
		}

		if (exitText.getGlobalBounds().contains(mousePos))
		{
			exitButtonHovered = true;
			exitText.setFillColor(sf::Color::Red);
		}
		else
		{
			exitButtonHovered = false;
			exitText.setFillColor(sf::Color::White);
		}
	}
	if (ingame == true)
	{
		bird.move({ birdVelocity.x * dt, birdVelocity.y * dt });

		sf::FloatRect birdBounds = bird.getGlobalBounds();
		sf::FloatRect bounds = bird.getGlobalBounds();
		
		if (bounds.position.x <= 0 || bounds.position.x + bounds.size.x >= window.getSize().x)
		{
			birdVelocity.x = -birdVelocity.x;
		}
		if (bounds.position.y <= 0 || bounds.position.y + bounds.size.y >= window.getSize().y)
		{
			birdVelocity.y = -birdVelocity.y;
		}
	}
}

// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
     if (menuActive == true)
	 {
		 titleText.setPosition({ 200, 100 });
		 titleText.setScale({ 2.0f, 2.0f });
		 playText.setPosition({ 500, 300 });
		 playText.setScale({ 1.5f, 1.5f });
		 exitText.setPosition({ 500, 400 });
		 exitText.setScale({ 1.5f, 1.5f });
		 window.draw(titleText);
		 window.draw(playText);
		 window.draw(exitText);
		 return;
	 }
	 else if (ingame == true)
	 {
		 window.draw(background);
		 window.draw(bird);
		 window.draw(scoreText);
		 scoreText.setScale({ 1.5f, 1.5f });
		 scoreText.setFillColor(sf::Color::Black);
	 }
	
}

//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked

	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;

	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		
	}
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		sf::Vector2f mousePos = window.mapPixelToCoords(event->position);

		if (playText.getGlobalBounds().contains(mousePos))
		{
			menuActive = false;
			ingame = true;
		}
		else if (exitText.getGlobalBounds().contains(mousePos))
		{
			window.close();
		}
	}

	if (ingame == true)
	{
		sf::Vector2f mousePos = window.mapPixelToCoords(event->position);
		if (bird.getGlobalBounds().contains(mousePos))
		{
			score += 1;
			scoreText.setString("Score: " + std::to_string(score));
			float randomX = rand() % 900 + 1;
			float randomY = rand() % 600 + 1;
			bird.setPosition({ randomX, randomY });

		}
	}


}

// Called by event polling when a KeyPressed event is found
void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	// You can tell which button was pressed by the scancode to SFML's definitions of keyboard keys
	if (event->scancode == sf::Keyboard::Scancode::W)
	{

	}

}

// Called by event polling when a KeyReleased event is found
void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	// Works the same way as KeyPressed
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was released
	}

}

