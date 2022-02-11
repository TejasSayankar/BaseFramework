#pragma once

#include<unordered_map>
#include<string>

namespace BaseFramework
{
	template<typename RESOURCE>
	class ResourceManager
	{
	public:
		ResourceManager(const std::string& folder, const std::string& extension) : _folder("res/" + folder + "/"), _extension("." + extension) {}

		const RESOURCE& get(const std::string& name) const;

		bool exists(const std::string& name);

		void add(const std::string& name);
	private:
		std::string getFullPath(const std::string& name);
		
		const std::string _folder;
		const std::string _extension;

		std::unordered_map<std::string, RESOURCE*> _resources;
	};
}