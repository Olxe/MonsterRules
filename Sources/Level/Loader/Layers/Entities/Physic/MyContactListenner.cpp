#include "MyContactListenner.h"

MyContactListenner::MyContactListenner()
{
}

MyContactListenner::~MyContactListenner()
{
}

void MyContactListenner::BeginContact(b2Contact* contact)
{
	entities::PhysicalEntity* bodyA_userData = static_cast<entities::PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	entities::PhysicalEntity* bodyB_userData = static_cast<entities::PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if (!bodyA_userData || !bodyB_userData) return;

	if (contact->GetFixtureA()->IsSensor() == true){
		bodyA_userData->CheckSensorCollision(bodyB_userData);
	}
	else{
		bodyA_userData->CheckCollision(bodyB_userData);
	}

	if (contact->GetFixtureB()->IsSensor() == true){
		bodyB_userData->CheckSensorCollision(bodyA_userData);
	}
	else{
		bodyB_userData->CheckCollision(bodyA_userData);
	}
}

void MyContactListenner::EndContact(b2Contact* contact)
{
	entities::PhysicalEntity* bodyA_userData = static_cast<entities::PhysicalEntity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	entities::PhysicalEntity* bodyB_userData = static_cast<entities::PhysicalEntity*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if (!bodyA_userData || !bodyB_userData) return;

	if (contact->GetFixtureA()->IsSensor() == true){
		bodyA_userData->CheckEndSensorContact(bodyB_userData);
	}
	else{
		bodyA_userData->CheckEndContact(bodyB_userData);
	}

	if (contact->GetFixtureB()->IsSensor() == true){
		bodyB_userData->CheckEndSensorContact(bodyA_userData);
	}
	else{
		bodyB_userData->CheckEndContact(bodyA_userData);
	}
}

void MyContactListenner::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
}

void MyContactListenner::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
}
