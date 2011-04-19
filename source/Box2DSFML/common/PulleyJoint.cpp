#include "GeneralInclude.h"

#include "PulleyJoint.h"


namespace My2DPhys
{
	PulleyJoint::PulleyJoint(void)
	{
	}


	PulleyJoint::~PulleyJoint(void)
	{
	}

	void PulleyJoint::Create(b2World &world,
			const BasicShape &joinedBody1,
			const BasicShape &joinedBody2,
			const b2Vec2 &bodyAnchor1,
			const b2Vec2 &bodyAnchor2,
			const b2Vec2 &groundAnchor1,
			const b2Vec2 &groundAnchor2,
			const bool collideConnected,
			const float maxLength1,
			const float maxLength2,
			const float ratio, 
			const float length1,
			const float length2)
	{
		b_ptrJoinedBody1 = const_cast<b2Body*>(joinedBody1.GetBody());
		b_ptrJoinedBody2 = const_cast<b2Body*>(joinedBody2.GetBody());

		//b2PulleyJointDef pulleyJointDefinition;
		_pulleyJointDefinition.bodyA = b_ptrJoinedBody1;
		_pulleyJointDefinition.bodyB = b_ptrJoinedBody2;
		_pulleyJointDefinition.localAnchorA = bodyAnchor1;
		_pulleyJointDefinition.localAnchorB = bodyAnchor2;
		_pulleyJointDefinition.groundAnchorA = groundAnchor1;
		_pulleyJointDefinition.groundAnchorB = groundAnchor2;
		_pulleyJointDefinition.collideConnected = collideConnected;
		_pulleyJointDefinition.maxLengthA = maxLength1;
		_pulleyJointDefinition.maxLengthB = maxLength2;
		_pulleyJointDefinition.ratio = ratio;
		_pulleyJointDefinition.lengthA = length1;
		_pulleyJointDefinition.lengthB = length2;

		b_ptrJoint = world.CreateJoint(&_pulleyJointDefinition);
	}

	const b2PulleyJoint* PulleyJoint::Joint() const
	{
		return static_cast<b2PulleyJoint*>(b_ptrJoint);
	}
}