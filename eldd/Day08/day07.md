### ioctl() examples

#### LCD device

1. LCD_CLEAR -- `_IO()` -- No 3rd param needed
2. LCD_START_SCROLL -- `_IO()` -- No 3rd param needed
3. LCD_STOP_SCROLL -- `_IO()` -- No 3rd param needed
4. LCD_SET_SCROLL_DELAY -- `_IOW()` -- 3rd param = delay
5. LCD_SET_LINE -- `_IOW()` -- 3rd param = line num

#### UART device

1. UART_ENABLE -- `_IO()` -- No 3rd param needed
2. UART_DISBALE -- `_IO()` -- No 3rd param needed
3. UART_SET_BAUDRATE -- `_IOW()` -- 3rd param = baud rate
4. UART_GET_BAUDRATE -- `_IOR()` -- 3rd param = baud rate

#### Pseudo char device -- with kfifo

1. FIFO_CLEAR -- `_IO()` -- No 3rd param needed
   - `#define FIFO_CLEAR _IO('x', 1)`
2. FIFO_GET_INFO -- `_IOR()` -- 3rd param - `struct fifo_info*`
   - short size, len, avail;
   - `#define FIFO_GET_INFO _IOR('x', 2, struct fifo_info)`
3. FIFO_RESIZE -- `_IOW()` -- 3rd param - new fifo size (int)
   - `#define FIFO_RESIZE _IOW('x', 3, int)`

#### Pseudo char device -- Multiple Device Instances

```sh
> sudo ./pchar_wr_test.out /dev/pchar0 "ABCD"

> sudo ./pchar_wr_test.out /dev/pchar1 "Hello"

> sudo ./pchar_wr_test.out /dev/pchar2 "XYZ"
```

- Each open() call from user space for different device files (pchar0, pchar1, pchar2), will call the same device operation i.e. pchar_open().
- Each write() call from user space for different device files (pchar0, pchar1, pchar2), will call the same device operation i.e. pchar_write().
- Each close() call from user space for different device files (pchar0, pchar1, pchar2), will call the same device operation i.e. pchar_close().

```sh
> sudo ./pchar_rd_test.out /dev/pchar0

> sudo ./pchar_rd_test.out /dev/pchar1

> sudo ./pchar_rd_test.out /dev/pchar2
```
