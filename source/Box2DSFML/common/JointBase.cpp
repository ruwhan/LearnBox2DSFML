#include "GeneralInclude.h"

#include "JointBase.h"

namespace My2DPhys
{
	JointBase::JointBase(void)
	{
		b_ptrJoinedBody1 = NULL;
		b_ptrJoinedBody2 = NULL;
		b_ptrJoint = NULL;
	}


	JointBase::~JointBase(void)
	{
		if(b_ptrJoinedBody1 != NULL)
			b_ptrJoinedBody1 = NULL;

		if(b_ptrJoinedBody2 != NULL)
			b_ptrJoinedBody2 = NULL;

		if(b_ptrJoint != NULL)
			b_ptrJoint = NULL;
	}

	const b2Body* JointBase::GetBody1() const
	{
		return b_ptrJoinedBody1;
	}

	const b2Body* JointBase::GetBody2() const
	{
		return b_ptrJoinedBody2;
	}
	
	const b2Joint* JointBase::GetJoint() const
	{
		return b_ptrJoint;
	}
}
