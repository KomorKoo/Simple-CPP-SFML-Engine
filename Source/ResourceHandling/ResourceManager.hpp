#pragma once

#include <unordered_map>

template<typename ResourceType>
class ResourceManager {
	private:
		std::string m_folder;
		std::string m_extension;

		std::unordered_map<std::string, ResourceType> m_resources;

	public:
		ResourceManager(const std::string& folder, const std::string& ext)
		:	m_folder   ("Resources/" + folder + "/")
		,	m_extension("." + ext)
		{ }

		void addResource(const std::string& name) {
			ResourceType resource;

			resource.loadFromFile(getFullPath(name));
			m_resources.insert(std::make_pair(name, resource));
		}

		ResourceType& get(const std::string& name) {
			return m_resources.at(name);
		}

	private:
		std::string getFullPath(const std::string& name) {
			return m_folder + name + m_extension;
		}
};
