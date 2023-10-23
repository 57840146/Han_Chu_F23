#pragma once

#if BV_DEBUG==2
	#define BV_ERROR(x) std::cout<<x<<std::endl;
	#define BV_LOG(x) std::cout<<x<<std::endl;
#elif BV_DEBUG==1
	#define BV_ERROR(x) std::cout<<x<<std::endl;
	#define BV_LOG(x)
#else
	#define BV_ERROR(x)
	#define BV_LOG(x)
#endif

#ifdef BEAVER_MSCPP
	#ifdef BEAVER_LIB
		#define BEAVER_API __declspec(dllexport)
	#else
		#define BEAVER_API __declspec(dllimport)
	#endif
#else
	#define BEAVER_API
#endif

#define BEAVER_APPLICATION_START(ClassName) \
int main(){ \
	ClassName game; \
	game.Run(); \
	return 0; \
}
