#ifndef __IMAGENODE__
#define __IMAGENODE__

#include "Node.h"

namespace Parser
{
	class ImageNode: public Node
	{
	public:
		ImageNode(Node* parent = nullptr);
		~ImageNode();

		float getWidth() const { return m_width; }
		float getHeight() const { return m_height; }
		std::string getSource() const { return m_source; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:
		float m_width;
		float m_height;
		std::string m_source;

	};
}

#endif