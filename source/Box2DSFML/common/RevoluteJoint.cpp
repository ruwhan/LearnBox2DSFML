#include "GeneralInclude.h"

#include "RevoluteJoint.h"


namespace sfb2d
{
	RevoluteJoint::RevoluteJoint(void)
	{
	}

	RevoluteJoint::~RevoluteJoint(void)
	{
	}

	void RevoluteJoint::Create(b2World &world,
			const BasicShape &joinedBody1,
			const BasicShape &joinedBody2,
			const b2Vec2 &anchor1,
			const b2Vec2 &anchor2,
			const bool collideConnected,
			const float lowerAngle,
			const float upperAngle,
			const bool enableLimit,
			const float maxMotorTorque,
			const float motorSpeed,
			const bool enableMotor,
			const float referenceAngle)
	{
		b_ptrJoinedBody1 = const_cast<b2Body*>(joinedBody1.GetBody());
		b_ptrJoinedBody2 = const_cast<b2Body*>(joinedBody2.GetBody());

		//b2RevoluteJointDef revoluteJointDefinition;
		_revoluteJointDefinition.bodyA = b_ptrJoinedBody1;
		_revoluteJointDefinition.bodyB = b_ptrJoinedBody2;
		_revoluteJointDefinition.localAnchorA = anchor1;
		_revoluteJointDefinition.localAnchorB = anchor2;
		_revoluteJointDefinition.collideConnected = collideConnected;
		_revoluteJointDefinition.lowerAngle = lowerAngle;
		_revoluteJointDefinition.upperAngle = upperAngle;
		_revoluteJointDefinition.enableLimit = enableLimit;
		_revoluteJointDefinition.maxMotorTorque = maxMotorTorque;
		_revoluteJointDefinition.motorSpeed = motorSpeed;
		_revoluteJointDefinition.enableMotor = enableMotor; 
		_revoluteJointDefinition.referenceAngle = referenceAngle;

		b_ptrJoint = world.CreateJoint(&_revoluteJointDefinition);
	}

	const b2RevoluteJoint* RevoluteJoint::Joint() const
	{
		return static_cast<b2RevoluteJoint*>(b_ptrJoint);
	}
}