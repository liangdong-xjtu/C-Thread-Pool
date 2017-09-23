#ifndef _MEMBARRIER_H
#define _MEMBARRIER_H

//#define EANBLE_BARRIER

#ifdef EANBLE_BARRIER

#if defined(__ia64) || defined(__itanium__) || defined(_M_IA64) || defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__)
	#define com_barrier() __asm__ __volatile__ ("" : : : "memory")
	#define com_dsb() {} __asm__ __volatile__ ("dsb sy" : : : "memory")
#else

	#define com_barrier() __asm__ __volatile__ ("" : : : "memory")
	#define com_dsb() {} __asm__ __volatile__ ("dsb" : : : "memory")
#endif

#else /* EANBLE_BARRIER */

	#define com_barrier() do { } while (0)
	#define com_dsb() {} do { } while (0)

#endif /* EANBLE_BARRIER */

#endif	/* _MEMBARRIER_H */
