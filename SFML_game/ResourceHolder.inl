template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id,
  const std::string & filename) {
  //unique指针指向新创建的Resource(),退出函数时。会自动销毁
  std::unique_ptr<Resource> resource(new	Resource());
  //资源类有通用的loadFromFile接口
  if (!resource->loadFromFile(filename))
    throw std::runtime_error("ResourceHolder::load - Failed to load" + filename);
  insertResource(id, std::move(resource));
}

template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename,
  const Parameter & secondParam) {
  std::unique_ptr<Resource> resource(new	Resource());
  //render类的loadFromFile接口需要两个参数
  if (!resource->loadFromFile(filename, secondParam))
    throw std::runtime_error("ResourceHolder::load - Failed to load" + filename);
  insertResource(id, std::move(resource));
}

template<typename Resource, typename Identifier>
Resource & ResourceHolder<Resource, Identifier>::get(Identifier id) {
  auto found = mResourceMap.find(id);
  assert(found != mResourceMap.end());
  return *(found->second);
}

template<typename Resource, typename Identifier>
const Resource & ResourceHolder<Resource, Identifier>::get(Identifier id) const {
  auto found = mResourceMap.find(id);
  assert(found != mResourceMap.end());
  return *(found->second);
}

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id,
  std::unique_ptr<Resource> resource) {
  auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
  assert(inserted.second);
}
