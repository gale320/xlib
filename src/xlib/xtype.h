/**

 */

 
#ifndef __XTYPE_H__
#define __XTYPE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdatomic.h>

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct _XNode XNode;

struct _XNode{
    void * value;
    XNode * prev;
    XNode * next;
};


#ifdef __cplusplus
    }
#endif

#endif

