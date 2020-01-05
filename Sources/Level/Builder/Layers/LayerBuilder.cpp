#include "LayerBuilder.h"

using namespace Builder;

LayerBuilder::LayerBuilder(Parser::LayerNode* layerNode, std::vector< Tile* >& tiles, sf::Vector2f tileSize)
	: m_tileSize(tileSize)
	, m_layer(layerNode)
{
	if (layerNode) {
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

sf::Vector2i Builder::LayerBuilder::getLayerSize() const
{
	if (m_layer) {
		return sf::Vector2i(m_layer->GetWidth(), m_layer->GetHeight());
	}
	return sf::Vector2i();
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
