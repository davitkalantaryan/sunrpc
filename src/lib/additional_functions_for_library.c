

#include <netdb.h>
#include <stddef.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int ffsl(long int a_arg)
{
    long int nMask = 1;
    long int i=1;
    //const long int clnScanRegion = sizeof(long int)-1;
    //const long int clnScanRegion = sizeof(long int);

    for(;nMask;++i,nMask <<= 1){
        if(nMask&a_arg){
            return i;
        }
    }

    return 0;
}

int ffs2(int a_arg)
{
    int nMask = 1;
    int i=1;

    for(;nMask;++i,nMask <<= 1){
        if(nMask&a_arg){
            return i;
        }
    }

    return 0;
}

#if 1

extern int sys_nerr;
int sys_nerr = 1024;

int getdtablesize(void)
{
    return 1024;
}

int getprotobyname_r(const char *a_name,struct protoent *a_result_buf, char *a_buf,size_t a_buflen, struct protoent **a_pResult)
{
    static pthread_mutex_t sMutex = PTHREAD_MUTEX_INITIALIZER;

    int nReturn = -1;
    int i;
    size_t count;
    char* pcBufferNext = a_buf;
    char** pAlias;
    size_t unRemainingFromBuffer = a_buflen-1;
    size_t unStrLenPlus1, unSizeForCopy;
    struct protoent *result;

    *a_pResult = NULL;

    pthread_mutex_lock(&sMutex);
    result = getprotobyname(a_name);
    if(!result){
        goto returnPoint;
    }
    *a_pResult = a_result_buf;
    nReturn = 0;
    memcpy(a_result_buf,result,sizeof(struct protoent));

    for (count=0,pAlias = result->p_aliases; *pAlias; ++pAlias,++count);
    unStrLenPlus1 = count*sizeof(char*);
    if(a_buflen<unStrLenPlus1){
        a_result_buf->p_name = NULL;
        a_result_buf->p_aliases = NULL;
        goto returnPoint;
    }
    a_buf[unRemainingFromBuffer]=0;

    unSizeForCopy = unStrLenPlus1;  // here we are shure that we have enough space because of if(a_buflen<unStrLenPlus1){
    a_result_buf->p_aliases = (char**)((void*)pcBufferNext);
    pcBufferNext += unSizeForCopy;
    unRemainingFromBuffer -= unSizeForCopy;

    unStrLenPlus1 = strlen(result->p_name) + 1;
    unSizeForCopy = (unStrLenPlus1>unRemainingFromBuffer) ? unRemainingFromBuffer : unStrLenPlus1;
    memcpy(pcBufferNext,result->p_name,unSizeForCopy);
    a_result_buf->p_name = pcBufferNext;
    pcBufferNext += unSizeForCopy;
    unRemainingFromBuffer -= unSizeForCopy;

    for (i=0,pAlias = result->p_aliases; (*pAlias)&&unSizeForCopy; ++pAlias,++i){
        unStrLenPlus1 = strlen(*pAlias) + 1;
        unSizeForCopy = (unStrLenPlus1>unRemainingFromBuffer) ? unRemainingFromBuffer : unStrLenPlus1;
        memcpy(pcBufferNext,*pAlias,unSizeForCopy);
        a_result_buf->p_aliases[i] = pcBufferNext;
        pcBufferNext += unSizeForCopy;
        unRemainingFromBuffer -= unSizeForCopy;
    }

    *a_pResult = a_result_buf;
    nReturn = 0;
returnPoint:
    pthread_mutex_unlock(&sMutex);
    return nReturn;
}



#else   // #if 1


#include <inet/net-internal.h>
#include <assert.h>

#define HANDLE_NULL_EMORY(_memory)

int __libc_rpc_gethostbyname(const char* a_hostname, struct sockaddr_in* a_pSin)
{
    char vcBuffer[4096];
    struct hostent hbuf;
    struct hostent* result;
    int err;
    int rc = gethostbyname_r(a_hostname, &hbuf, vcBuffer, 4096, &result, &err);

    if((rc && (rc!=ERANGE))||(!result)){
        return rc;
    }

    a_pSin->sin_family = (__kernel_sa_family_t)result->h_addrtype;
    a_pSin->sin_port = 0;
    memset(a_pSin->sin_zero,0,sizeof(a_pSin->sin_zero));
    memcpy(&a_pSin->sin_addr,result->h_addr,(size_t)result->h_length);

    return 0;
}


int __getprotobyname_r(const char *a_name,struct protoent *a_result_buf, char *a_buf,size_t a_buflen, struct protoent **a_pResult)
{
    static pthread_mutex_t sMutex = PTHREAD_MUTEX_INITIALIZER;

    int nReturn = -1;
    int i;
    size_t count;
    char* pcBufferNext = a_buf;
    char** pAlias;
    size_t unRemainingFromBuffer = a_buflen-1;
    size_t unStrLenPlus1, unSizeForCopy;
    struct protoent *result;

    *a_pResult = NULL;

    pthread_mutex_lock(&sMutex);
    result = getprotobyname(a_name);
    if(!result){
        goto returnPoint;
    }
    *a_pResult = a_result_buf;
    nReturn = 0;
    memcpy(a_result_buf,result,sizeof(struct protoent));

    for (count=0,pAlias = result->p_aliases; *pAlias; ++pAlias,++count);
    unStrLenPlus1 = count*sizeof(char*);
    if(a_buflen<unStrLenPlus1){
        a_result_buf->p_name = NULL;
        a_result_buf->p_aliases = NULL;
        goto returnPoint;
    }
    a_buf[unRemainingFromBuffer]=0;

    unSizeForCopy = unStrLenPlus1;  // here we are shure that we have enough space because of if(a_buflen<unStrLenPlus1){
    a_result_buf->p_aliases = (char**)((void*)pcBufferNext);
    pcBufferNext += unSizeForCopy;
    unRemainingFromBuffer -= unSizeForCopy;

    unStrLenPlus1 = strlen(result->p_name) + 1;
    unSizeForCopy = (unStrLenPlus1>unRemainingFromBuffer) ? unRemainingFromBuffer : unStrLenPlus1;
    memcpy(pcBufferNext,result->p_name,unSizeForCopy);
    a_result_buf->p_name = pcBufferNext;
    pcBufferNext += unSizeForCopy;
    unRemainingFromBuffer -= unSizeForCopy;

    for (i=0,pAlias = result->p_aliases; (*pAlias)&&unSizeForCopy; ++pAlias,++i){
        unStrLenPlus1 = strlen(*pAlias) + 1;
        unSizeForCopy = (unStrLenPlus1>unRemainingFromBuffer) ? unRemainingFromBuffer : unStrLenPlus1;
        memcpy(pcBufferNext,*pAlias,unSizeForCopy);
        a_result_buf->p_aliases[i] = pcBufferNext;
        pcBufferNext += unSizeForCopy;
        unRemainingFromBuffer -= unSizeForCopy;
    }

    *a_pResult = a_result_buf;
    nReturn = 0;
returnPoint:
    pthread_mutex_unlock(&sMutex);
    return nReturn;
}

static pthread_key_t   s_rpc_thread_key = 0;
struct SKeyEntryListItem{
    struct SKeyEntryListItem *prev, *next;
    char* name;
    void** pValue;
    size_t nameLenPlus1;
};

struct SFirstLastItems
{
    struct SKeyEntryListItem *first, *last;
};

static void rpc_thread_key_deleter(void* a_pValue)
{
    free(a_pValue);
}

static void make_key(void)
{
    (void) pthread_key_create(&s_rpc_thread_key, &rpc_thread_key_deleter);
}


void** __rpc_thread_specific_variable(const char* a_name)
{
    //static pthread_rwlock_t sMutexRw = PTHREAD_RWLOCK_INITIALIZER;
    //static pthread_mutex_t sMutex = PTHREAD_MUTEX_INITIALIZER;
    static pthread_once_t key_once = PTHREAD_ONCE_INIT;

    struct SFirstLastItems* pFirstLast;
    struct SKeyEntryListItem *pItem;
    const size_t cunNameLenPlus1 = strlen(a_name) + 1;

    (void) pthread_once(&key_once, make_key);

    pFirstLast = (struct SFirstLastItems*)pthread_getspecific(s_rpc_thread_key);

    if(!pFirstLast){
        pFirstLast = (struct SFirstLastItems*)malloc(sizeof(struct SFirstLastItems));
        HANDLE_NULL_EMORY(pFirstLast);
        pFirstLast->first = pFirstLast->last = NULL;
    }

    pItem = pFirstLast->first;

    while(pItem){
        if((cunNameLenPlus1==pItem->nameLenPlus1)&&(!memcmp(pItem->name,a_name,cunNameLenPlus1))){
            return pItem->pValue;
        }
    }

    pItem = (struct SKeyEntryListItem*)calloc(1,sizeof(struct SKeyEntryListItem));
    HANDLE_NULL_EMORY(pItem);
    pItem->name = (char*)malloc(cunNameLenPlus1);
    HANDLE_NULL_EMORY(pItem->name);
    pItem->pValue = (void**)calloc(1,sizeof(void*));
    HANDLE_NULL_EMORY(pItem->pValue);
    *(pItem->pValue) = NULL;
    pItem->prev = pFirstLast->last;
    if(pFirstLast->first){
        pFirstLast->last->next = pItem;
    }
    else{
        pFirstLast->first=pItem;
    }
    pFirstLast->last=pItem;

    return pItem->pValue;
}

struct deadline_current_time __deadline_current_time (void)
{
  struct deadline_current_time result;
  if (clock_gettime (CLOCK_MONOTONIC, &result.current) != 0)
    {
      struct timeval current_tv;
      if (__gettimeofday (&current_tv, NULL) == 0)
        //__libc_fatal ("Fatal error: gettimeofday system call failed\n");
        result.current.tv_sec = current_tv.tv_sec;
        result.current.tv_nsec = current_tv.tv_usec * 1000;
    }
  //assert (result.current.tv_sec >= 0);
  return result;
}


static inline struct deadline
infinite_deadline (void)
{
  return (struct deadline) { { -1, -1 } };
}

struct deadline __deadline_from_timeval (struct deadline_current_time current,struct timeval tv)
{
  assert (__is_timeval_valid_timeout (tv));
  /* Compute second-based deadline.  Perform the addition in
     uintmax_t, which is unsigned, to simply overflow detection.  */
  uintmax_t sec = current.current.tv_sec;
  sec += tv.tv_sec;
  if (sec < (uintmax_t) tv.tv_sec)
    return infinite_deadline ();
  /* Compute nanosecond deadline.  */
  int nsec = current.current.tv_nsec + tv.tv_usec * 1000;
  if (nsec >= 1000 * 1000 * 1000)
    {
      /* Carry nanosecond overflow to seconds.  */
      nsec -= 1000 * 1000 * 1000;
      if (sec + 1 < sec)
        return infinite_deadline ();
      ++sec;
    }
  /* This uses a GCC extension, otherwise these casts for detecting
     overflow would not be defined.  */
  if ((time_t) sec < 0 || sec != (uintmax_t) (time_t) sec)
    return infinite_deadline ();
  return (struct deadline) { { sec, nsec } };
}


int __deadline_to_ms (struct deadline_current_time current,
                  struct deadline deadline)
{
  if (__deadline_is_infinite (deadline))
    return INT_MAX;
  if (current.current.tv_sec > deadline.absolute.tv_sec
      || (current.current.tv_sec == deadline.absolute.tv_sec
          && current.current.tv_nsec >= deadline.absolute.tv_nsec))
    return 0;
  time_t sec = deadline.absolute.tv_sec - current.current.tv_sec;
  if (sec >= INT_MAX)
    /* This value will overflow below.  */
    return INT_MAX;
  int nsec = deadline.absolute.tv_nsec - current.current.tv_nsec;
  if (nsec < 0)
    {
      /* Borrow from the seconds field.  */
      assert (sec > 0);
      --sec;
      nsec += 1000 * 1000 * 1000;
    }
  /* Prepare for rounding up to milliseconds.  */
  nsec += 999999;
  if (nsec > 1000 * 1000 * 1000)
    {
      assert (sec < INT_MAX);
      ++sec;
      nsec -= 1000 * 1000 * 1000;
    }
  unsigned int msec = nsec / (1000 * 1000);
  if (sec > INT_MAX / 1000)
    return INT_MAX;
  msec += sec * 1000;
  if (msec > INT_MAX)
    return INT_MAX;
  return msec;
}

#endif   // #if 1
