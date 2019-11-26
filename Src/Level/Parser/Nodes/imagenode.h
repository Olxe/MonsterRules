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

		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }
		std::string GetSource() const { return m_source; }

	protected:
		void ParseAttribute(const tinyxml2::XMLElement* eAttribute) override;
		void ParseChildTag(const tinyxml2::XMLElement* eChild) override {}

	private:
		int m_width;
		int m_height;
		std::string m_source;
	};
}

#endif