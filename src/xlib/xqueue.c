#include <stdatomic.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "xqueue.h"

bool xqueue_init(XQueue * queue)
{
    bool ret = false;
    assert(queue);
    queue->header = NULL;
    queue->tail = NULL;
    atomic_init(&queue->size, 0);

    ret = true;
    return ret;
}

bool xqueue_destory(XQueue * queue)
{
    bool ret = false;
    assert(queue);
    XNode * node = queue->header;
    while(node)
    {
        XNode * next = node->next;
        free(node);
        node = next;
    }
    atomic_store(&queue->size, 0);
    ret = true;

    return ret;
}

bool xqueue_push(XQueue * queue, void * x)
{
    bool ret = false;
    assert(queue);
    XNode * node = (XNode *)malloc(sizeof(XNode));
    if(node == NULL)
    {
        perror("failed malloc");
        return ret;
    }

    node->value = x;
    node->next = NULL;

    if(queue->header == NULL)
    {
        queue->header = node;
        queue->tail = node;
    }
    else {
        queue->tail->next = node;
        queue->tail = queue->tail->next;
    }
    atomic_fetch_add(&queue->size, 1);
    return ret;
}

bool xqueue_pop(XQueue * queue, void **x)
{
    bool ret = false;
    assert(queue);
    if(queue->header == NULL)
    {
        return ret;
    }

    assert(queue->header);
    XNode * node = queue->header;
    *x = node->value;
    if(queue->header->next == NULL)
    {
        queue->header = NULL;
        queue->tail = NULL;
    }
    else {
        queue->header = queue->header->next;
    }
    free(node);
    atomic_fetch_sub(&queue->size, 1);
    ret = true;

    return ret;
}

bool xqueue_empty(XQueue * queue)
{
    bool ret = false;
    assert(queue);

    if(atomic_load(&queue->size) == 0)
    {
        ret = 0;
    }
    return ret;
}

bool xqueue_front(XQueue * queue, void **x)
{
    bool ret = false;
    assert(queue);
    assert(queue->header);
    *x = queue->header->value;
    ret = true;
    return ret;
}

bool xqueue_back(XQueue * queue, void **x)
{
    bool ret = false;
    assert(queue);
    assert(queue->tail);
    *x = queue->tail->value;

    ret = true;
    return ret;
}

uint32_t xqueue_size(XQueue * queue)
{
    assert(queue);
    return atomic_load(&queue->size);
}