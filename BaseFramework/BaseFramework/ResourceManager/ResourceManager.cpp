#include<iostream>
#include "ResourceManager.h"

namespace BaseFramework
{
	template<typename RESOURCE>
	const RESOURCE& ResourceManager<RESOURCE>::get(const std::string& name) const
	{
		if (!exists(name))
		{
			add(name);
		}

		return _resources.at(name);
	}

	template<typename RESOURCE>
	bool ResourceManager<RESOURCE>::exists(const std::string& name)
	{
		return _resources.find(name) != _resources.end();
	}

	template<typename RESOURCE>
	void ResourceManager<RESOURCE>::add(const std::string& name)
	{
		RESOURCE r;
		if (!r.loadFromFile(getFullPath(name)))
		{
			std::cout << "Can't load resource " << name;
		}
		else
		{
			_resources.push_back(std::make_pair(name, r));
		}
	}

	template<typename RESOURCE>
	std::string ResourceManager<RESOURCE>::getFullPath(const std::string& name)
	{
		return _folder + name + _extension;
	}
}