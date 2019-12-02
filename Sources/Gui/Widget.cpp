#include "Widget.hpp"

namespace gui
{
	Widget::Widget()
		: m_callback(nullptr)
	{
	}

	Widget::~Widget()
	{
	}
	void Widget::TriggerCallback() const
	{
		if (m_callback) {
			m_callback();
		}
	}
}