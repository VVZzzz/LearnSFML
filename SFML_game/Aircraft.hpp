#pragma once
#include "Entity.hpp"
class Aircraft : public Entity {
public:
  //������������:ӥ ����
  enum Type { Eagle, Raptor };

public:
  explicit Aircraft(Type type);
private:
  Type mType;

};
