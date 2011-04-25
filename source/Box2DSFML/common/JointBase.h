#ifndef __JOINT_BASE_H
#define __JOINT_BASE_H

namespace sfb2d
{
	class JointBase
	{
	protected:
		b2Body *b_ptrJoinedBody1;
		b2Body *b_ptrJoinedBody2;
		b2Joint *b_ptrJoint;

		virtual const b2Joint* Joint() const = NULL;

	public:
		JointBase(void);
		virtual ~JointBase(void);

		const b2Body* GetBody1() const;
		const b2Body* GetBody2() const;
		const b2Joint* GetJoint() const;
	};
}

#endif // __JOINT_BASE_H