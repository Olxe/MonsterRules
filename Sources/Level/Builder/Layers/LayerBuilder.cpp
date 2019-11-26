#include "LayerBuilder.h"

using namespace Builder;

LayerBuilder::LayerBuilder(Parser::LayerNode* layerNode, std::vector< Tile* >& tiles)
{
	if (Parser::DataNode* dataNode = dynamic_cast<Parser::DataNode*>(layerNode->GetFirstSpecificChild(Parser::NodeType::DATA))) {
		if (dataNode->GetEncoding() == "csv") {
			std::string strData = dataNode->GetData();
			const char* data = strData.c_str();
			if (data) {
				fillLayoutFromCSV(data, layerNode->GetWidth(), tiles);
			}
			else display("Error -> Data not available");
		}
	}
	else display("Error -> No data node");
}

LayerBuilder::~LayerBuilder()
{
}

void LayerBuilder::fillLayoutFromCSV(const char* data, int widthGrid, std::vector<Tile*>& tiles)
{
	const char* delim = ",";
	char* input = (char*)data;
	char* next_token = nullptr;
	char* token = strtok_s(input, delim, &next_token);
	int counter = 0;
	std::vector< Tile* > line;

	while (token) {
		int gidTile = atoi(token);

		line.push_back(this->getTileWithGid(gidTile, tiles));
		
		counter++;
		if (counter > widthGrid) {
			counter = 0;
			m_layout.push_back(line);
			line.clear();
		}

		token = strtok_s(NULL, delim, &next_token);
	}
}
