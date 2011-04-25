#include "GameIncludes.h"

namespace TryGame
{
	int DemoPolygon::_elementCounter = 0;

	DemoPolygon::DemoPolygon(void)
	{
		_elementCounter = 0;
		_ptrGround = NULL;
	}


	DemoPolygon::~DemoPolygon(void)
	{
		for(int i = 0; i < GROUND_ELEMENT_COUNT; i++)
		{
			if(_ptrGround[i])
			{
				delete _ptrGround[i];
				_ptrGround[i] = NULL;
			}
		}

		delete [] _ptrGround;
	}

	DemoLevel* DemoPolygon::Create()
	{
		return new DemoPolygon;
	}

	DemoLevel* DemoPolygon::NextLevel()
	{
		return NULL;
	}
	DemoLevel* DemoPolygon::PrevLevel()
	{
		return NULL;
	}

	void DemoPolygon::Init(b2World &refPhysWorld, sfb2d::Actor **gameElements)
	{
		_ptrGround = new BasicShape *[GROUND_ELEMENT_COUNT];

		b2Vec2 bigGroundVertices[4];
		bigGroundVertices[0] = b2Vec2(0.0f, 30.0f);
		bigGroundVertices[1] = b2Vec2(0.0f, 0.0f);
		bigGroundVertices[2] = b2Vec2(100.0f, 0.0f);
		bigGroundVertices[3] = b2Vec2(100.0f, 30.0f);

		_ptrGround[0] = new BasicShape;
		_ptrGround[0]->CreatePolygon(refPhysWorld,
			bigGroundVertices,
			4,
			b2Vec2(0, 360),
			0.0f,
			b2_staticBody,
			1.0f,
			0.7f,
			0.2f);

		gameElements[_elementCounter++] = _ptrGround[0];
	}
	
	int DemoPolygon::GetElementCount() const
	{
		return 1;//GROUND_ELEMENT_COUNT;
	}
	
	sfb2d::Actor *DemoPolygon::GetPlayable() const
	{
		return NULL;
	}
}
