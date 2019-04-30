
#ifndef SUNRPC_ADDITIONAL_INET_NET_INTERNAL_H
#define SUNRPC_ADDITIONAL_INET_NET_INTERNAL_H

#ifndef CINTERFACE
#define CINTERFACE
#endif

#include <time.h>



#ifdef __cplusplus
extern "C"{
#endif

#define SO_EE_ORIGIN_NONE    0
#define SO_EE_ORIGIN_LOCAL   1
#define SO_EE_ORIGIN_ICMP    2
#define SO_EE_ORIGIN_ICMP6   3

struct sock_extended_err {
    uint32_t ee_errno;   /* error number */
    uint8_t  ee_origin;  /* where the error originated */
    uint8_t  ee_type;    /* type */
    uint8_t  ee_code;    /* code */
    uint8_t  ee_pad;
    uint32_t ee_info;    /* additional information */
    uint32_t ee_data;    /* other data */
    /* More data may follow */
};

struct deadline_current_time
{
  struct timespec current;
};

struct deadline
{
  struct timespec absolute;
};

struct deadline_current_time __deadline_current_time (void) attribute_hidden;
struct deadline __deadline_from_timeval (struct deadline_current_time,struct timeval tv) attribute_hidden;
int __deadline_to_ms (struct deadline_current_time, struct deadline) attribute_hidden;


static inline bool_t
__deadline_is_infinite (struct deadline deadline)
{
  return deadline.absolute.tv_nsec < 0;
}

static inline struct deadline
__deadline_first (struct deadline left, struct deadline right)
{
  if (__deadline_is_infinite (right)
      || left.absolute.tv_sec < right.absolute.tv_sec
      || (left.absolute.tv_sec == right.absolute.tv_sec
          && left.absolute.tv_nsec < right.absolute.tv_nsec))
    return left;
  else
    return right;
}

static inline bool_t
__is_timeval_valid_timeout (struct timeval tv)
{
  return tv.tv_sec >= 0 && tv.tv_usec >= 0 && tv.tv_usec < 1000 * 1000;
}

static inline bool_t
__deadline_elapsed (struct deadline_current_time current,
                    struct deadline deadline)
{
  return !__deadline_is_infinite (deadline)
    && (current.current.tv_sec > deadline.absolute.tv_sec
        || (current.current.tv_sec == deadline.absolute.tv_sec
            && current.current.tv_nsec >= deadline.absolute.tv_nsec));
}



#ifdef __cplusplus
}
#endif


#endif  // #ifndef SUNRPC_ADDITIONAL_INET_NET_INTERNAL_H
