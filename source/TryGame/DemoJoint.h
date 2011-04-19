#ifndef __DEMO_JOINT_H
#define __DEMO_JOINT_H

namespace TryGame
{
	class DemoJoint : public DemoLevel
	{
	private:
		enum ELEMENTS_COUNT
		{
			HANGER_COUNT = 2,
			DYNAMIC_OBJECT_COUNT = 15,
			//RAGDOLL_COMPONENT_COUNT = 10
			PLAYABLE_COUNT = 1
		};

		enum JOINTS_COUNT
		{
			ROPE_JOINT_COUNT = 16,
			RAGDOLL_JOINT = 9
		};

		My2DPhys::BasicShape *_ptrPlayer;
		My2DPhys::BasicShape **_ptrRopes;
		My2DPhys::BasicShape **_ptrHanger;
		//My2DPhys::BasicShape **_ptrRagDollComponents;

		My2DPhys::DistanceJoint **_ptrRopeJoints;
		//My2DPhys::RevoluteJoint **_ptrRagDollJoint;

		static int _elementCounter;

		DemoLevel *_ptrNextLevel;
		DemoLevel *_ptrPrevLevel;

		void CreateRope(b2World &refPhysWorld, My2DPhys::Actor **gameElements);
		//void CreateRagDoll(b2World &refPhysWorld, My2DPhys::Actor **gameElements);

	public:
		DemoJoint(void);
		~DemoJoint(void);

		static DemoLevel* Create();
		virtual DemoLevel* NextLevel();
		virtual DemoLevel* PrevLevel();
		virtual void Init(b2World &refPhysWorld, My2DPhys::Actor **gameElements);
		virtual int GetElementCount() const;
		virtual My2DPhys::Actor *GetPlayable() const;
	};
}

#endif // __DEMO_JOINT_H

