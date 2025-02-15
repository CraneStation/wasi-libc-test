#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/resource.h>
#include "test.h"

int t_memfill()
{
	int r = 0;
#ifdef __wasilibc_unmodified_upstream // Disable this OOM test as it takes too long to run in practice
	/* alloc mmap space with PROT_NONE */
	if (t_vmfill(0,0,0) < 0) {
		t_error("vmfill failed: %s\n", strerror(errno));
		r = -1;
	}
	/* limit brk space */
	if (t_setrlim(RLIMIT_DATA, 0) < 0)
		r = -1;
	if (!r)
		/* use up libc reserves if any */
		while (malloc(1));
#else
        abort();
#endif
	return r;
}
