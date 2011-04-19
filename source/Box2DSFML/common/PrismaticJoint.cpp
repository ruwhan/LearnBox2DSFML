#include "GeneralInclude.h"

#include "PrismaticJoint.h"


namespace My2DPhys
{
	PrismaticJoint::PrismaticJoint(void)
	{
	}


	PrismaticJoint::~PrismaticJoint(void)
	{
	}

	void PrismaticJoint::Create(b2World &world,
			const BasicShape &joinedBody1,
			const BasicShape &joinedBody2,
			const b2Vec2 &anchor1,
			const b2Vec2 &anchor2,
			const bool collideConnected,
			const float lowerTranslation,
			const float upperTranslation,
			const bool enableLimit,
			const float maxMotorTorque,
			const float motorSpeed,
			const bool enableMotor,
			const b2Vec2 &localTranslationAxis1)
	{
		b_ptrJoinedBody1 = const_cast<b2Body*>(joinedBody1.GetBody());
		b_ptrJoinedBody2 = const_cast<b2Body*>(joinedBody2.GetBody());

		//b2PrismaticJointDef prismaticJointDefinition;
		_prismaticJointDefinition.bodyA = b_ptrJoinedBody1;
		_prismaticJointDefinition.bodyB = b_ptrJoinedBody2;
		_prismaticJointDefinition.localAnchorA = anchor1;
		_prismaticJointDefinition.localAnchorB = anchor2;
		_prismaticJointDefinition.collideConnected = collideConnected;
		_prismaticJointDefinition.lowerTranslation = lowerTranslation;
		_prismaticJointDefinition.upperTranslation = upperTranslation;
		_prismaticJointDefinition.enableLimit = enableLimit;
		_prismaticJointDefinition.maxMotorForce = maxMotorTorque;
		_prismaticJointDefinition.motorSpeed = motorSpeed;
		_prismaticJointDefinition.enableMotor = enableMotor;
		_prismaticJointDefinition.localAxis1 = localTranslationAxis1;

		b_ptrJoint = world.CreateJoint(&_prismaticJointDefinition);
	}

	const b2PrismaticJoint* PrismaticJoint::Joint() const
	{
		return static_cast<b2PrismaticJoint*>(b_ptrJoint);
	}
}
