#pragma once
#include <list>
namespace BaseFramework
{
	class Entity;
	class Collider;
	class CollisionManager
	{
	public:
		CollisionManager();
		~CollisionManager();

		void addCollider(Collider* collider);
		void removeCollider(Collider* collider);

		void CheckCollisions();
		bool CollisionTest(Collider* a, Collider* b);

	private:
		std::list<Collider*> _colliders;
	};
}
