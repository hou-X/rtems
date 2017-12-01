/*
 *  COPYRIGHT (c) 1989-2015
 *  On-Line Applications Research Corporation (OAR).
 */

#include <stdlib.h>

#include <rtems/test.h>
#include <rtems/score/threadimpl.h>

/*
 * This is the entry point automatically generated by GNAT.
 */
extern int gnat_main ( int argc, char **argv, char **envp );

static void *POSIX_Init(
  void *argument
)
{
  (void) gnat_main ( 0, 0, 0 );

  exit( 0 );
}

/*
 *  Prototypes for various test support routines. Since these are bound to
 *  from Ada, there are no external .h files even though they must be public.
 */
void ada_test_begin(void);
void ada_test_end(void);
uint32_t milliseconds_per_tick(void);
uint32_t ticks_per_second(void);
uint32_t work_space_size(void);
uint32_t is_configured_multiprocessing(void);
uint32_t get_node(void);
rtems_id tcb_to_id(Thread_Control *tcb);

/*
 *  By putting this in brackets rather than quotes, we get the search
 *  path and can get this file from ".." in the mptests.
 */
#define CONFIGURE_INIT
#define CONFIGURE_GNAT_RTEMS
#define CONFIGURE_MEMORY_OVERHEAD  (256)

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_DISABLE_SMP_CONFIGURATION

#include <config.h>

const char rtems_test_name[] = ADA_TEST_NAME;

void ada_test_begin(void)
{
  rtems_test_begin(rtems_test_name, RTEMS_TEST_STATE_PASS);
}

void ada_test_end(void)
{
  rtems_test_end(rtems_test_name);
}

rtems_id tcb_to_id(
  Thread_Control *tcb
)
{
  return tcb->Object.id; /* Only for sp04 */
}

uint32_t milliseconds_per_tick(void)
{
  return CONFIGURE_MICROSECONDS_PER_TICK / 1000;
}

uint32_t ticks_per_second(void)
{
  return rtems_clock_get_ticks_per_second();
}

uint32_t work_space_size(void)
{
  return CONFIGURE_EXECUTIVE_RAM_SIZE;
}

uint32_t is_configured_multiprocessing(void)
{
#if defined(RTEMS_MULTIPROCESSING)
  return 1;
#else
  return 0;
#endif
}

uint32_t get_node(void)
{
  /* XXX HACK -- use public API */
  return _Objects_Local_node;
}

