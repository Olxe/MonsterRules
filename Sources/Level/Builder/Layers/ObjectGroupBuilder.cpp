#include "ObjectGroupBuilder.h"

using namespace Builder;

ObjectGroupBuilder::ObjectGroupBuilder(Parser::ObjectGroupNode* objectGroup, std::vector< Tile* >& tiles)
{
	for (auto it : objectGroup->GetSpecificListOfChild(Parser::NodeType::OBJECT)) {
		if (Parser::ObjectNode* objectNode = dynamic_cast<Parser::ObjectNode*>(it)) {
			if (objectNode->GetGid() > 0) {
				Tile* tile = this->getTileWithGid(objectNode->GetGid(), tiles);
				m_layout.push_back(std::unique_ptr<SceneObject>(new SceneObject(objectNode, tile)));
			}
			else {
				m_layout.push_back(ObjectBuilder::BuildObject(objectNode));
			}
		}
	}
}

ObjectGroupBuilder::~ObjectGroupBuilder()
{
}
