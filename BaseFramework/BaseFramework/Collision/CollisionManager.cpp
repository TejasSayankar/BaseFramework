#include <stack>
#include "CollisionManager.h"
#include "Collider.h"
namespace BaseFramework
{
    CollisionManager::~CollisionManager()
    {
        for (auto colliderIt = _colliders.begin(), end = _colliders.end();
            colliderIt != end;
            ++colliderIt)
        {
            delete *colliderIt;
        }
    }
    void CollisionManager::addCollider(Collider* collider)
    {
        _colliders.push_back(collider);
    }
    void CollisionManager::removeCollider(Collider* collider)
    {
        _colliders.remove(collider);
        delete &collider;
    }
    void CollisionManager::CheckCollisions()
    {
        _colliders.sort([](Collider* a, Collider* b) {
            float startPosA = a->getPosition().x - a->getRadius();
            float startPosB = b->getPosition().x - b->getRadius();
            return startPosA < startPosB;
        });

        std::list<Collider*> collidedColliders;
        for (auto colliderIt = _colliders.begin();
            colliderIt != _colliders.end();
            ++colliderIt)
        {
            for (auto collidedColliderIt = collidedColliders.begin(); 
                collidedColliderIt != collidedColliders.end(); 
                ++collidedColliderIt)
            {
                if (((*colliderIt)->getPosition().x - (*colliderIt)->getRadius()) >=
                    ((*collidedColliderIt)->getPosition().x + (*collidedColliderIt)->getRadius()))
                {
                    Collider* colliderA = *colliderIt;
                    Collider* colliderB = *collidedColliderIt;
                    if (CollisionTest(colliderA, colliderB))
                    {
                        //real collision
                    }
                }
                else
                {
                    collidedColliders.remove(*collidedColliderIt);
                }
            }

            collidedColliders.push_back(*colliderIt);
        }

        /*for (auto colliderAIt = _colliders.begin();
            colliderAIt != _colliders.end();
            ++colliderAIt)
        {
            auto colliderBIt = colliderAIt;
            for (++colliderBIt; colliderBIt != _colliders.end(); ++colliderBIt)
            {
                Collider* colliderA = *colliderAIt;
                Collider* colliderB = *colliderBIt;
                if (CollisionTest(colliderA, colliderB))
                {
                    game->DoCollision(colliderA->entity, colliderB->entity);
                    CheckCollisions(game);
                    return;
                }
            }
        }*/
    }

    bool CollisionManager::CollisionTest(Collider* a, Collider* b)
    {
        if (a->isEnabled() == false)
            return false;
        if (b->isEnabled() == false)
            return false;

        sf::Vector2f diff = a->getPosition() - b->getPosition();
        float distance = sqrt((diff.x * diff.x) + (diff.y * diff.y));
        if (distance < (a->getRadius() + b->getRadius()))
        {
            return true;
        }

        return false;
    }
}