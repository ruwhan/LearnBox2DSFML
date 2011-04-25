#ifndef __GEAR_JOINT_H
#define __GEAR_JOINT_H

namespace sfb2d
{
	class GearJoint : public JointBase
	{
	private:
		b2GearJointDef _gearJointDefinition;
		b2Joint *_ptrJoint1;
		b2Joint *_ptrJoint2;

	public:
		GearJoint(void);
		~GearJoint(void);

		void Create(b2World &world,
			const BasicShape &joinedBody1,
			const BasicShape &joinedBody2,
			const JointBase &joint1,
			const JointBase &joint2,
			const bool collideConnected = false,
			const float ratio = 1.0f);

		const b2GearJoint* Joint() const;
	};
}

#endif // __GEAR_JOINT_H

