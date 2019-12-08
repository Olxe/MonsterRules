#include "LayerBuilder.h"

using namespace Builder;

LayerBuilder::LayerBuilder(Parser::LayerNode* layerNode, std::vector< Tile* >& tiles, float tileWidth, float tileHeight)
	: m_layerWidth(0)
	, m_layerHeight(0)
	, m_tileWidth(tileWidth)
	, m_tileHeight(tileHeight)
{
	if (layerNode) {
		m_layerWidth = layerNode->GetWidth();
		m_layerHeight = layerNode->GetHeight();

		if (Parser::DataNode* dataNode = dynamic_cast<Parser::DataNode*>(layerNode->GetFirstSpecificChild(Parser::NodeType::DATA))) {
			if (dataNode->GetEncoding() == "csv") {
				std::string strData = dataNode->GetData();
				const char* data = strData.c_str();
				if (data) {
					fillLayoutFromCSV(data, tiles);
				}
				else Out("Error : ", "LayerBuilder -> No data");
			}
		}
		else Out("Error : ", "LayerBuilder -> No dataNode");
	}
	else {
		Out("Error : ", "LayerBuilder -> Nullptr layerNode");
	}
}

LayerBuilder::~LayerBuilder()
{
}

void LayerBuilder::fillLayoutFromCSV(const char* data, std::vector<Tile*>& tiles)
{
	m_layout.clear();
	const char* delim = ",";
	char* input = (char*)data;
	char* next_token = nullptr;
	char* token = strtok_s(input, delim, &next_token);

	while (token) {
		int gidTile = atoi(token);

		m_layout.push_back(this->getTileWithGid(gidTile, tiles));

		token = strtok_s(NULL, delim, &next_token);
	}
}
