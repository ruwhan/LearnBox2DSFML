#include "GeneralInclude.h"

namespace sfb2d
{
	BasicShape::BasicShape(void)
	{
		_ptrWorld = NULL;

		_ptrBody = NULL;
		_ptrFixture = NULL;
		_ptrPhysicsShapePoly = NULL;
		_ptrPhysicsShapeCircle = NULL;
	}

	BasicShape::BasicShape(b2World *world)
	{
		_ptrWorld = world;

		_ptrBody = NULL;
		_ptrFixture = NULL;
		_ptrPhysicsShapePoly = NULL;
		_ptrPhysicsShapeCircle = NULL;
	}

	BasicShape::~BasicShape(void)
	{
		/*if(_ptrWorld != NULL)
		{
			_ptrWorld->DestroyBody(_ptrBody);
		}*/

		if(_ptrPhysicsShapePoly != NULL)
			_ptrPhysicsShapePoly = NULL;

		if(_ptrPhysicsShapeCircle != NULL)
			_ptrPhysicsShapeCircle = NULL;

		if(_ptrFixture != NULL)
			_ptrFixture = NULL;

		if(_ptrBody != NULL)
			_ptrBody = NULL;

		if(_ptrWorld != NULL)
			_ptrWorld = NULL;
	}

	void BasicShape::CreatePolygon(b2World &refWorld, 
			b2Vec2 *vertices,
			const int vertexCount,
			const b2Vec2 &initPosition,
			const float initAngle,
			const b2BodyType bodyType,
			const float density,
			const float friction,
			const float restitution)
	{
		_bodyDefinition.type = bodyType;
		_bodyDefinition.position.Set(initPosition.x * METERS_PER_PIXEL, initPosition.y * METERS_PER_PIXEL);
		_bodyDefinition.angle = -(initAngle * DEG_TO_RAD);
		_ptrBody = refWorld.CreateBody(&_bodyDefinition);
		
		_ptrBody->SetSleepingAllowed(true);
		_ptrBody->SetAngularDamping(0.1f);

		_ptrPhysicsShapePoly = new b2PolygonShape;
		_ptrPhysicsShapePoly->Set(vertices, vertexCount);
		
		_fixtureDefinition.density = density;
		_fixtureDefinition.friction = friction;
		_fixtureDefinition.restitution = restitution;
		_fixtureDefinition.shape = _ptrPhysicsShapePoly;
		_ptrFixture = _ptrBody->CreateFixture(&_fixtureDefinition);
			

		for(int i = 0; i < vertexCount; i++)
		{
			_shape.AddPoint(vertices[i].x * PIXELS_PER_METER, vertices[i].y * PIXELS_PER_METER, sf::Color::Cyan);
		}

		_shape.SetOutlineWidth(1.0f);
		_shape.EnableOutline(true);

		_shape.SetPosition(initPosition.x, initPosition.y);
		_shape.SetRotation(initAngle);
	}

	void BasicShape::CreateCircle(b2World &refWorld, 
			const float radius,
			const b2Vec2 &initPosition,
			const float initAngle,
			const b2BodyType bodyType,
			const float density,
			const float friction,
			const float restitution)
	{
		_bodyDefinition.type = bodyType;
		_bodyDefinition.position.Set(initPosition.x * METERS_PER_PIXEL, initPosition.y * METERS_PER_PIXEL);
		_bodyDefinition.angle = -(initAngle * DEG_TO_RAD);
		_ptrBody = refWorld.CreateBody(&_bodyDefinition);

		_ptrBody->SetSleepingAllowed(true);
		_ptrBody->SetAngularDamping(0.1f);

		_ptrPhysicsShapeCircle = new b2CircleShape;
		_ptrPhysicsShapeCircle->m_radius = radius;
		
		_fixtureDefinition.density = density;
		_fixtureDefinition.friction = friction;
		_fixtureDefinition.restitution = restitution;
		_fixtureDefinition.shape = _ptrPhysicsShapeCircle;
		_ptrFixture = _ptrBody->CreateFixture(&_fixtureDefinition);
		
		_shape = sf::Shape::Circle(0, 0, radius * PIXELS_PER_METER, sf::Color::Cyan, 1.0f, sf::Color::Black);
		
		_shape.SetPosition(initPosition.x, initPosition.y);
		_shape.SetRotation(initAngle);
	}

	b2Body* BasicShape::GetBody() const
	{
		return _ptrBody;
	}

	void BasicShape::Update(sf::RenderWindow &window)
	{
		_tempCurrentPos = _ptrBody->GetPosition();

		_shape.SetPosition(_tempCurrentPos.x * PIXELS_PER_METER, _tempCurrentPos.y * PIXELS_PER_METER);
		_shape.SetRotation(-(_ptrBody->GetAngle() * RAD_TO_DEG));
	}

	void BasicShape::Draw(sf::RenderWindow &window)
	{
		window.Draw(_shape);
	}
}
