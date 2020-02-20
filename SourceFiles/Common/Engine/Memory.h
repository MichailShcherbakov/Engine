#ifndef _MEMORY_H_
#define _MEMORY_H_

#ifndef SAFE_DELETE
	#define SAFE_DELETE(p) { if(p) { delete (p); (p)=nullptr; } }
#endif // SAFE_DELETE 

#ifndef SAFE_RELEASE
	#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=nullptr; } }
#endif // SAFE_RELEASE 

#endif // _MEMORY_H_