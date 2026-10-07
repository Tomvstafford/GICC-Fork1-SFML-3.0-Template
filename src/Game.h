
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
  void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
  void keyPressed(const sf::Event::KeyPressed* event);
  void keyReleased(const sf::Event::KeyReleased* event);
  

 private:
  sf::RenderWindow& window;


  // menu
  bool menuActive = true;
  bool playButtonHovered = false;
  bool exitButtonHovered = false;
  bool ingame = false;

  sf::Font font;
  sf::Text titleText;
  sf::Text playText;
  sf::Text exitText;
  sf::Text scoreText;

  //textures
  sf::Texture backgroundTexture{ "../Data/Images/Whackamole Worksheet/background.png" };
  sf::Texture birdTexture{ "../Data/Images/Whackamole Worksheet/bird.png" };

  //sprites
  sf::Sprite background = sf::Sprite(backgroundTexture);
  sf::Sprite bird = sf::Sprite(birdTexture);

  //variableas
  int score = 0;
  float x_prime = 0.0f;
  float y_prime = 0.0f;
  float theta = (rand() % 360)* 3.14 / 360.0f; // Convert degrees to radians

  sf::Vector2f birdVelocity{ 400.0f, 300.0f };
};


#endif // SFML_GAME_H
