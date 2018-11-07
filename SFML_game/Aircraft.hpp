#pragma once
#include "Entity.hpp"
class Aircraft : public Entity {
public:
  //飞行器的类型:鹰 猛禽
  enum Type { Eagle, Raptor };

public:
  explicit Aircraft(Type type);
private:
  Type mType;

};
