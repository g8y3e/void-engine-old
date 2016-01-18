#ifndef VOID_BASE_MATH_MATH_3D_H_
#define VOID_BASE_MATH_MATH_3D_H_

namespace void_base {
namespace math {
	class Vector3f{
	public:
		Vector3f();
		Vector3f(float x, float y, float z);

	public:
		float x_ = 0;
		float y_ = 0;
		float z_ = 0;
	};
}
}

#endif