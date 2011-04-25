#include "GameIncludes.h"

namespace TryGame
{
	int DemoTexture::_elementCounter = 0;

	DemoTexture::DemoTexture() : 
		assetsDir("../../../assets/")
	{
		_elementCounter = 0;

		_ptrBoundaries = NULL;
		_ptrBodies = NULL;
		_ptrPlayable = NULL;

		_ptrNextLevel = NULL;
		_ptrPrevLevel = NULL;
	}

	DemoTexture::~DemoTexture(void)
	{
		for(int i = 0; i < STATIC_OBJECT_COUNT; i++)
		{
			delete _ptrBoundaries[i];
			_ptrBoundaries[i] = NULL;
		}

		delete [] _ptrBoundaries;
		_ptrBoundaries = NULL;

		for(int i = 0; i < DYNAMIC_OBJECT_COUNT; i++)
		{
			delete _ptrBodies[i];
			_ptrBodies[i] = NULL;
		}

		delete [] _ptrBodies;
		_ptrBodies = NULL;

		delete _ptrPlayable;
		_ptrPlayable = NULL;

		_ptrPrevLevel = NULL;
		_ptrNextLevel = NULL;
		//delete _ptrPrevLevel;
		//delete _ptrNextLevel;
	}

	void DemoTexture::Init(b2World &refPhysWorld, sfb2d::Actor **gameElements)
	{
		CreateStaticBodies(refPhysWorld, gameElements);
		CreateBodies(refPhysWorld, gameElements);
	}

	DemoLevel* DemoTexture::Create()
	{
		return new DemoTexture;
	}

	DemoLevel* DemoTexture::NextLevel()
	{
		if(_ptrNextLevel == NULL)
			_ptrNextLevel = DemoJoint::Create();
		
		return _ptrNextLevel;
	}

	DemoLevel* DemoTexture::PrevLevel()
	{
		return NULL;
	}

	void DemoTexture::CreateStaticBodies(b2World &refPhysWorld, sfb2d::Actor **gameElements)
	{
		_ptrBoundaries = new Sprite *[STATIC_OBJECT_COUNT];
		for(int i = 0; i < DYNAMIC_OBJECT_COUNT; i++)
		{
			_ptrBoundaries[i] = NULL;
		}

		_ptrBoundaries[0] = new Sprite;
		_ptrBoundaries[0]->CreateBox(refPhysWorld,
			"../../../assets/wall.png",
			b2_staticBody,
			0.1f,
			0.5f,
			0.5f,
			Vector2f(8, 600),
			Vector2f(1, 1),
			Vector2f(1.0f, 1.0f),
			Vector2f(4.0f, 300.0f));
		gameElements[_elementCounter++] = _ptrBoundaries[0];

		_ptrBoundaries[1] = new Sprite;
		_ptrBoundaries[1]->CreateBox(refPhysWorld,
			"../../../assets/ground-roof.png",
			b2_staticBody,
			0.1f,
			0.5f,
			0.5f,
			Vector2f(800, 8),
			Vector2f(1, 1),
			Vector2f(1.0f, 1.0f),
			Vector2f(400.0f, 595.0f));
		gameElements[_elementCounter++] = _ptrBoundaries[1];

		_ptrBoundaries[2] = new Sprite;
		_ptrBoundaries[2]->CreateBox(refPhysWorld,
			"../../../assets/wall.png",
			b2_staticBody,
			1.0f,
			0.5f,
			0.5f,
			Vector2f(8, 600),
			Vector2f(1, 1),
			Vector2f(1.0f, 1.0f),
			Vector2f(795.0f, 300.0f));
		gameElements[_elementCounter++] = _ptrBoundaries[2];

		_ptrBoundaries[3] = new Sprite;
		_ptrBoundaries[3]->CreateBox(refPhysWorld,
			"../../../assets/ground-roof.png",
			b2_staticBody,
			1.0f,
			0.5f,
			0.1f,
			Vector2f(8, 600),
			Vector2f(1, 1),
			Vector2f(1.0f, 1.0f),
			Vector2f(400.0f, 4.0f));
		gameElements[_elementCounter++] = _ptrBoundaries[3];
	}

	void DemoTexture::CreateBodies(b2World &refPhysWorld, sfb2d::Actor **gameElements)
	{		
		_ptrBodies = new Sprite *[DYNAMIC_OBJECT_COUNT];
		for(int i = 0; i < DYNAMIC_OBJECT_COUNT; i++)
		{
			_ptrBodies[i] = NULL;
		}

		_ptrBodies[0] = new Sprite;
		_ptrBodies[0]->CreateBox(refPhysWorld,
			"../../../assets/transparent-rect.png",
			b2_dynamicBody,
			1.0f, 
			0.0f, 
			0.8f,
			Vector2f(64.0f, 64.0f),
			Vector2f(1.0f, 1.0f),
			Vector2f(1.0f / 2.0f, 1.0f / 2.0f),
			Vector2f(400.0f, 300.0f),
			0.0f);
		gameElements[_elementCounter++] = _ptrBodies[0];

		_ptrBodies[1] = new Sprite;
		_ptrBodies[1]->CreateBox(refPhysWorld,
			"../../../assets/transparent-rect.png",
			b2_dynamicBody,
			1.0f, 
			0.0f, 
			0.8f,
			Vector2f(64.0f, 64.0f),
			Vector2f(1.0f, 1.0f),
			Vector2f(1.0f / 2.0f, 1.0f / 2.0f),
			Vector2f(400.0f, 300.0f),
			0.0f);
		gameElements[_elementCounter++] = _ptrBodies[1];

		_ptrBodies[2] = new Sprite;
		_ptrBodies[2]->CreateBox(refPhysWorld,
			"../../../assets/transparent-rect.png",
			b2_dynamicBody,
			1.0f, 
			0.0f, 
			0.8f,
			Vector2f(64.0f, 64.0f),
			Vector2f(1.0f, 1.0f),
			Vector2f(1.0f / 2.0f, 1.0f / 2.0f),
			Vector2f(400.0f, 300.0f),
			0.0f);
		gameElements[_elementCounter++] = _ptrBodies[2];

		_ptrPlayable = new Sprite;
		_ptrPlayable->CreateCircle(refPhysWorld,
			"../../../assets/transparent-circle.png",
			b2_dynamicBody,
			1.0f, 
			1.0f, 
			0.8f,
			Vector2f(64.0f, 64.0f),
			Vector2f(1.0f, 1.0f),
			Vector2f(1.0f / 2.0f, 1.0f / 2.0f),
			Vector2f(400.0f, 300.0f),
			0.0f);
		gameElements[_elementCounter++] = _ptrPlayable;
	}

	int DemoTexture::GetElementCount() const
	{
		return STATIC_OBJECT_COUNT + DYNAMIC_OBJECT_COUNT + PLAYABLE_COUNT;
	}
	
	sfb2d::Actor *DemoTexture::GetPlayable() const
	{
		return _ptrPlayable;
	}
}
