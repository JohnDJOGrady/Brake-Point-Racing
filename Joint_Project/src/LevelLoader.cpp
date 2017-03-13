#include "LevelLoader.h"

void operator >> (const YAML::Node& roadNode, RoadData& road)
{
	road.m_fileName = roadNode["file"].as<std::string>();
	road.m_position.x = roadNode["position"]["x"].as<float>();
	road.m_position.y= roadNode["position"]["y"].as<float>();
	road.m_rotation = roadNode["rotation"].as<double>();
	road.m_scale = roadNode["scale"].as<double>();
}

void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	// load in the data from the yaml file to the level load system
	const YAML::Node& roadsNode = levelNode["tile"].as<YAML::Node>();
	for (unsigned i = 0; i < roadsNode.size(); i++)
	{
		RoadData road;
		roadsNode[i] >> road;
		level.m_roads.push_back(road);
	}

	const YAML::Node& nodesNode = levelNode["node"].as<YAML::Node>();
	for (unsigned i = 0; i < nodesNode.size(); i++)
	{
		NodeData node;
		nodesNode[i] >> node;
		level.m_nodes.push_back(node);
	}
}

void operator >> (const YAML::Node& nodeNode, NodeData& node)
{
	node.m_number = nodeNode["number"].as<int>();
	node.m_position.x = nodeNode["position"]["x"].as<float>();
	node.m_position.y = nodeNode["position"]["y"].as<float>();
}

LevelLoader::LevelLoader()
{
}

bool LevelLoader::load(int levelNo, LevelData& level)
{
	// load the levels 
	std::stringstream ss;
	ss << "resources/levels/level";
	ss << levelNo;
	ss << ".yaml";

	try 
	{

		YAML::Node base = YAML::LoadFile(ss.str());
		if (base.IsNull())
		{
			std::string message("file:" + ss.str() + "not found");
			throw std::exception(message.c_str());
		}
		base >> level;
	}

	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	return true;
}