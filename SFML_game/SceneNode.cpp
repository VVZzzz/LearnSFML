#include "SceneNode.hpp"

SceneNode::SceneNode() :mChildren(), mParent(nullptr) {

}

void SceneNode::attachChild(Ptr child) {
  child->mParent = this;
  mChildren.push_back(std::move(child));
}
