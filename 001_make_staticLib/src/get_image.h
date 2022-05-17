#ifndef __GET_IMAGE_H__
#define __GET_IMAGE_H__

/* Std Libs */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdint.h"

/* Error Libs*/
#include <errno.h>

/* Linux Libs */

#include <fcntl.h>
#include <unistd.h> // For close

/* V4L2 Libs*/
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/videodev2.h>

/* Output buffer format defines*/
#define UINT_8 1
#define UINT_16 2
#define UINT_32 3
#define FLOAT_32 4

/* V4l2 defines*/
/* You Need to modify the parameter */
#define VIDEO_DEVICE "/dev/video0"
#define SENSOR_COLORFORMAT V4L2_PIX_FMT_SRGGB12 // 12
#define BIT_DEPTH 12
// Use bit_depth to decide the size of image_size
// #define BufferType UINT_8
#define BUFFER_COUNT 5

#ifdef __cplusplus
extern "C"
{
#endif
    // Extern variable for resizing image
    extern int IMAGE_WIDTH;
    extern int IMAGE_HEIGHT;
    extern int RESIZE_WIDTH;
    extern int RESIZE_HEIGHT;
    extern int RESIZE_IMAGE_SIZE;
    extern int ALIGN_BYTES;
    // uint8_t *video_buffer_ptr[BUFFER_COUNT];

    /* Return cam_fd or -1 for error */
    int cam_init(int IMAGE_WIDTH, int IMAGE_HEIGHT);

    /* Convert Data Byte Order */
    void cvt_ByteOrder(uint8_t *new_file, uint8_t *raw_file, int raw_buffer_size, int pixel_bit);
    //void cvt_ByteOrder_float(void *new_file, uint8_t *raw_file, int image_size);

    /* Return 0 for success, -1 for error */
    /* Since all fmt are doing the same job:
       Passing into function --> cvt byte order --> return
       And cvt byte order is independent with buffer fmt,
       We decide to remove fmt to make the code cleaner.
     */

    int cam_get_image_ext_fmt(void *out_buffer, int out_buffer_size, int cam_fd/*, int fmt*/, int raw_bit);

    /* Close camera before leaving */
    int cam_close(int cam_fd);

    /* reset stream and format to clear buf */
    int change_raw_fmt(int pixel_bit, int *cam_fd);

    void init_log();
    void write_log(char *log_msg);

#ifdef __cplusplus
}
#endif

#endif
