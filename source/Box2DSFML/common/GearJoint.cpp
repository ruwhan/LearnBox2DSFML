#include "GeneralInclude.h"

#include "GearJoint.h"


namespace My2DPhys
{
	GearJoint::GearJoint(void)
	{
	}


	GearJoint::~GearJoint(void)
	{
	}

	void GearJoint::Create(b2World &world,
		const BasicShape &joinedBody1,
		const BasicShape &joinedBody2,
		const JointBase &joint1,
		const JointBase &joint2,
		const bool collideConnected,
		const float ratio)
	{
		b_ptrJoinedBody1 = const_cast<b2Body*>(joinedBody1.GetBody());
		b_ptrJoinedBody2 = const_cast<b2Body*>(joinedBody1.GetBody());
		_ptrJoint1 = const_cast<b2Joint*>(joint1.GetJoint());
		_ptrJoint2 = const_cast<b2Joint*>(joint2.GetJoint());

		_gearJointDefinition.bodyA = b_ptrJoinedBody1;
		_gearJointDefinition.bodyB = b_ptrJoinedBody2;
		_gearJointDefinition.joint1 = _ptrJoint1;
		_gearJointDefinition.joint2 = _ptrJoint2;
		_gearJointDefinition.collideConnected;
		_gearJointDefinition.ratio;

		b_ptrJoint = world.CreateJoint(&_gearJointDefinition);
	}

	const b2GearJoint *GearJoint::Joint() const
	{
		return static_cast<b2GearJoint*>(b_ptrJoint);
	}
}
