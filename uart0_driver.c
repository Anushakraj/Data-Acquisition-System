#include<lpc21xx.h>
#include "header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)
void uart0_init(u32 baud)
{
int a[]={15,60,30,0,15};
u32 pclk=a[VPBDIV]*1000000;
u32 result=pclk/(16*baud);
PINSEL0|=0x05;
U0LCR=0x83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}
void uart0_tx(u8 data)
{
U0THR=data;
	while(THRE==0);
}
u8 uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}
void uart0_tx_string(char *s)
{
while(*s)
{
uart0_tx(*s);
s++;
}
}
void uart0_rx_string(char *a,int n)
{
int i;
for(i=0;i<n;i++)
{
a[i]=uart0_rx();
if(a[i]=='\r')
break;
}
a[i]='\0';
}
void uart0_reverse(char *s)
{
char t;
int i,j,len;
for(len=0;s[len];len++);
for(i=0,j=len-1;i<j;i++,j--)
{
t=s[i];
s[i]=s[j];
s[j]=t;
}
//uart0_tx_string(char *s);
}
void uart0_tx_int(int num)
{
int a[10],i;
if(num==0)
{
uart0_tx('0');
if(num <0)
uart0_tx('-');
num=-num;
}
i=0;
while(num)
{
a[i]=num%10;
num=num/10;
i++;
}
for(--i;i>=0;i--)
uart0_tx(a[i]+48);
}
void uart0_tx_float (float num){
	int i;
	i= num;
	uart0_tx_int(i);
	uart0_tx('.');
	i = (num-i)*10;
	uart0_tx(i+48);
	
	
	
}


