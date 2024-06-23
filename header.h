typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;
typedef signed char s8;
typedef unsigned short int u16;

extern void delay_ms(unsigned int ms);
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *s);
extern void uart0_rx_string(char *a,int n);
extern void uart0_reverse(char *s);
extern void uart0_tx_int(int num);
extern void uart0_tx_float(float num);




void adc_init(void);
u32 adc_read(int);
void adc_uart_tx_int(s32);



void spi0_init(void);
unsigned char spi0(unsigned char);
unsigned short int mcp3204_adc_read(unsigned int);

void i2c_init(void);
void i2c_byte_write_frame(u8, u8, u8);
u8 i2c_byte_read_frame(u8, u8);  