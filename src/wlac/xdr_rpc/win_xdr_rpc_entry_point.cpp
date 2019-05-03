
#include <first_includes/common_definations_wul.h>
#include <sys/socket.h>

#ifdef __USING_WRPC_SOURCES__

class winrpc_initer
{
public:
	winrpc_initer()
	{
		if (!initialize_windows_socket_library())
		{
			throw "problem to init socket lib.";
		}
	}

	~winrpc_initer()
	{
		WSACleanup();
	}
};
static winrpc_initer s_winrpc_initer;

#else

__BEGIN_DECLS

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		return initialize_windows_socket_library();
	case DLL_PROCESS_DETACH:
		WSACleanup();
		break;
	default:
		break;
	}

	return TRUE;
}

__END_DECLS

#endif 
