
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

  //sprites
  sf::Sprite background;
  sf::Sprite mainmenubackground;
  sf::Sprite bird;

  //textures
  sf::Texture backgroundTexture;
  sf::Texture mainmenubackgroundTexture;
  sf::Texture birdTexture;

  //font
  sf::Font font;

  //menu
  bool inmenu;
  sf::Text menutext;
  sf::Text playoption;
  sf::Text quitoption;
  bool playoptionselected;


};


#endif // SFML_GAME_H
