#include<p18f4520.h>
void UART_init(void);
unsigned char receive (void);
void trans(unsigned char);
void main()
{
unsigned char id [13]="09001521665B";
unsigned char id1[13];
int i;
unsigned char x;
UART_init();
TRISCB=0x00;
while(1)
{
for(i=0;i<12;i++)
{
x=receive();
id1[i]=x;
trans(x);
}
if((id1[0]==id[0])&&(id1[1]==id[1])&&(id1[2]==id[2])&&(id1[3]==id[3])&&(id1[4]==id[4])&&
(id1[5]==id[5])&&(id1[6]==id[6])&&(id1[7]==id[7])&&(id1[8]==id[8])&&(id1[9]==id[9])&&
(id1[10]==id[10])&&(id1[11]==id[11]))
{
PORTB=0xff;
}
else
{
PORTB=0x00;
}
}
}
unsigned char receive(void)
{
while(PIRIbits.RCIF==0);
return RCREG;
}
void UART_init(void)
{
TRISC=0x80;
TXSTA=0x24;
RCSTA=0x90;
SPBRG=0x81;
}
void trans(unsigned char x)
{
TXREG=x;
while(TXSTAbits.TRMT==0);
}