#define VIDEO_COLUMNS   80
#define VIDEO_LINES     24
#define VIDEO_ATTRIBUTE 7
#define VIDEO_ADDRESS   0xB8000

unsigned char* video_memory = (unsigned char*)VIDEO_ADDRESS;

void vga_putchar(char c, int x_pos, int y_pos) 
{
    *(video_memory + (x_pos + y_pos * VIDEO_COLUMNS) * 2)     = c & 0xFF;
    *(video_memory + (x_pos + y_pos * VIDEO_COLUMNS) * 2 + 1) = VIDEO_ATTRIBUTE;
}