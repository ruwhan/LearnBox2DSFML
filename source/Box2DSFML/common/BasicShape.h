#ifndef __BASIC_SHAPE
#define __BASIC_SHAPE

namespace sfb2d
{
	class BasicShape : public Actor
	{
	private:
		sf::Shape _shape;
		//sf::Drawable _shape;

		b2World *_ptrWorld;

		b2BodyDef _bodyDefinition;
		b2Body *_ptrBody;
		b2FixtureDef _fixtureDefinition;
		b2Fixture *_ptrFixture;
		b2PolygonShape *_ptrPhysicsShapePoly;
		b2CircleShape *_ptrPhysicsShapeCircle;

		b2Vec2 _tempCurrentPos;

	public:
		BasicShape(void);
		BasicShape(b2World *world);
		~BasicShape(void);

		void CreatePolygon(b2World &refWorld, 
			b2Vec2 *vertices,
			const int vertexCount,
			const b2Vec2 &initPosition,
			const float initAngle,
			const b2BodyType bodyType,
			const float density = 0.0f,
			const float friction = 0.0f,
			const float restitution = 0.0f);

		void CreateCircle(b2World &refWorld, 
			const float radius,
			const b2Vec2 &initPosition,
			const float initAngle,
			const b2BodyType bodyType,
			const float density = 0.0f,
			const float friction = 0.0f,
			const float restitution = 0.0f);

		b2Body* GetBody() const;

		void Update(sf::RenderWindow &window);
		void Draw(sf::RenderWindow &window);
	};
}

#endif // __BASIC_SHAPE
