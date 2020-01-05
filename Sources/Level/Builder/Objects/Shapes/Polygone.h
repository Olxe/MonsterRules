#pragma once

#include "../ObjectTemplate.h"
#include "Point.h"

namespace Builder
{
	enum class PolygoneType
	{
		POLYGONE,
		POLYLINE
	};

	class Polygone: public ObjectTemplate
	{
	public:
		Polygone(Parser::ObjectNode* object, std::string points, PolygoneType category);
		~Polygone();

		const std::vector< Point >& getPoints() const { return m_points; }
		const PolygoneType& getCategory() const { return m_category; }

	private:
		void convertPoints(std::string points);

	private:
		std::vector< Point > m_points;
		PolygoneType m_category;
	};
}


