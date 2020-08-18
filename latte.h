#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct{
    // ichigolatte
    volatile int32_t* g_env;
    volatile uint64_t* g_msec;
    size_t  (*mem_check)();
    void*   (*mem_alloc)(size_t size);
    void    (*mem_free)(void* mem);
    int  (*timer_set)(size_t usec, void (*func)());
    uint32_t (*rand_get)();
    int32_t (*sin8)(int32_t d);
    int32_t (*div)(int32_t n, int32_t d);
    int32_t (*mod)(int32_t n, int32_t d);
    ssize_t (*read)(int fd, void *buf, size_t count);
    ssize_t (*write)(int fd, const void *buf, size_t count);
    int         (*flash_erase)(uint8_t num);
    int         (*flash_save)(uint8_t num, const void* buf, size_t size);
    const char* (*flash_load)(uint8_t num);
    void    (*uart_bps)(uint32_t bps);
    void    (*uart_send)(const uint8_t* buf, size_t len);
    int32_t (*uart_read)();
    int (*i2c)(uint8_t wbf[], size_t nwb, uint8_t rbf[], size_t nrb);
    int     (*io_led)(int nf);
    int     (*io_btn)();
    int     (*io_in)(int n);
    int     (*io_ana)(int n);
    void    (*io_out)(int n);
    void    (*io_pwm)(int n, uint32_t d);
    void    (*io_pwmt)(uint32_t t);
    void    (*io_beep)(uint32_t hz, uint32_t msec);
    void  (*sleep)(int msec, int deep);
    char* (*line)(const char* last, size_t len);
    void  (*reset)();
    void (*ntsc_onoff)(int n);

    // screen
    const uint8_t (*g_aFont)[8];
    unsigned char* g_aScreen;
    uint8_t* g_nCursorX;
    uint8_t* g_nCursorY;
    unsigned char* (*screen_buf)(uint8_t x, uint8_t y);
    void (*screen_regulize)();
    void (*screen_clear)();
    void (*screen_scroll_l)();
    void (*screen_scroll_r)();
    void (*screen_scroll_u)();
    void (*screen_scroll_d)();
    void (*screen_putc)(unsigned char c);
    void (*screen_puts)(const char* s);
    
    // keyboard
    int (*keyboard_enqKeyBuf)(uint8_t k);
    uint8_t (*keyboard_deqKeyBuf)();

    // library - stdio.c
    int (*atoi)(const char* s);
    signed int (*printf)(const char *pFormat, ...);
    int (*snprintf)(char *pString, size_t length, const char *pFormat, ...);

    // library - string.c
    void* (*memcpy)(void* dst, const void* src, size_t n);
    void* (*memset)(void* b, int c, size_t len);
    char* (*strncpy)(char* dst, const char* src, size_t len);
    int (*strncmp)(const char* s1, const char* s2, size_t n);
    size_t (*strlen)(const char* s);
} API;

extern const API latte;


