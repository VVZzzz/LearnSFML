#pragma once
//������Դ��ģ��
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

//Identifier��Ϊ����Դ������
template <typename Resource, typename Identifier>
class ResourceHolder {
 public:
	//�ϳɵĹ��캯��
	void load(Identifier id, const std::string &filename);
	//����ģ��,��Ҫ�Ǽ���renderʱ,Ҫ�����ڶ�������
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