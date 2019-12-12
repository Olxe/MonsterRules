#include "Widget.hpp"

namespace gui
{
	Widget::Widget()
		: MouseButtonReleasedCallback( [&]{ void(); } )
	{
	}

	Widget::~Widget()
	{
	}
}