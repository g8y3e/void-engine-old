#ifndef VOID_BASE_DEBUG_FPS_FPS_COUNTER_H_
#define VOID_BASE_DEBUG_FPS_FPS_COUNTER_H_

#include <void_base/define/system_define.h>

namespace void_base {
namespace debug {
	class FPSCounter {
	public:
		FPSCounter();

	public:
		void init();

		void count();
		void countStatic();

	public:
		int getCount();
		int getCountStatic();

		int getPreviousCount();
		int getPreviousCountStatic();
		
	public:
		bool printData();

	private:
		ulong previous_time_;

		int previous_count_;
		int previous_static_count_;

		int count_;
		int static_count_;
	};
}
}

#endif