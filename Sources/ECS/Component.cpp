#include "Component.h"
#include "Entity.h"

Component::Component(ComponentID id, Entity* entity)
	: m_id(id)
	, m_entity(entity)
{
}
