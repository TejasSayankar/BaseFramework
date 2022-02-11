#pragma once
#include <SFML/Graphics.hpp>
namespace BaseFramework
{
	class Entity;
	class Collider
	{
	public:
		Collider();
		~Collider();

		sf::Vector2f getPosition() const;
		Entity* getEntity() const;
		void enable();
		void disable();
		bool isEnabled() const;
		float getRadius() const;
	private:
		Entity* _entity;
		float _radius;
		bool _isEnabled;
	};
}

