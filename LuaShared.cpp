//Crossrefrenaced between:
//		https://www.lua.org/manual/5.1/manual.html
//		https://www.lua.org/manual/5.2/manual.html
//		https://www.lua.org/manual/5.3/manual.html
//		https://www.lua.org/manual/5.4/manual.html
//		http://luajit.org/ext_c_api.html
//
//		Turns out some of the stuff is also from other portions of lua.org outside of the manuals. Be ready to explore if anything breaks.


#if defined SYSTEM_WINDOWS
	#include<Windows.h>
	#include<libloaderapi.h>
#elif defined SYSTEM_POSIX
	#include<dlfcn.h>
	
	void* shared_lib = dlopen("lua_shared.so", RTLD_LAZY);
#endif


//Some things might not be defined. Put them here
typedef int (*lua_CFunction)(lua_State *L);
typedef ... lua_Integer;
typedef ... lua_Number;
typedef struct lua_State lua_State;
typedef ... lua_Unsigned;
typedef struct luaL_Buffer luaL_Buffer;

typedef const char*(*lua_Reader)(lua_State *L,void *data,size_t *size);
typedef void(*lua_WarnFunction)(void *ud,const char *msg,int tocont);
typedef int(*lua_Writer)(lua_State *L,const void* p,size_t sz,void* ud);

typedef struct luaL_Reg{
	const char* name;
	lua_CFunction func;
}luaL_Reg;

typedef struct luaL_Stream{
	FILE *f;
	lua_CFunction closef;
}luaL_Stream;

typedef struct lua_Debug {
	int event;
	const char *name;			/* (n) */
	const char *namewhat;		/* (n) */
	const char *what;			/* (S) */
	const char *source;			/* (S) */
	size_t srclen;				/* (S) */
	int currentline;			/* (l) */
	int linedefined;			/* (S) */
	int lastlinedefined;		/* (S) */
	unsigned char nups;			/* (u) number of upvalues */
	unsigned char nparams;		/* (u) number of parameters */
	char isvararg;				/* (u) */
	char istailcall;			/* (t) */
	unsigned short ftransfer;	/* (r) index of first value transferred */
	unsigned short ntransfer;	/* (r) number of transferred values */
	char short_src[LUA_IDSIZE];	/* (S) */
	/* private part */
	other fields
}lua_Debug;

typedef void (*lua_Hook)(lua_State *L,lua_Debug *ar);


typedef lua_CFunction(*_lua_atpanic)(lua_State* L,lua_CFunction panicf);
#if defined SYSTEM_WINDOWS
	static _lua_atpanic lua_atpanic = (_lua_atpanic)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_atpanic");
#elif defined SYSTEM_POSIX
	static _lua_atpanic lua_atpanic = (_lua_atpanic)dlsym(shared_lib,"lua_atpanic");
#endif

typedef void(*_lua_call)(lua_State* L,int nargs,int nresults);
#if defined SYSTEM_WINDOWS
	static _lua_call lua_call = (_lua_call)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_call");
#elif defined SYSTEM_POSIX
	static _lua_call lua_call = (_lua_call)dlsym(shared_lib,"lua_call");
#endif

typedef int(*_lua_checkstack)(lua_State* L,int extra);
#if defined SYSTEM_WINDOWS
	static _lua_checkstack lua_checkstack = (_lua_checkstack)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_checkstack");
#elif defined SYSTEM_POSIX
	static _lua_checkstack lua_checkstack = (_lua_checkstack)dlsym(shared_lib,"lua_checkstack");
#endif

typedef void(*_lua_close)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_close lua_close = (_lua_close)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_close");
#elif defined SYSTEM_POSIX
	static _lua_close lua_close = (_lua_close)dlsym(shared_lib,"lua_close");
#endif

typedef int n(*_lua_concat)(lua_State* L,int n);
#if defined SYSTEM_WINDOWS
	static _lua_concat lua_concat = (_lua_concat)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_concat");
#elif defined SYSTEM_POSIX
	static _lua_concat lua_concat = (_lua_concat)dlsym(shared_lib,"lua_concat");
#endif

typedef int(*_lua_cpcall)(lua_State* L,lua_CFunction func,void* ud);
#if defined SYSTEM_WINDOWS
	static _lua_cpcall lua_cpcall = (_lua_cpcall)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_cpcall");
#elif defined SYSTEM_POSIX
	static _lua_cpcall lua_cpcall = (_lua_cpcall)dlsym(shared_lib,"lua_cpcall");
#endif

typedef void(*_lua_createtable)(lua_State* L,int narr,int nrec);
#if defined SYSTEM_WINDOWS
	static _lua_createtable lua_createtable = (_lua_createtable)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_createtable");
#elif defined SYSTEM_POSIX
	static _lua_createtable lua_createtable = (_lua_createtable)dlsym(shared_lib,"lua_createtable");
#endif

typedef int(*_lua_dump)(lua_State* L,lua_Writer writer,void* data);
#if defined SYSTEM_WINDOWS
	static _lua_dump lua_dump = (_lua_dump)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_dump");
#elif defined SYSTEM_POSIX
	static _lua_dump lua_dump = (_lua_dump)dlsym(shared_lib,"lua_dump");
#endif

typedef int(*_lua_equal)(lua_State* L,int index1,int index2);
#if defined SYSTEM_WINDOWS
	static _lua_equal lua_equal = (_lua_equal)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_equal");
#elif defined SYSTEM_POSIX
	static _lua_equal lua_equal = (_lua_equal)dlsym(shared_lib,"lua_equal");
#endif

typedef int(*_lua_error)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_error lua_error = (_lua_error)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_error");
#elif defined SYSTEM_POSIX
	static _lua_error lua_error = (_lua_error)dlsym(shared_lib,"lua_error");
#endif

typedef int(*_lua_gc)(lua_State* L,int what,int data);
#if defined SYSTEM_WINDOWS
	static _lua_gc lua_gc = (_lua_gc)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_gc");
#elif defined SYSTEM_POSIX
	static _lua_gc lua_gc = (_lua_gc)dlsym(shared_lib,"lua_gc");
#endif

typedef lua_Alloc(*_lua_getallocf)(lua_State* L,void** ud);
#if defined SYSTEM_WINDOWS
	static _lua_getallocf lua_getallocf = (_lua_getallocf)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getallocf");
#elif defined SYSTEM_POSIX
	static _lua_getallocf lua_getallocf = (_lua_getallocf)dlsym(shared_lib,"lua_getallocf");
#endif

typedef void(*_lua_getfenv)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_getfenv lua_getfenv = (_lua_getfenv)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getfenv");
#elif defined SYSTEM_POSIX
	static _lua_getfenv lua_getfenv = (_lua_getfenv)dlsym(shared_lib,"lua_getfenv");
#endif

typedef void(*_lua_getfield)(lua_State* L,int index,const char *k);
#if defined SYSTEM_WINDOWS
	static _lua_getfield lua_getfield = (_lua_getfield)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getfield");
#elif defined SYSTEM_POSIX
	static _lua_getfield lua_getfield = (_lua_getfield)dlsym(shared_lib,"lua_getfield");
#endif

typedef lua_Hook(*_lua_gethook)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_gethook lua_gethook = (_lua_gethook)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_gethook");
#elif defined SYSTEM_POSIX
	static _lua_gethook lua_gethook = (_lua_gethook)dlsym(shared_lib,"lua_gethook");
#endif

typedef int(*_lua_gethookcount)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_gethookcount lua_gethookcount = (_lua_gethookcount)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_gethookcount");
#elif defined SYSTEM_POSIX
	static _lua_gethookcount lua_gethookcount = (_lua_gethookcount)dlsym(shared_lib,"lua_gethookcount");
#endif

typedef int(*_lua_gethookmask)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_gethookmask lua_gethookmask = (_lua_gethookmask)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_gethookmask");
#elif defined SYSTEM_POSIX
	static _lua_gethookmask lua_gethookmask = (_lua_gethookmask)dlsym(shared_lib,"lua_gethookmask");
#endif

typedef int(*_lua_getinfo)(lua_State* L,const char* what,lua_Debug* ar);
#if defined SYSTEM_WINDOWS
	static _lua_getinfo lua_getinfo = (_lua_getinfo)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getinfo");
#elif defined SYSTEM_POSIX
	static _lua_getinfo lua_getinfo = (_lua_getinfo)dlsym(shared_lib,"lua_getinfo");
#endif

typedef const char*(*_lua_getlocal)(lua_State* L,lua_Debug *ar,int n);
#if defined SYSTEM_WINDOWS
	static _lua_getlocal lua_getlocal = (_lua_getlocal)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getlocal");
#elif defined SYSTEM_POSIX
	static _lua_getlocal lua_getlocal = (_lua_getlocal)dlsym(shared_lib,"lua_getlocal");
#endif

typedef int(*_lua_getmetatable)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_getmetatable lua_getmetatable = (_lua_getmetatable)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getmetatable");
#elif defined SYSTEM_POSIX
	static _lua_getmetatable lua_getmetatable = (_lua_getmetatable)dlsym(shared_lib,"lua_getmetatable");
#endif

typedef int(*_lua_getstack)(lua_State* L,int level,lua_Debug *ar);
#if defined SYSTEM_WINDOWS
	static _lua_getstack lua_getstack = (_lua_getstack)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getstack");
#elif defined SYSTEM_POSIX
	static _lua_getstack lua_getstack = (_lua_getstack)dlsym(shared_lib,"lua_getstack");
#endif

typedef void(*_lua_gettable)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_gettable lua_gettable = (_lua_gettable)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_gettable");
#elif defined SYSTEM_POSIX
	static _lua_gettable lua_gettable = (_lua_gettable)dlsym(shared_lib,"lua_gettable");
#endif

typedef int(*_lua_gettop)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_gettop lua_gettop = (_lua_gettop)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_gettop");
#elif defined SYSTEM_POSIX
	static _lua_gettop lua_gettop = (_lua_gettop)dlsym(shared_lib,"lua_gettop");
#endif

typedef const char*(*_lua_getupvalue)(lua_State* L,int funcindex,int n);
#if defined SYSTEM_WINDOWS
	static _lua_getupvalue lua_getupvalue = (_lua_getupvalue)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_getupvalue");
#elif defined SYSTEM_POSIX
	static _lua_getupvalue lua_getupvalue = (_lua_getupvalue)dlsym(shared_lib,"lua_getupvalue");
#endif

typedef void(*_lua_insert)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_insert lua_insert = (_lua_insert)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_insert");
#elif defined SYSTEM_POSIX
	static _lua_insert lua_insert = (_lua_insert)dlsym(shared_lib,"lua_insert");
#endif

typedef int(*_lua_iscfunction)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_iscfunction lua_iscfunction = (_lua_iscfunction)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_iscfunction");
#elif defined SYSTEM_POSIX
	static _lua_iscfunction lua_iscfunction = (_lua_iscfunction)dlsym(shared_lib,"lua_iscfunction");
#endif

typedef int(*_lua_isnumber)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_isnumber lua_isnumber = (_lua_isnumber)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_isnumber");
#elif defined SYSTEM_POSIX
	static _lua_isnumber lua_isnumber = (_lua_isnumber)dlsym(shared_lib,"lua_isnumber");
#endif

typedef int(*_lua_isstring)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_isstring lua_isstring = (_lua_isstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_isstring");
#elif defined SYSTEM_POSIX
	static _lua_isstring lua_isstring = (_lua_isstring)dlsym(shared_lib,"lua_isstring");
#endif

typedef int(*_lua_isuserdata)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_isuserdata lua_isuserdata = (_lua_isuserdata)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_isuserdata");
#elif defined SYSTEM_POSIX
	static _lua_isuserdata lua_isuserdata = (_lua_isuserdata)dlsym(shared_lib,"lua_isuserdata");
#endif

typedef int(*_lua_lessthan)(lua_State* L,int index1,int index2);
#if defined SYSTEM_WINDOWS
	static _lua_lessthan lua_lessthan = (_lua_lessthan)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_lessthan");
#elif defined SYSTEM_POSIX
	static _lua_lessthan lua_lessthan = (_lua_lessthan)dlsym(shared_lib,"lua_lessthan");
#endif

typedef int(*_lua_load)(lua_State* L,lua_Reader reader,void* data,const char* chunkname);
#if defined SYSTEM_WINDOWS
	static _lua_load lua_load = (_lua_load)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_load");
#elif defined SYSTEM_POSIX
	static _lua_load lua_load = (_lua_load)dlsym(shared_lib,"lua_load");
#endif

typedef int(*_lua_loadx)(lua_State* L,lua_Reader reader,void* data,const char* chunkname,const char* mode);
#if defined SYSTEM_WINDOWS
	static _lua_loadx lua_loadx = (_lua_loadx)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_loadx");
#elif defined SYSTEM_POSIX
	static _lua_loadx lua_loadx = (_lua_loadx)dlsym(shared_lib,"lua_loadx");
#endif

typedef lua_State*(*_lua_newstate)(lua_State* L,void* ud);
#if defined SYSTEM_WINDOWS
	static _lua_newstate lua_newstate = (_lua_newstate)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_newstate");
#elif defined SYSTEM_POSIX
	static _lua_newstate lua_newstate = (_lua_newstate)dlsym(shared_lib,"lua_newstate");
#endif

typedef lua_State*(*_lua_newthread)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_newthread lua_newthread = (_lua_newthread)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_newthread");
#elif defined SYSTEM_POSIX
	static _lua_newthread lua_newthread = (_lua_newthread)dlsym(shared_lib,"lua_newthread");
#endif

typedef void(*_lua_newuserdata)(lua_State* L,size_t size);
#if defined SYSTEM_WINDOWS
	static _lua_newuserdata lua_newuserdata = (_lua_newuserdata)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_newuserdata");
#elif defined SYSTEM_POSIX
	static _lua_newuserdata lua_newuserdata = (_lua_newuserdata)dlsym(shared_lib,"lua_newuserdata");
#endif

typedef int(*_lua_next)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_next lua_next = (_lua_next)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_next");
#elif defined SYSTEM_POSIX
	static _lua_next lua_next = (_lua_next)dlsym(shared_lib,"lua_next");
#endif

typedef size_t(*_lua_objlen)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_objlen lua_objlen = (_lua_objlen)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_objlen");
#elif defined SYSTEM_POSIX
	static _lua_objlen lua_objlen = (_lua_objlen)dlsym(shared_lib,"lua_objlen");
#endif

typedef int(*_lua_pcall)(lua_State* L,int nargs, int nresults, int errfunc);
#if defined SYSTEM_WINDOWS
	static _lua_pcall lua_pcall = (_lua_pcall)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pcall");
#elif defined SYSTEM_POSIX
	static _lua_pcall lua_pcall = (_lua_pcall)dlsym(shared_lib,"lua_pcall");
#endif

typedef void(*_lua_pushboolean)(lua_State* L,int b);
#if defined SYSTEM_WINDOWS
	static _lua_pushboolean lua_pushboolean = (_lua_pushboolean)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushboolean");
#elif defined SYSTEM_POSIX
	static _lua_pushboolean lua_pushboolean = (_lua_pushboolean)dlsym(shared_lib,"lua_pushboolean");
#endif

typedef void(*_lua_pushcclosure)(lua_State* L,lua_CFunction fn, int n);
#if defined SYSTEM_WINDOWS
	static _lua_pushcclosure lua_pushcclosure = (_lua_pushcclosure)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushcclosure");
#elif defined SYSTEM_POSIX
	static _lua_pushcclosure lua_pushcclosure = (_lua_pushcclosure)dlsym(shared_lib,"lua_pushcclosure");
#endif

typedef const char*(*_lua_pushfstring)(lua_State* L,const char *fmt, ...);
#if defined SYSTEM_WINDOWS
	static _lua_pushfstring lua_pushfstring = (_lua_pushfstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushfstring");
#elif defined SYSTEM_POSIX
	static _lua_pushfstring lua_pushfstring = (_lua_pushfstring)dlsym(shared_lib,"lua_pushfstring");
#endif

typedef void(*_lua_pushinteger)(lua_State* L,lua_Integer n);
#if defined SYSTEM_WINDOWS
	static _lua_pushinteger lua_pushinteger = (_lua_pushinteger)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushinteger");
#elif defined SYSTEM_POSIX
	static _lua_pushinteger lua_pushinteger = (_lua_pushinteger)dlsym(shared_lib,"lua_pushinteger");
#endif

typedef void(*_lua_pushlightuserdata)(lua_State* L,void *p);
#if defined SYSTEM_WINDOWS
	static _lua_pushlightuserdata lua_pushlightuserdata = (_lua_pushlightuserdata)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushlightuserdata");
#elif defined SYSTEM_POSIX
	static _lua_pushlightuserdata lua_pushlightuserdata = (_lua_pushlightuserdata)dlsym(shared_lib,"lua_pushlightuserdata");
#endif

typedef void(*_lua_pushlstring)(lua_State* L,const char *s, size_t len);
#if defined SYSTEM_WINDOWS
	static _lua_pushlstring lua_pushlstring = (_lua_pushlstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushlstring");
#elif defined SYSTEM_POSIX
	static _lua_pushlstring lua_pushlstring = (_lua_pushlstring)dlsym(shared_lib,"lua_pushlstring");
#endif
/////////////////////////////////
typedef void(*_lua_pushnil)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_pushnil lua_pushnil = (_lua_pushnil)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushnil");
#elif defined SYSTEM_POSIX
	static _lua_pushnil lua_pushnil = (_lua_pushnil)dlsym(shared_lib,"lua_pushnil");
#endif

typedef void(*_lua_pushnumber)(lua_State* L,lua_Number n);
#if defined SYSTEM_WINDOWS
	static _lua_pushnumber lua_pushnumber = (_lua_pushnumber)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushnumber");
#elif defined SYSTEM_POSIX
	static _lua_pushnumber lua_pushnumber = (_lua_pushnumber)dlsym(shared_lib,"lua_pushnumber");
#endif

typedef void(*_lua_pushstring)(lua_State* L,const char *s);
#if defined SYSTEM_WINDOWS
	static _lua_pushstring lua_pushstring = (_lua_pushstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushstring");
#elif defined SYSTEM_POSIX
	static _lua_pushstring lua_pushstring = (_lua_pushstring)dlsym(shared_lib,"lua_pushstring");
#endif

typedef int(*_lua_pushthread)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_pushthread lua_pushthread = (_lua_pushthread)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushthread");
#elif defined SYSTEM_POSIX
	static _lua_pushthread lua_pushthread = (_lua_pushthread)dlsym(shared_lib,"lua_pushthread");
#endif

typedef void(*_lua_pushvalue)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_pushvalue lua_pushvalue = (_lua_pushvalue)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushvalue");
#elif defined SYSTEM_POSIX
	static _lua_pushvalue lua_pushvalue = (_lua_pushvalue)dlsym(shared_lib,"lua_pushvalue");
#endif

typedef const char*(*_lua_pushvfstring)(lua_State* L,const char *fmt,va_list argp);
#if defined SYSTEM_WINDOWS
	static _lua_pushvfstring lua_pushvfstring = (_lua_pushvfstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_pushvfstring");
#elif defined SYSTEM_POSIX
	static _lua_pushvfstring lua_pushvfstring = (_lua_pushvfstring)dlsym(shared_lib,"lua_pushvfstring");
#endif

typedef int(*_lua_rawequal)(lua_State* L,int index1, int index2);
#if defined SYSTEM_WINDOWS
	static _lua_rawequal lua_rawequal = (_lua_rawequal)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_rawequal");
#elif defined SYSTEM_POSIX
	static _lua_rawequal lua_rawequal = (_lua_rawequal)dlsym(shared_lib,"lua_rawequal");
#endif

typedef void(*_lua_rawget)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_rawget lua_rawget = (_lua_rawget)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_rawget");
#elif defined SYSTEM_POSIX
	static _lua_rawget lua_rawget = (_lua_rawget)dlsym(shared_lib,"lua_rawget");
#endif

typedef void(*_lua_rawgeti)(lua_State* L,int index, int n);
#if defined SYSTEM_WINDOWS
	static _lua_rawgeti lua_rawgeti = (_lua_rawgeti)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_rawgeti");
#elif defined SYSTEM_POSIX
	static _lua_rawgeti lua_rawgeti = (_lua_rawgeti)dlsym(shared_lib,"lua_rawgeti");
#endif

typedef void(*_lua_rawset)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_rawset lua_rawset = (_lua_rawset)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_rawset");
#elif defined SYSTEM_POSIX
	static _lua_rawset lua_rawset = (_lua_rawset)dlsym(shared_lib,"lua_rawset");
#endif

typedef void(*_lua_rawseti)(lua_State* L,int index, int n);
#if defined SYSTEM_WINDOWS
	static _lua_rawseti lua_rawseti = (_lua_rawseti)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_rawseti");
#elif defined SYSTEM_POSIX
	static _lua_rawseti lua_rawseti = (_lua_rawseti)dlsym(shared_lib,"lua_rawseti");
#endif

typedef void(*_lua_remove)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_remove lua_remove = (_lua_remove)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_remove");
#elif defined SYSTEM_POSIX
	static _lua_remove lua_remove = (_lua_remove)dlsym(shared_lib,"lua_remove");
#endif

typedef void(*_lua_replace)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_replace lua_replace = (_lua_replace)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_replace");
#elif defined SYSTEM_POSIX
	static _lua_replace lua_replace = (_lua_replace)dlsym(shared_lib,"lua_replace");
#endif

typedef int(*_lua_resume_real)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_resume_real lua_resume_real = (_lua_resume_real)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_resume_real");
#elif defined SYSTEM_POSIX
	static _lua_resume_real lua_resume_real = (_lua_resume_real)dlsym(shared_lib,"lua_resume_real");
#endif

typedef lua_Alloc(*_lua_setallocf)(lua_State* L,void **ud);
#if defined SYSTEM_WINDOWS
	static _lua_setallocf lua_setallocf = (_lua_setallocf)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_setallocf");
#elif defined SYSTEM_POSIX
	static _lua_setallocf lua_setallocf = (_lua_setallocf)dlsym(shared_lib,"lua_setallocf");
#endif

typedef int(*_lua_setfenv)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_setfenv lua_setfenv = (_lua_setfenv)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_setfenv");
#elif defined SYSTEM_POSIX
	static _lua_setfenv lua_setfenv = (_lua_setfenv)dlsym(shared_lib,"lua_setfenv");
#endif

typedef void(*_lua_setfield)(lua_State* L,int index, const char *k);
#if defined SYSTEM_WINDOWS
	static _lua_setfield lua_setfield = (_lua_setfield)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_setfield");
#elif defined SYSTEM_POSIX
	static _lua_setfield lua_setfield = (_lua_setfield)dlsym(shared_lib,"lua_setfield");
#endif

typedef int(*_lua_sethook)(lua_State* L,lua_Hook f, int mask, int count);
#if defined SYSTEM_WINDOWS
	static _lua_sethook lua_sethook = (_lua_sethook)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_sethook");
#elif defined SYSTEM_POSIX
	static _lua_sethook lua_sethook = (_lua_sethook)dlsym(shared_lib,"lua_sethook");
#endif

typedef const char*(*_lua_setlocal)(lua_State* L,lua_Debug *ar, int n);
#if defined SYSTEM_WINDOWS
	static _lua_setlocal lua_setlocal = (_lua_setlocal)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_setlocal");
#elif defined SYSTEM_POSIX
	static _lua_setlocal lua_setlocal = (_lua_setlocal)dlsym(shared_lib,"lua_setlocal");
#endif

typedef int(*_lua_setmetatable)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_setmetatable lua_setmetatable = (_lua_setmetatable)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_setmetatable");
#elif defined SYSTEM_POSIX
	static _lua_setmetatable lua_setmetatable = (_lua_setmetatable)dlsym(shared_lib,"lua_setmetatable");
#endif

typedef void(*_lua_settable)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_settable lua_settable = (_lua_settable)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_settable");
#elif defined SYSTEM_POSIX
	static _lua_settable lua_settable = (_lua_settable)dlsym(shared_lib,"lua_settable");
#endif

typedef void(*_lua_settop)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_settop lua_settop = (_lua_settop)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_settop");
#elif defined SYSTEM_POSIX
	static _lua_settop lua_settop = (_lua_settop)dlsym(shared_lib,"lua_settop");
#endif

typedef const char*(*_lua_setupvalue)(lua_State* L,int funcindex, int n);
#if defined SYSTEM_WINDOWS
	static _lua_setupvalue lua_setupvalue = (_lua_setupvalue)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_setupvalue");
#elif defined SYSTEM_POSIX
	static _lua_setupvalue lua_setupvalue = (_lua_setupvalue)dlsym(shared_lib,"lua_setupvalue");
#endif

typedef int(*_lua_status)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _lua_status lua_status = (_lua_status)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_status");
#elif defined SYSTEM_POSIX
	static _lua_status lua_status = (_lua_status)dlsym(shared_lib,"lua_status");
#endif

typedef int(*_lua_toboolean)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_toboolean lua_toboolean = (_lua_toboolean)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_toboolean");
#elif defined SYSTEM_POSIX
	static _lua_toboolean lua_toboolean = (_lua_toboolean)dlsym(shared_lib,"lua_toboolean");
#endif

typedef lua_CFunction(*_lua_tocfunction)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_tocfunction lua_tocfunction = (_lua_tocfunction)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_tocfunction");
#elif defined SYSTEM_POSIX
	static _lua_tocfunction lua_tocfunction = (_lua_tocfunction)dlsym(shared_lib,"lua_tocfunction");
#endif

typedef lua_Integer(*_lua_tointeger)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_tointeger lua_tointeger = (_lua_tointeger)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_tointeger");
#elif defined SYSTEM_POSIX
	static _lua_tointeger lua_tointeger = (_lua_tointeger)dlsym(shared_lib,"lua_tointeger");
#endif

typedef const char*(*_lua_tolstring)(lua_State* L,int index, size_t *len);
#if defined SYSTEM_WINDOWS
	static _lua_tolstring lua_tolstring = (_lua_tolstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_tolstring");
#elif defined SYSTEM_POSIX
	static _lua_tolstring lua_tolstring = (_lua_tolstring)dlsym(shared_lib,"lua_tolstring");
#endif

typedef lua_Number(*_lua_tonumber)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_tonumber lua_tonumber = (_lua_tonumber)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_tonumber");
#elif defined SYSTEM_POSIX
	static _lua_tonumber lua_tonumber = (_lua_tonumber)dlsym(shared_lib,"lua_tonumber");
#endif

typedef const char*(*_lua_topointer)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_topointer lua_topointer = (_lua_topointer)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_topointer");
#elif defined SYSTEM_POSIX
	static _lua_topointer lua_topointer = (_lua_topointer)dlsym(shared_lib,"lua_topointer");
#endif

typedef lua_State*(*_lua_tothread)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_tothread lua_tothread = (_lua_tothread)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_tothread");
#elif defined SYSTEM_POSIX
	static _lua_tothread lua_tothread = (_lua_tothread)dlsym(shared_lib,"lua_tothread");
#endif

typedef void(*_lua_touserdata)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_touserdata lua_touserdata = (_lua_touserdata)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_touserdata");
#elif defined SYSTEM_POSIX
	static _lua_touserdata lua_touserdata = (_lua_touserdata)dlsym(shared_lib,"lua_touserdata");
#endif

typedef int(*_lua_type)(lua_State* L,int index);
#if defined SYSTEM_WINDOWS
	static _lua_type lua_type = (_lua_type)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_type");
#elif defined SYSTEM_POSIX
	static _lua_type lua_type = (_lua_type)dlsym(shared_lib,"lua_type");
#endif

typedef const char*(*_lua_typename)(lua_State* L,int tp);
#if defined SYSTEM_WINDOWS
	static _lua_typename lua_typename = (_lua_typename)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_typename");
#elif defined SYSTEM_POSIX
	static _lua_typename lua_typename = (_lua_typename)dlsym(shared_lib,"lua_typename");
#endif

typedef int(*_lua_upvalueid)(lua_State* L,int funcindex,int n);
#if defined SYSTEM_WINDOWS
	static _lua_upvalueid lua_upvalueid = (_lua_upvalueid)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_upvalueid");
#elif defined SYSTEM_POSIX
	static _lua_upvalueid lua_upvalueid = (_lua_upvalueid)dlsym(shared_lib,"lua_upvalueid");
#endif

typedef void(*_lua_upvaluejoin)(lua_State* L,int funcindex1, int n1, int funcindex2, int n2);
#if defined SYSTEM_WINDOWS
	static _lua_upvaluejoin lua_upvaluejoin = (_lua_upvaluejoin)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_upvaluejoin");
#elif defined SYSTEM_POSIX
	static _lua_upvaluejoin lua_upvaluejoin = (_lua_upvaluejoin)dlsym(shared_lib,"lua_upvaluejoin");
#endif

typedef void(*_lua_xmove)(lua_State* L,lua_State *to, int n);
#if defined SYSTEM_WINDOWS
	static _lua_xmove lua_xmove = (_lua_xmove)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_xmove");
#elif defined SYSTEM_POSIX
	static _lua_xmove lua_xmove = (_lua_xmove)dlsym(shared_lib,"lua_xmove");
#endif

typedef int(*_lua_yield)(lua_State* L,int nresults);
#if defined SYSTEM_WINDOWS
	static _lua_yield lua_yield = (_lua_yield)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"lua_yield");
#elif defined SYSTEM_POSIX
	static _lua_yield lua_yield = (_lua_yield)dlsym(shared_lib,"lua_yield");
#endif

typedef int(*_luaJIT_setmode)(lua_State* L,int idx, int mode);
#if defined SYSTEM_WINDOWS
	static _luaJIT_setmode luaJIT_setmode = (_luaJIT_setmode)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaJIT_setmode");
#elif defined SYSTEM_POSIX
	static _luaJIT_setmode luaJIT_setmode = (_luaJIT_setmode)dlsym(shared_lib,"luaJIT_setmode");
#endif

/* //incomplete
typedef int(*_luaJIT_version_2_0_4)(lua_State* L,);
#if defined SYSTEM_WINDOWS
	static _luaJIT_version_2_0_4 luaJIT_version_2_0_4 = (_luaJIT_version_2_0_4)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaJIT_version_2_0_4");
#elif defined SYSTEM_POSIX
	static _luaJIT_version_2_0_4 luaJIT_version_2_0_4 = (_luaJIT_version_2_0_4)dlsym(shared_lib,"luaJIT_version_2_0_4");
#endif
*/
typedef void(*_luaL_addlstring)(luaL_Buffer *B, const char *s, size_t l);
#if defined SYSTEM_WINDOWS
	static _luaL_addlstring luaL_addlstring = (_luaL_addlstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_addlstring");
#elif defined SYSTEM_POSIX
	static _luaL_addlstring luaL_addlstring = (_luaL_addlstring)dlsym(shared_lib,"luaL_addlstring");
#endif

typedef void(*_luaL_addstring)(luaL_Buffer *B, const char *s);
#if defined SYSTEM_WINDOWS
	static _luaL_addstring luaL_addstring = (_luaL_addstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_addstring");
#elif defined SYSTEM_POSIX
	static _luaL_addstring luaL_addstring = (_luaL_addstring)dlsym(shared_lib,"luaL_addstring");
#endif

typedef void(*_luaL_addvalue)(luaL_Buffer *B);
#if defined SYSTEM_WINDOWS
	static _luaL_addvalue luaL_addvalue = (_luaL_addvalue)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_addvalue");
#elif defined SYSTEM_POSIX
	static _luaL_addvalue luaL_addvalue = (_luaL_addvalue)dlsym(shared_lib,"luaL_addvalue");
#endif

typedef int(*_luaL_argerror)(lua_State* L,int narg, const char *extramsg);
#if defined SYSTEM_WINDOWS
	static _luaL_argerror luaL_argerror = (_luaL_argerror)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_argerror");
#elif defined SYSTEM_POSIX
	static _luaL_argerror luaL_argerror = (_luaL_argerror)dlsym(shared_lib,"luaL_argerror");
#endif

typedef void(*_luaL_buffinit)(lua_State* L,luaL_Buffer *B);
#if defined SYSTEM_WINDOWS
	static _luaL_buffinit luaL_buffinit = (_luaL_buffinit)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_buffinit");
#elif defined SYSTEM_POSIX
	static _luaL_buffinit luaL_buffinit = (_luaL_buffinit)dlsym(shared_lib,"luaL_buffinit");
#endif

typedef int(*_luaL_callmeta)(lua_State* L,int obj, const char *e);
#if defined SYSTEM_WINDOWS
	static _luaL_callmeta luaL_callmeta = (_luaL_callmeta)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_callmeta");
#elif defined SYSTEM_POSIX
	static _luaL_callmeta luaL_callmeta = (_luaL_callmeta)dlsym(shared_lib,"luaL_callmeta");
#endif

typedef void(*_luaL_checkany)(lua_State* L,int narg);
#if defined SYSTEM_WINDOWS
	static _luaL_checkany luaL_checkany = (_luaL_checkany)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checkany");
#elif defined SYSTEM_POSIX
	static _luaL_checkany luaL_checkany = (_luaL_checkany)dlsym(shared_lib,"luaL_checkany");
#endif

typedef lua_Integer(*_luaL_checkinteger)(lua_State* L,int narg);
#if defined SYSTEM_WINDOWS
	static _luaL_checkinteger luaL_checkinteger = (_luaL_checkinteger)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checkinteger");
#elif defined SYSTEM_POSIX
	static _luaL_checkinteger luaL_checkinteger = (_luaL_checkinteger)dlsym(shared_lib,"luaL_checkinteger");
#endif

typedef const char*(*_luaL_checklstring)(lua_State* L,int narg, size_t *l);
#if defined SYSTEM_WINDOWS
	static _luaL_checklstring luaL_checklstring = (_luaL_checklstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checklstring");
#elif defined SYSTEM_POSIX
	static _luaL_checklstring luaL_checklstring = (_luaL_checklstring)dlsym(shared_lib,"luaL_checklstring");
#endif

typedef lua_Number(*_luaL_checknumber)(lua_State* L,int narg);
#if defined SYSTEM_WINDOWS
	static _luaL_checknumber luaL_checknumber = (_luaL_checknumber)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checknumber");
#elif defined SYSTEM_POSIX
	static _luaL_checknumber luaL_checknumber = (_luaL_checknumber)dlsym(shared_lib,"luaL_checknumber");
#endif

typedef int(*_luaL_checkoption)(lua_State* L,int narg,const char *def,const char *const lst[]);
#if defined SYSTEM_WINDOWS
	static _luaL_checkoption luaL_checkoption = (_luaL_checkoption)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checkoption");
#elif defined SYSTEM_POSIX
	static _luaL_checkoption luaL_checkoption = (_luaL_checkoption)dlsym(shared_lib,"luaL_checkoption");
#endif

typedef void(*_luaL_checkstack)(lua_State* L,int sz, const char *msg);
#if defined SYSTEM_WINDOWS
	static _luaL_checkstack luaL_checkstack = (_luaL_checkstack)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checkstack");
#elif defined SYSTEM_POSIX
	static _luaL_checkstack luaL_checkstack = (_luaL_checkstack)dlsym(shared_lib,"luaL_checkstack");
#endif

typedef void(*_luaL_checktype)(lua_State* L, int narg, int t);
#if defined SYSTEM_WINDOWS
	static _luaL_checktype luaL_checktype = (_luaL_checktype)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checktype");
#elif defined SYSTEM_POSIX
	static _luaL_checktype luaL_checktype = (_luaL_checktype)dlsym(shared_lib,"luaL_checktype");
#endif

typedef void(*_luaL_checkudata)(lua_State* L,int narg, const char *tname);
#if defined SYSTEM_WINDOWS
	static _luaL_checkudata luaL_checkudata = (_luaL_checkudata)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_checkudata");
#elif defined SYSTEM_POSIX
	static _luaL_checkudata luaL_checkudata = (_luaL_checkudata)dlsym(shared_lib,"luaL_checkudata");
#endif

typedef int(*_luaL_error)(lua_State* L,const char *fmt, ...);
#if defined SYSTEM_WINDOWS
	static _luaL_error luaL_error = (_luaL_error)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_error");
#elif defined SYSTEM_POSIX
	static _luaL_error luaL_error = (_luaL_error)dlsym(shared_lib,"luaL_error");
#endif

typedef int(*_luaL_execresult)(lua_State* L,int stat);
#if defined SYSTEM_WINDOWS
	static _luaL_execresult luaL_execresult = (_luaL_execresult)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_execresult");
#elif defined SYSTEM_POSIX
	static _luaL_execresult luaL_execresult = (_luaL_execresult)dlsym(shared_lib,"luaL_execresult");
#endif

typedef int(*_luaL_fileresult)(lua_State* L,int stat, const char *fname);
#if defined SYSTEM_WINDOWS
	static _luaL_fileresult luaL_fileresult = (_luaL_fileresult)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_fileresult");
#elif defined SYSTEM_POSIX
	static _luaL_fileresult luaL_fileresult = (_luaL_fileresult)dlsym(shared_lib,"luaL_fileresult");
#endif

typedef const char*(*_luaL_findtable)(lua_State* L,int idx,const char *fname, int szhint);
#if defined SYSTEM_WINDOWS
	static _luaL_findtable luaL_findtable = (_luaL_findtable)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_findtable");
#elif defined SYSTEM_POSIX
	static _luaL_findtable luaL_findtable = (_luaL_findtable)dlsym(shared_lib,"luaL_findtable");
#endif

typedef int(*_luaL_getmetafield)(lua_State* L,int obj, const char *e);
#if defined SYSTEM_WINDOWS
	static _luaL_getmetafield luaL_getmetafield = (_luaL_getmetafield)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_getmetafield");
#elif defined SYSTEM_POSIX
	static _luaL_getmetafield luaL_getmetafield = (_luaL_getmetafield)dlsym(shared_lib,"luaL_getmetafield");
#endif

typedef const char*(*_luaL_gsub)(lua_State* L,const char *s,const char *p,const char *r);
#if defined SYSTEM_WINDOWS
	static _luaL_gsub luaL_gsub = (_luaL_gsub)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_gsub");
#elif defined SYSTEM_POSIX
	static _luaL_gsub luaL_gsub = (_luaL_gsub)dlsym(shared_lib,"luaL_gsub");
#endif

typedef int(*_luaL_loadbuffer)(lua_State* L,const char *buff,size_t sz,const char *name);
#if defined SYSTEM_WINDOWS
	static _luaL_loadbuffer luaL_loadbuffer = (_luaL_loadbuffer)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_loadbuffer");
#elif defined SYSTEM_POSIX
	static _luaL_loadbuffer luaL_loadbuffer = (_luaL_loadbuffer)dlsym(shared_lib,"luaL_loadbuffer");
#endif

typedef int(*_luaL_loadbufferx)(lua_State* L,const char *buff,size_t sz,const char *name,const char *mode);
#if defined SYSTEM_WINDOWS
	static _luaL_loadbufferx luaL_loadbufferx = (_luaL_loadbufferx)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_loadbufferx");
#elif defined SYSTEM_POSIX
	static _luaL_loadbufferx luaL_loadbufferx = (_luaL_loadbufferx)dlsym(shared_lib,"luaL_loadbufferx");
#endif

typedef int(*_luaL_loadfile)(lua_State* L,const char *filename);
#if defined SYSTEM_WINDOWS
	static _luaL_loadfile luaL_loadfile = (_luaL_loadfile)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_loadfile");
#elif defined SYSTEM_POSIX
	static _luaL_loadfile luaL_loadfile = (_luaL_loadfile)dlsym(shared_lib,"luaL_loadfile");
#endif

typedef int(*_luaL_loadfilex)(lua_State* L,const char *filename,const char *mode);
#if defined SYSTEM_WINDOWS
	static _luaL_loadfilex luaL_loadfilex = (_luaL_loadfilex)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_loadfilex");
#elif defined SYSTEM_POSIX
	static _luaL_loadfilex luaL_loadfilex = (_luaL_loadfilex)dlsym(shared_lib,"luaL_loadfilex");
#endif

typedef int(*_luaL_loadstring)(lua_State* L,const char *s);
#if defined SYSTEM_WINDOWS
	static _luaL_loadstring luaL_loadstring = (_luaL_loadstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_loadstring");
#elif defined SYSTEM_POSIX
	static _luaL_loadstring luaL_loadstring = (_luaL_loadstring)dlsym(shared_lib,"luaL_loadstring");
#endif

typedef int(*_luaL_newmetatable)(lua_State* L,const char *tname);
#if defined SYSTEM_WINDOWS
	static _luaL_newmetatable luaL_newmetatable = (_luaL_newmetatable)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_newmetatable");
#elif defined SYSTEM_POSIX
	static _luaL_newmetatable luaL_newmetatable = (_luaL_newmetatable)dlsym(shared_lib,"luaL_newmetatable");
#endif

/*Incomplete
typedef int(*_luaL_newmetatable_type)(lua_State* L,);
#if defined SYSTEM_WINDOWS
	static _luaL_newmetatable_type luaL_newmetatable_type = (_luaL_newmetatable_type)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_newmetatable_type");
#elif defined SYSTEM_POSIX
	static _luaL_newmetatable_type luaL_newmetatable_type = (_luaL_newmetatable_type)dlsym(shared_lib,"luaL_newmetatable_type");
#endif
*/
typedef lua_State*(*_luaL_newstate)(lua_State* L,void *ud);
#if defined SYSTEM_WINDOWS
	static _luaL_newstate luaL_newstate = (_luaL_newstate)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_newstate");
#elif defined SYSTEM_POSIX
	static _luaL_newstate luaL_newstate = (_luaL_newstate)dlsym(shared_lib,"luaL_newstate");
#endif

typedef void(*_luaL_openlib)(lua_State* L,const char *libname,const luaL_Reg *l, int nup);
#if defined SYSTEM_WINDOWS
	static _luaL_openlib luaL_openlib = (_luaL_openlib)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_openlib");
#elif defined SYSTEM_POSIX
	static _luaL_openlib luaL_openlib = (_luaL_openlib)dlsym(shared_lib,"luaL_openlib");
#endif

typedef coid(*_luaL_openlibs)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaL_openlibs luaL_openlibs = (_luaL_openlibs)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_openlibs");
#elif defined SYSTEM_POSIX
	static _luaL_openlibs luaL_openlibs = (_luaL_openlibs)dlsym(shared_lib,"luaL_openlibs");
#endif

typedef lua_Integer(*_luaL_optinteger)(lua_State* L,int narg,lua_Integer d);
#if defined SYSTEM_WINDOWS
	static _luaL_optinteger luaL_optinteger = (_luaL_optinteger)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_optinteger");
#elif defined SYSTEM_POSIX
	static _luaL_optinteger luaL_optinteger = (_luaL_optinteger)dlsym(shared_lib,"luaL_optinteger");
#endif

typedef const char*(*_luaL_optlstring)(lua_State* L,int narg,const char *d,size_t *l);
#if defined SYSTEM_WINDOWS
	static _luaL_optlstring luaL_optlstring = (_luaL_optlstring)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_optlstring");
#elif defined SYSTEM_POSIX
	static _luaL_optlstring luaL_optlstring = (_luaL_optlstring)dlsym(shared_lib,"luaL_optlstring");
#endif

typedef lua_Number(*_luaL_optnumber)(lua_State* L,int narg, lua_Number d);
#if defined SYSTEM_WINDOWS
	static _luaL_optnumber luaL_optnumber = (_luaL_optnumber)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_optnumber");
#elif defined SYSTEM_POSIX
	static _luaL_optnumber luaL_optnumber = (_luaL_optnumber)dlsym(shared_lib,"luaL_optnumber");
#endif

typedef char*(*_luaL_prepbuffer)(luaL_Buffer *B);
#if defined SYSTEM_WINDOWS
	static _luaL_prepbuffer luaL_prepbuffer = (_luaL_prepbuffer)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_prepbuffer");
#elif defined SYSTEM_POSIX
	static _luaL_prepbuffer luaL_prepbuffer = (_luaL_prepbuffer)dlsym(shared_lib,"luaL_prepbuffer");
#endif

typedef void(*_luaL_pushresult)(luaL_Buffer *B);
#if defined SYSTEM_WINDOWS
	static _luaL_pushresult luaL_pushresult = (_luaL_pushresult)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_pushresult");
#elif defined SYSTEM_POSIX
	static _luaL_pushresult luaL_pushresult = (_luaL_pushresult)dlsym(shared_lib,"luaL_pushresult");
#endif

typedef int(*_luaL_ref)(lua_State* L,int t);
#if defined SYSTEM_WINDOWS
	static _luaL_ref luaL_ref = (_luaL_ref)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_ref");
#elif defined SYSTEM_POSIX
	static _luaL_ref luaL_ref = (_luaL_ref)dlsym(shared_lib,"luaL_ref");
#endif

typedef void(*_luaL_register)(lua_State* L,const char *libname,const luaL_Reg *l);
#if defined SYSTEM_WINDOWS
	static _luaL_register luaL_register = (_luaL_register)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_register");
#elif defined SYSTEM_POSIX
	static _luaL_register luaL_register = (_luaL_register)dlsym(shared_lib,"luaL_register");
#endif

typedef void(*_luaL_traceback)(lua_State *L, lua_State *L1,const char *msg, int level);
#if defined SYSTEM_WINDOWS
	static _luaL_traceback luaL_traceback = (_luaL_traceback)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_traceback");
#elif defined SYSTEM_POSIX
	static _luaL_traceback luaL_traceback = (_luaL_traceback)dlsym(shared_lib,"luaL_traceback");
#endif

typedef int(*_luaL_typerror)(lua_State* L,int narg, const char *tname);
#if defined SYSTEM_WINDOWS
	static _luaL_typerror luaL_typerror = (_luaL_typerror)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_typerror");
#elif defined SYSTEM_POSIX
	static _luaL_typerror luaL_typerror = (_luaL_typerror)dlsym(shared_lib,"luaL_typerror");
#endif

typedef void(*_luaL_unref)(lua_State* L,int t, int ref);
#if defined SYSTEM_WINDOWS
	static _luaL_unref luaL_unref = (_luaL_unref)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_unref");
#elif defined SYSTEM_POSIX
	static _luaL_unref luaL_unref = (_luaL_unref)dlsym(shared_lib,"luaL_unref");
#endif

typedef void(*_luaL_where)(lua_State* L,int lvl);
#if defined SYSTEM_WINDOWS
	static _luaL_where luaL_where = (_luaL_where)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaL_where");
#elif defined SYSTEM_POSIX
	static _luaL_where luaL_where = (_luaL_where)dlsym(shared_lib,"luaL_where");
#endif

typedef int(*_luaopen_base)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_base luaopen_base = (_luaopen_base)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_base");
#elif defined SYSTEM_POSIX
	static _luaopen_base luaopen_base = (_luaopen_base)dlsym(shared_lib,"luaopen_base");
#endif

typedef int(*_luaopen_bit)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_bit luaopen_bit = (_luaopen_bit)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_bit");
#elif defined SYSTEM_POSIX
	static _luaopen_bit luaopen_bit = (_luaopen_bit)dlsym(shared_lib,"luaopen_bit");
#endif

typedef int(*_luaopen_debug)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_debug luaopen_debug = (_luaopen_debug)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_debug");
#elif defined SYSTEM_POSIX
	static _luaopen_debug luaopen_debug = (_luaopen_debug)dlsym(shared_lib,"luaopen_debug");
#endif

typedef int(*_luaopen_jit)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_jit luaopen_jit = (_luaopen_jit)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_jit");
#elif defined SYSTEM_POSIX
	static _luaopen_jit luaopen_jit = (_luaopen_jit)dlsym(shared_lib,"luaopen_jit");
#endif

typedef int(*_luaopen_math)(lua_State* L,IntPtr L);
#if defined SYSTEM_WINDOWS
	static _luaopen_math luaopen_math = (_luaopen_math)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_math");
#elif defined SYSTEM_POSIX
	static _luaopen_math luaopen_math = (_luaopen_math)dlsym(shared_lib,"luaopen_math");
#endif

typedef int(*_luaopen_os)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_os luaopen_os = (_luaopen_os)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_os");
#elif defined SYSTEM_POSIX
	static _luaopen_os luaopen_os = (_luaopen_os)dlsym(shared_lib,"luaopen_os");
#endif

typedef int(*_luaopen_package)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_package luaopen_package = (_luaopen_package)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_package");
#elif defined SYSTEM_POSIX
	static _luaopen_package luaopen_package = (_luaopen_package)dlsym(shared_lib,"luaopen_package");
#endif

typedef int(*_luaopen_string)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_string luaopen_string = (_luaopen_string)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_string");
#elif defined SYSTEM_POSIX
	static _luaopen_string luaopen_string = (_luaopen_string)dlsym(shared_lib,"luaopen_string");
#endif

typedef int(*_luaopen_table)(lua_State* L);
#if defined SYSTEM_WINDOWS
	static _luaopen_table luaopen_table = (_luaopen_table)GetProcAddress(GetModuleHandleA("lua_shared.dll"),"luaopen_table");
#elif defined SYSTEM_POSIX
	static _luaopen_table luaopen_table = (_luaopen_table)dlsym(shared_lib,"luaopen_table");
#endif


#ifdef
	void Unload_Modules(){
		dlclose(shared_lib);
		return;
	}
#endif
