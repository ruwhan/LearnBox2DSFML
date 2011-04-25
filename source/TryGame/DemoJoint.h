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

		sfb2d::BasicShape *_ptrPlayer;
		sfb2d::BasicShape **_ptrRopes;
		sfb2d::BasicShape **_ptrHanger;
		//sfb2d::BasicShape **_ptrRagDollComponents;

		sfb2d::DistanceJoint **_ptrRopeJoints;
		//sfb2d::RevoluteJoint **_ptrRagDollJoint;

		static int _elementCounter;

		DemoLevel *_ptrNextLevel;
		DemoLevel *_ptrPrevLevel;

		void CreateRope(b2World &refPhysWorld, sfb2d::Actor **gameElements);
		//void CreateRagDoll(b2World &refPhysWorld, sfb2d::Actor **gameElements);

	public:
		DemoJoint(void);
		~DemoJoint(void);

		static DemoLevel* Create();
		virtual DemoLevel* NextLevel();
		virtual DemoLevel* PrevLevel();
		virtual void Init(b2World &refPhysWorld, sfb2d::Actor **gameElements);
		virtual int GetElementCount() const;
		virtual sfb2d::Actor *GetPlayable() const;
	};
}

#endif // __DEMO_JOINT_H

