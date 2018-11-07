#pragma once
//加载资源类模板
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

//Identifier作为该资源的引用
template <typename Resource, typename Identifier>
class ResourceHolder {
 public:
	//合成的构造函数
	void load(Identifier id, const std::string &filename);
	//函数模板,主要是加载render时,要给出第二个参数
	template <typename Parameter>
	void load(Identifier id, const std::string &filename, const Parameter &secondParam);

	Resource &get(Identifier id);
	const Resource &get(Identifier id) const;
 private:
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);
 private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};
#include "ResourceHolder.inl"