#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>

#include <vector>
#include <memory>
class SceneNode : public sf::Transform, public sf::Drawable, private sf::NonCopyable {
public:
  typedef std::unique_ptr<SceneNode> Ptr;
public:
  SceneNode();
  void attachChild(Ptr child);  //向当前场景中插入结点
  Ptr  detachChild(const SceneNode& node);

  void update(sf::Time dt);

  sf::Vector2f getWorldPosition() const;
  sf::Transform getWorldTransform() const;

public:
  virtual void updateCurrent(sf::Time dt);
  void updateChildren(sf::Time dt);

  virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
  void	drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
private:
  std::vector<Ptr> mChildren;
  SceneNode *mParent;
};
