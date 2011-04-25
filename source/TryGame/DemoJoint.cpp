#include "GameIncludes.h"

namespace TryGame
{
	/*struct RagDoll
	{

	};*/

	int DemoJoint::_elementCounter = 0;

	DemoJoint::DemoJoint(void)
	{
		_elementCounter = 0;
		_ptrPlayer = NULL;
		//_ptrRagDollComponents = NULL;
		//_ptrRagDollJoint = NULL;
		_ptrRopes = NULL;
		_ptrRopeJoints = NULL;
		_ptrHanger = NULL;

		_ptrPrevLevel = NULL;
		_ptrNextLevel = NULL;
	}

	DemoJoint::~DemoJoint(void)
	{
		/*for(int i = 0; i < RAGDOLL_COMPONENT_COUNT; i++)
		{
			delete _ptrRagDollComponents[i];
			_ptrRagDollComponents[i] = NULL;
		}

		delete [] _ptrRagDollComponents;*/

		for(int i = 0; i < DYNAMIC_OBJECT_COUNT; i++)
		{
			delete _ptrRopes[i];
			_ptrRopes[i] = NULL;
		}

		delete [] _ptrRopes;

		for(int i = 0; i < ROPE_JOINT_COUNT; i++)
		{
			delete _ptrRopeJoints[i];
			_ptrRopeJoints[i] = NULL;
		}

		delete [] _ptrRopeJoints;

		for(int i = 0; i < HANGER_COUNT; i++)
		{
			delete _ptrHanger[i];
			_ptrHanger[i] = NULL;
		}

		delete [] _ptrHanger;

		delete _ptrPlayer;
		_ptrPlayer = NULL;
		
		_ptrPrevLevel = NULL;
		_ptrNextLevel = NULL;
		//delete _ptrPrevLevel;
		//delete _ptrNextLevel;
	}

	DemoLevel *DemoJoint::Create()
	{
		return new DemoJoint;
	}
	DemoLevel *DemoJoint::NextLevel()
	{
		return NULL;
	}
	
	DemoLevel *DemoJoint::PrevLevel()
	{
		if(_ptrPrevLevel == NULL)
			_ptrPrevLevel = DemoTexture::Create();

		return _ptrPrevLevel;
	}
	
	void DemoJoint::Init(b2World &refPhysWorld, sfb2d::Actor **gameElements)
	{
		_ptrPlayer = new BasicShape;
		_ptrPlayer->CreateCircle(refPhysWorld,
			1.0f,
			b2Vec2(500.0f, 450.0f),
			0.0f,
			b2_dynamicBody,
			1.0f,
			0.7f,
			0.7f);
		gameElements[_elementCounter++] = _ptrPlayer;

		CreateRope(refPhysWorld, gameElements);
		//CreateRagDoll(refPhysWorld, gameElements);
	}

	int DemoJoint::GetElementCount() const
	{
		return PLAYABLE_COUNT + DYNAMIC_OBJECT_COUNT + HANGER_COUNT;// + RAGDOLL_COMPONENT_COUNT;
	}
	
	sfb2d::Actor *DemoJoint::GetPlayable() const
	{
		return _ptrPlayer;
	}

	void DemoJoint::CreateRope(b2World &refPhysWorld, sfb2d::Actor **gameElements)
	{
		{
			b2Vec2 ropesVertices[4];
			ropesVertices[0] = b2Vec2(0.0f, 1.0f);
			ropesVertices[1] = b2Vec2(0.0f, 0.0f);
			ropesVertices[2] = b2Vec2(4.0f, 0.0f);
			ropesVertices[3] = b2Vec2(4.0f, 1.0f);

			_ptrRopes = new BasicShape *[DYNAMIC_OBJECT_COUNT];
			for(int i = 0; i < DYNAMIC_OBJECT_COUNT; i++)
			{
				_ptrRopes[i] = NULL;
			}

			_ptrHanger = new BasicShape *[HANGER_COUNT];
			for(int i = 0; i < HANGER_COUNT; i++)
			{
				_ptrHanger[i] = NULL;
			}

			_ptrRopeJoints = new DistanceJoint *[ROPE_JOINT_COUNT];
			for(int i = 0; i < ROPE_JOINT_COUNT; i++)
			{
				_ptrRopeJoints[i] = NULL;
			}

			for(int i = 0; i < DYNAMIC_OBJECT_COUNT; i++)
			{
				_ptrRopes[i] = new BasicShape;
				_ptrRopes[i]->CreatePolygon(refPhysWorld,
					ropesVertices,
					4,
					b2Vec2(400, 500),
					0.0f,
					b2_dynamicBody,
					0.5f,
					0.7f,
					0.1f);
				gameElements[_elementCounter++] = _ptrRopes[i];
			}
		}

		_ptrHanger[0] = new BasicShape;
		_ptrHanger[0]->CreateCircle(refPhysWorld, 
			8.0f,
			b2Vec2(150.0f, 480.0f),
			0.0f,
			b2_staticBody,
			1.0f,
			0.2f,
			0.3f);
		gameElements[_elementCounter++] = _ptrHanger[0];

		_ptrHanger[1] = new BasicShape;
		_ptrHanger[1]->CreateCircle(refPhysWorld, 
			8.0f,
			b2Vec2(650.0f, 480.0f),
			0.0f,
			b2_staticBody,
			1.0f,
			0.2f,
			0.3f);
		gameElements[_elementCounter++] = _ptrHanger[1];

		for(int i = 0; i < ROPE_JOINT_COUNT - 2; i++)
		{
			_ptrRopeJoints[i] = new DistanceJoint;
			_ptrRopeJoints[i]->Create(refPhysWorld, 
				*_ptrRopes[i],
				*_ptrRopes[i + 1],
				b2Vec2(3.0f, 0.5f),
				b2Vec2(1.0f, 0.5f),
				false,
				0.9f,
				7.5f,
				0.1f);
		}

		_ptrRopeJoints[ROPE_JOINT_COUNT - 2] = new DistanceJoint;
		_ptrRopeJoints[ROPE_JOINT_COUNT - 2]->Create(refPhysWorld,
			*_ptrHanger[0],
			*_ptrRopes[0],
			b2Vec2(8.0f, 0.0f),
			b2Vec2(1.0f, 0.5f),
			false,
			0.5f,
			7.5f,
			0.1f);

		_ptrRopeJoints[ROPE_JOINT_COUNT - 1] = new DistanceJoint;
		_ptrRopeJoints[ROPE_JOINT_COUNT - 1]->Create(refPhysWorld,
			*_ptrHanger[1],
			*_ptrRopes[DYNAMIC_OBJECT_COUNT - 1],
			b2Vec2(-8.0f, 0.0f),
			b2Vec2(3.0f, 0.5f),
			false,
			0.5f,
			7.5f,
			0.1f);
	}

	/*void DemoJoint::CreateRagDoll(b2World &refPhysWorld, sfb2d::Actor **gameElements)
	{
		_ptrRagDollComponents = new BasicShape *[RAGDOLL_COMPONENT_COUNT];
		_ptrRagDollJoint = new RevoluteJoint *[RAGDOLL_JOINT];

		{
			b2Vec2 armLegsVertices[4];
			armLegsVertices[0] = b2Vec2(0.0f, 1.0f);
			armLegsVertices[1] = b2Vec2(0.0f, 0.0f);
			armLegsVertices[2] = b2Vec2(3.0f, 0.0f);
			armLegsVertices[3] = b2Vec2(3.0f, 1.0f);

			for(int i = 0; i < RAGDOLL_COMPONENT_COUNT - 2; i++)
			{
				_ptrRagDollComponents[i] = new BasicShape;
				_ptrRagDollComponents[i]->CreatePolygon(refPhysWorld,
					armLegsVertices,
					4,
					b2Vec2(500, 10),
					0.0f,
					b2_dynamicBody,
					1.0f, 
					1.0f,
					0.02f);
				gameElements[_elementCounter++] = _ptrRagDollComponents[i];
			}
		}

		{
			b2Vec2 headVertices[3];
			headVertices[0] = b2Vec2(2.5f, 4.0f);
			headVertices[1] = b2Vec2(0.0f, 0.0f);
			headVertices[2] = b2Vec2(4.0f, 0.0f);

			_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 2] = new BasicShape;
			_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 2]->CreatePolygon(refPhysWorld,
				headVertices,
				3,
				b2Vec2(500, 10),
				0.0f,
				b2_dynamicBody,
				1.0f, 
				1.0f,
				0.02f);
			gameElements[_elementCounter++] = _ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 2];
		}

		{
			b2Vec2 bodyVertices[4];
			bodyVertices[0] = b2Vec2(0.0f, 7.0f);
			bodyVertices[1] = b2Vec2(0.0f, 0.0f);
			bodyVertices[2] = b2Vec2(5.0f, 0.0f);
			bodyVertices[3] = b2Vec2(5.0f, 7.0f);

			_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 1] = new BasicShape;
			_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 1]->CreatePolygon(refPhysWorld,
				bodyVertices,
				4,
				b2Vec2(500, 10),
				0.0f,
				b2_dynamicBody,
				1.0f, 
				1.0f,
				0.02f);
			gameElements[_elementCounter++] = _ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 1];
		}

		_ptrRagDollJoint[0] = new RevoluteJoint;
		_ptrRagDollJoint[0]->Create(refPhysWorld,
			*_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 1],
			*_ptrRagDollComponents[0],
			b2Vec2(5.0f, 1.5f),
			b2Vec2(0.0f, 0.5f),
			true,
			-90.0f * DEG_TO_RAD,
			90.0f * DEG_TO_RAD,
			true);

		_ptrRagDollJoint[1] = new RevoluteJoint;
		_ptrRagDollJoint[1]->Create(refPhysWorld,
			*_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 1],
			*_ptrRagDollComponents[1],
			b2Vec2(0.0f, 1.5f),
			b2Vec2(3.0f, 0.5f),
			true,
			-90.0f * DEG_TO_RAD,
			90.0f * DEG_TO_RAD,
			true);

		_ptrRagDollJoint[2] = new RevoluteJoint;
		_ptrRagDollJoint[2]->Create(refPhysWorld,
			*_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 1],
			*_ptrRagDollComponents[2],
			b2Vec2(0.5f, 7.0f),
			b2Vec2(0.0f, 0.5f),
			true,
			-180.0f * DEG_TO_RAD,
			180.0f * DEG_TO_RAD,
			true);

		_ptrRagDollJoint[3] = new RevoluteJoint;
		_ptrRagDollJoint[3]->Create(refPhysWorld,
			*_ptrRagDollComponents[RAGDOLL_COMPONENT_COUNT - 1],
			*_ptrRagDollComponents[3],
			b2Vec2(4.5f, 7.0f),
			b2Vec2(0.0f, 0.5f),
			true,
			-180.0f * DEG_TO_RAD,
			180.0f * DEG_TO_RAD,
			true);

		_ptrRagDollJoint[4] = new RevoluteJoint;
		_ptrRagDollJoint[4]->Create(refPhysWorld,
			*_ptrRagDollComponents[0],
			*_ptrRagDollComponents[4],
			b2Vec2(3.0f, 0.5f),
			b2Vec2(0.0f, 0.5f),
			true,
			-180.0f * DEG_TO_RAD,
			180.0f * DEG_TO_RAD,
			true);

		_ptrRagDollJoint[5] = new RevoluteJoint;
		_ptrRagDollJoint[5]->Create(refPhysWorld,
			*_ptrRagDollComponents[1],
			*_ptrRagDollComponents[5],
			b2Vec2(3.0f, 0.5f),
			b2Vec2(0.0f, 0.5f),
			true,
			-180.0f * DEG_TO_RAD,
			180.0f * DEG_TO_RAD,
			true);

		_ptrRagDollJoint[6] = new RevoluteJoint;
		_ptrRagDollJoint[6]->Create(refPhysWorld,
			*_ptrRagDollComponents[2],
			*_ptrRagDollComponents[6],
			b2Vec2(3.0f, 0.5f),
			b2Vec2(0.0f, 0.5f),
			true,
			-180.0f * DEG_TO_RAD,
			180.0f * DEG_TO_RAD,
			true);

		_ptrRagDollJoint[7] = new RevoluteJoint;
		_ptrRagDollJoint[7]->Create(refPhysWorld,
			*_ptrRagDollComponents[3],
			*_ptrRagDollComponents[7],
			b2Vec2(3.0f, 0.5f),
			b2Vec2(0.0f, 0.5f),
			true,
			-180.0f * DEG_TO_RAD,
			180.0f * DEG_TO_RAD,
			true);
	}*/
}
