
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

  //textures
  sf::Texture backgroundTexture{ "../Data/Images/Whackamole Worksheet/background.png" };
  sf::Texture birdTexture{ "../Data/Images/Whackamole Worksheet/bird.png" };

  //sprites
  sf::Sprite background = sf::Sprite(backgroundTexture);
  sf::Sprite bird = sf::Sprite(birdTexture);

  

  


};


#endif // SFML_GAME_H
