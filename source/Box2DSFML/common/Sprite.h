#ifndef __SPRITE_H
#define __SPRITE_H

namespace sfb2d
{
	class Sprite : public Actor
	{
	private:
		int _subRectIndexer;
		std::vector<sf::IntRect> _vecSubRect;
		sf::Vector2i _subRectSize;

		//static sf::Image _imageSrc;
		sf::Image _imageSrc;
		sf::Sprite _sprite;

		b2BodyDef _bodyDefinition;
		b2Body *_ptrBody;
		b2FixtureDef _fixtureDefinition;
		b2Fixture *_ptrFixture;
		b2PolygonShape *_ptrPhysPoly;
		b2CircleShape *_ptrPhysCircle;

		Vector2f _tempCurrentPos;
		
		void Animate(sf::RenderWindow &window);

	public:
		Sprite(void);
		~Sprite(void);
		bool CreateBox(b2World &world, 
			char const *textureFileName,
			const b2BodyType bodyType,
			const float density,
			const float friction,
			const float restitution,
			const Vector2f &spritePerFrameSize,
			const Vector2f &rowColumnCount = Vector2f(1.0f, 1.0f),
			const Vector2f &scale = Vector2f(1.0f, 1.0f),
			const Vector2f &initPosition = Vector2f(0.0f, 0.0f),
			const float initAngle = 0.0f);

		bool CreateCircle(b2World &world, 
			char const *textureFileName,
			const b2BodyType bodyType,
			const float density,
			const float friction,
			const float restitution,
			const Vector2f &spritePerFrameSize,
			const Vector2f &rowColumnCount = Vector2f(1.0f, 1.0f),
			const Vector2f &scale = Vector2f(1.0f, 1.0f),
			const Vector2f &initPosition = Vector2f(0.0f, 0.0f),
			const float initAngle = 0.0f);

		void Update(sf::RenderWindow &window);

		void Draw(sf::RenderWindow &window);

		b2Body *GetBody() const;
	};
}

#endif // __SPRITE_H
