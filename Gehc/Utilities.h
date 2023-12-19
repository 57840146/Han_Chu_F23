#pragma once

#if hc_DEBUG==2
	#define hc_ERROR(x) std::cout<<x<<std::endl;
	#define hc_LOG(x) std::cout<<x<<std::endl;
#elif hc_DEBUG==1
	#define hc_ERROR(x) std::cout<<x<<std::endl;
	#define hc_LOG(x)
#else
	#define hc_ERROR(x)
	#define hc_LOG(x)
#endif

#ifdef GEHC_MSCPP
	#ifdef GEHC_LIB
		#define GEHC_API __declspec(dllexport)
	#else
		#define GEHC_API __declspec(dllimport)
	#endif
#else
	#define GEHC_API
#endif

#define GEHC_APPLICATION_START(ClassName) \
int main(){ \
	ClassName::Init(); \
	ClassName::RunInterface(); \
	return 0; \
}
