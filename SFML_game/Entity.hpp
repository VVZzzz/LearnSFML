#pragma once
#include <SFML\System\Vector2.hpp>
#include <SFML\System\Time.hpp>
//该game中一切的实体基类,一个共同的特性:速度!
class Entity {
public:
  void setVelocity(sf::Vector2f velocity);
  void setVelocity(float vx, float vy);


  sf::Vector2f getVelocity() const;
private:
  virtual void updateCurrent(sf::Time dt);

private:
  sf::Vector2f mVelocity;

};

