#include "GeneralInclude.h"

#include "Sprite.h"


namespace My2DPhys
{
	//sf::Image Sprite::_imageSrc;

	Sprite::Sprite(void)
	{
		_ptrBody = NULL;
		_ptrFixture = NULL;
		_ptrPhysPoly = NULL;
		_ptrPhysCircle = NULL;
	}


	Sprite::~Sprite(void)
	{
		if(_ptrBody != NULL)
			_ptrBody = NULL;

		if(_ptrFixture != NULL)
			_ptrFixture = NULL;
		
		if(_ptrPhysPoly != NULL)
			_ptrPhysPoly = NULL;

		if(_ptrPhysCircle != NULL)
			_ptrPhysCircle = NULL;
	}

	bool Sprite::CreateBox(b2World &world, 
			char const *textureFileName,
			const b2BodyType bodyType,
			const float density,
			const float friction,
			const float restitution,
			const Vector2f &spritePerFrameSize,
			const Vector2f &rowColumnCount,
			const Vector2f &scale,
			const Vector2f &initPosition,
			const float initAngle)
	{
		if(!_imageSrc.LoadFromFile(textureFileName))
			return false;

		_bodyDefinition.type = bodyType;
		_bodyDefinition.position.Set(initPosition.x * METERS_PER_PIXEL, initPosition.y * METERS_PER_PIXEL);
		_bodyDefinition.angle = -(initAngle * DEG_TO_RAD);
		_bodyDefinition.angularDamping = 0.1f;
		_ptrBody = world.CreateBody(&_bodyDefinition);

		_ptrPhysPoly = new b2PolygonShape;
		_ptrPhysPoly->SetAsBox((_imageSrc.GetWidth() * scale.x * METERS_PER_PIXEL) / 2.0f,
			(_imageSrc.GetHeight() * scale.y * METERS_PER_PIXEL) / 2.0f);

		_fixtureDefinition.density = density;
		_fixtureDefinition.friction = friction;
		_fixtureDefinition.restitution = restitution;
		_fixtureDefinition.shape = _ptrPhysPoly;

		_ptrFixture = _ptrBody->CreateFixture(&_fixtureDefinition);
		
		_sprite.SetImage(_imageSrc);
		_sprite.SetPosition(initPosition.x, initPosition.y);		
		_sprite.SetRotation(initAngle);
		_sprite.SetScale(scale.x, scale.y);
		_sprite.SetCenter(_imageSrc.GetWidth() / 2.0f, _imageSrc.GetHeight() / 2.0f);

		return true;
	}

	bool Sprite::CreateCircle(b2World &world, 
			char const *textureFileName,
			const b2BodyType bodyType,
			const float density,
			const float friction,
			const float restitution,
			const Vector2f &spritePerFrameSize,
			const Vector2f &rowColumnCount,
			const Vector2f &scale,
			const Vector2f &initPosition,
			const float initAngle)
	{
		if(!_imageSrc.LoadFromFile(textureFileName))
			return false;

		_bodyDefinition.type = bodyType;
		_bodyDefinition.position.Set(initPosition.x * METERS_PER_PIXEL, initPosition.y * METERS_PER_PIXEL);
		_bodyDefinition.angle = -(initAngle * DEG_TO_RAD);
		_bodyDefinition.angularDamping = 0.1f;
		_ptrBody = world.CreateBody(&_bodyDefinition);

		_ptrPhysCircle = new b2CircleShape;
		_ptrPhysCircle->m_radius = (_imageSrc.GetWidth() / 2.0f) * scale.x * METERS_PER_PIXEL;

		_fixtureDefinition.density = density;
		_fixtureDefinition.friction = friction;
		_fixtureDefinition.restitution = restitution;
		_fixtureDefinition.shape = _ptrPhysCircle;

		_ptrFixture = _ptrBody->CreateFixture(&_fixtureDefinition);
		
		_sprite.SetImage(_imageSrc);
		_sprite.SetPosition(initPosition.x, initPosition.y);		
		_sprite.SetRotation(initAngle);
		_sprite.SetScale(scale.x, scale.y);
		_sprite.SetCenter(_imageSrc.GetWidth() / 2.0f, _imageSrc.GetHeight() / 2.0f);

		return true;
	}

	void Sprite::Update(sf::RenderWindow &window)
	{
		_tempCurrentPos = _ptrBody->GetPosition();

		_sprite.SetPosition(_tempCurrentPos.x * PIXELS_PER_METER, _tempCurrentPos.y * PIXELS_PER_METER);
		_sprite.SetRotation(-(_ptrBody->GetAngle() * RAD_TO_DEG));
	}

	void Sprite::Draw(sf::RenderWindow &window)
	{
		window.Draw(_sprite);
	}

	b2Body *Sprite::GetBody() const
	{
		return _ptrBody;
	}
}