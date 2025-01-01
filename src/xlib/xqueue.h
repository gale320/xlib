#ifndef __XQUEUE_H__
#define __XQUEUE_H__

#include "xtype.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _XQueue{
    XNode * header;
    XNode * tail;
    atomic_uint size;
};

typedef struct _XQueue XQueue;

bool xqueue_init(XQueue * queue);
bool xqueue_destory(XQueue * queue);
bool xqueue_push(XQueue * queue, void * x);
bool xqueue_pop(XQueue * queue, void **x);
bool xqueue_empty(XQueue * queue);
bool xqueue_front(XQueue * queue, void **x);
bool xqueue_back(XQueue * queue, void **x);
uint32_t xqueue_size(XQueue * queue);



#ifdef __cplusplus
}
#endif


#endif
