#include "Config.h"
#include "ZoCfg.h"
#include "Worker/Game.h"

#include <signal.h>

#ifdef __GNUC__
#ifndef _WIN32
#include <sys/resource.h>
#include <fcntl.h>
extern "C" __attribute__((constructor)) void __serverInit()
{
	struct rlimit rlsrc = {RLIM_INFINITY, RLIM_INFINITY};
	struct rlimit rlsrc2 = {131072, 262144};
	setrlimit(RLIMIT_CORE, &rlsrc);
	setrlimit(RLIMIT_NOFILE, &rlsrc2);
	int f = open("/proc/sys/kernel/core_uses_pid", O_WRONLY);
	if (f < 0)
		return;
	if (write(f, "1", 1) < 0)
	{
		printf("WARNING: Unable to enable core dump with pid!!\n");
	}
	close(f);
}
#endif
#endif

extern "C" void sigbreak(int sig)
{
	fprintf(stdout, "Caught signal: %d\n", sig);
	fflush(stdout);
	//Worker::game.stop();
}

inline void registerSignals()
{
#ifndef SIGBREAK
#define SIGBREAK 21
#endif
	signal(SIGABRT, &sigbreak);
	signal(SIGINT, &sigbreak);
	signal(SIGTERM, &sigbreak);
	signal(SIGBREAK, &sigbreak);
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		zocfg.load();
	}
	else
	{
		zocfg.load(argv[1]);
	}
	registerSignals();  // register signals

	Worker::game.start();
	Worker::game.join();
	//main thread start
	return 0;
}