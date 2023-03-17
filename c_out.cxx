#define __BARN_FUNCTION__
#define __BARN_GLOBAL_VARIABLE__
#define __use__(x) {x;}
__BARN_FUNCTION__ extern "C" void vga_putchar(char c, int x_pos, int y_pos);

__BARN_FUNCTION__ extern "C" int strlen(char* str);

__BARN_FUNCTION__ void barn_print(char* cs) {
		int string_length = strlen(cs);
	int start_pos_x = 0;
	int start_pos_y = 0;
	for (int i = 0;i<string_length;i++) {
/* __code__ ./kernel/entry.ba */
vga_putchar(cs[i], start_pos_x, start_pos_y);
/* __code__ end */
	start_pos_x++;
}
__use__(string_length);
__use__(start_pos_y);
}

/* __code__ ./kernel/entry.ba */
extern "C"
/* __code__ end */
__BARN_FUNCTION__ void barn_kernel_entry() {
barn_print("Barn");
}

