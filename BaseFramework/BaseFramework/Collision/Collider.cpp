#include "Collider.h"
namespace BaseFramework
{
	sf::Vector2f Collider::getPosition() const
	{
		return sf::Vector2f();
	}
	/*Entity& Collider::getEntity()
	{
		return nullptr;
	}*/
	void Collider::enable()
	{
		_isEnabled = true;
	}
	void Collider::disable()
	{
		_isEnabled = false;
	}
	bool Collider::isEnabled() const
	{
		return _isEnabled;
	}
	float Collider::getRadius() const
	{
		return _radius;
	}
}