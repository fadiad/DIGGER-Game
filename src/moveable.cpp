#include "moveable.h"

void moveable::move(sf::RenderWindow& window,
			 const std::vector<std::unique_ptr<unmoveable>>& unmov)
{
	const sf::Vector2f step = get_next_step(window);
	m_object.move(step);
	if (collides(unmov))
		m_object.move(-step);
}
//=============================================
bool moveable::collides(const std::vector<std::unique_ptr<unmoveable>>& unmov) const
{
	for (const auto& others : unmov)
	{
		// check object collides with Rock or Wall
		if (others->GET_OPJ_TYPE() == WALL || others->GET_OPJ_TYPE() == ROCK)
			if (m_object.getGlobalBounds().intersects(others->GET_GLO_POUNDS()))
				return true;
	}
	return false;
}


