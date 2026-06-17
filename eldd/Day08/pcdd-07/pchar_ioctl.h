#ifndef __PCHAR_IOCTL_H
#define __PCHAR_IOCTL_H

#include <linux/ioctl.h>

struct fifo_info
{
    short size;   // fifo capacity
    short length; // num of elems in fifo
    short avail;  // num of empty elems in fifo
};

#define FIFO_CLEAR _IO('x', 1)
#define FIFO_GET_INFO _IOR('x', 2, struct fifo_info)
#define FIFO_RESIZE _IOW('x', 3, int)

#endif
