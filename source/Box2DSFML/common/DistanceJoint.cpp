#include "GeneralInclude.h"

#include "DistanceJoint.h"

namespace sfb2d
{
	DistanceJoint::DistanceJoint(void)
	{
	}

	DistanceJoint::~DistanceJoint(void)
	{
	}

	void DistanceJoint::Create(b2World &world,
		const BasicShape &joinedShape1,
		const BasicShape &joinedShape2,
		const b2Vec2 &anchor1,
		const b2Vec2 &anchor2,
		const bool collideConnected,
		const float length,
		const float frequencyHz,
		const float dampingRatio)
	{
		b_ptrJoinedBody1 = const_cast<b2Body*>(joinedShape1.GetBody());
		b_ptrJoinedBody2 = const_cast<b2Body*>(joinedShape2.GetBody());
		
		//b2DistanceJointDef _distanceJointDefinition;
		_distanceJointDefinition.bodyA = b_ptrJoinedBody1;
		_distanceJointDefinition.bodyB = b_ptrJoinedBody2;
		_distanceJointDefinition.localAnchorA = anchor1;
		_distanceJointDefinition.localAnchorB = anchor2;
		_distanceJointDefinition.collideConnected = collideConnected;
		_distanceJointDefinition.length = length;
		_distanceJointDefinition.frequencyHz = frequencyHz;
		_distanceJointDefinition.dampingRatio = dampingRatio;

		b_ptrJoint = world.CreateJoint(&_distanceJointDefinition);
	}

	const b2DistanceJoint* DistanceJoint::Joint() const
	{
		return static_cast<b2DistanceJoint*>(b_ptrJoint);
	}
}
