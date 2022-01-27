#include "string.h"
#include "reg51.h"
//Dinh nghia mot so chan de dieu khien den LCD
#define LCD_DATA P2
sbit EN=P0^2;
sbit RS=P0^0;
sbit RW=P0^1;
sbit SPK = P3^7;	   

char uart_data;

unsigned int isPlay = 0;
unsigned char note_name[4];

code unsigned int note_table[]={
	0xf9,0x1e,		//C4
	0xf9,0xde,		//D4
	0xfa,0x89,		//E4
	0xfa,0xd8,		//F4
	0xfb,0x68,
	0xfb,0xe8,
	0xfc,0x5a,
	0xfc,0x8f,
	0xfc,0xef,
	0xfd,0x44,
	0xfd,0x6c,
	0xfd,0xb4,
	0xfd,0xf4,
	0xfe,0x2d,
	0xfe,0x47,
	0xfe,0x77,
	0xfe,0xa2,
	0xfe,0xb6,
	0xfe,0xda,
	0xfe,0xfa,
	0xff,0x16,		//A6
};	  
unsigned char note_index;


//Khai bao prototype cho cac ham
void Init_System();	
void Delay_ms(int interval);  
void LCD_init();
void Wait_For_LCD();
void LCD_Send_Command(unsigned char x);
void LCD_Write_One_Char(unsigned char c);
void LCD_Write_String(unsigned char *s);
void play_one_note(unsigned char c);
void delay(unsigned int time);
void play_intro_music();

void main()
{
	Init_System();
	play_intro_music();	
	while(1){	
		if (isPlay) {
			play_one_note(uart_data);
			LCD_init();	
			LCD_Write_String(note_name);
		}	
	}
}
void Init_System()
{
	//khoi tao timer0
	TMOD=0x01;				// Dat timer0 o che do 16 bit
	EA=1;					// Cho phep ngat toan cuc
	ET0=1;					// Cho phep ngat timer0
	TR0=0;					// Dat timer0 khong chay
	// Khoi tao interrupt
	SCON = 0x50; 			/* uart in mode 1 (8 bit), REN=1 */
  	TMOD = TMOD | 0x20 ; 	/* Timer 1 in mode 2 */
	TH1 = 0xFD; 			/* 9600 Bds at 11.0592MHz */
	TL1 = 0xFD; 			/* 9600 Bds at 11.0592MHz */
	ES = 1; 				/* Enable serial interrupt*/
	EA = 1; 				/* Enable global interrupt */
	TR1 = 1; 				/* Timer 1 run */
	//Thiet lap LCD o che do doc
	RW=1;	
}


void Delay_ms(int interval)
{
	int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<interval;j++);
	}
}
//Ham thuc hien gui mot lenh xuong LCD
void LCD_Send_Command(unsigned char x)
{
	LCD_DATA=x;
	RS=0; //Chon thanh ghi lenh
	RW=0; //De ghi du lieu
	EN=1;
	Delay_ms(1);
	EN=0;		
	Wait_For_LCD(); //Doi cho LCD san sang
	EN=1;		  
}
//Ham kiem tra va cho den khi LCD san sang
void Wait_For_LCD()
{
	Delay_ms(1);
}
void LCD_init()
{
	LCD_Send_Command(0x38); //Chon che do 8 bit, 2 hang cho LCD
	LCD_Send_Command(0x0E); //Bat hien thi, nhap nhay con tro	
	LCD_Send_Command(0x01); //Xoa man hinh	
	LCD_Send_Command(0x80); //Ve dau dong
	
}
//Ham de LCD hien thi mot ky tu
void LCD_Write_One_Char(unsigned char c)
{
	LCD_DATA=c; //Dua du lieu vao thanh ghi 
	RS=1; //Chon thanh ghi du lieu
	RW=0;
	EN=1;
	Delay_ms(1);	
	EN=0;
	Wait_For_LCD();	
	EN=1;
}
//Ham de LCD hien thi mot xau
void LCD_Write_String(unsigned char *s)
{
	unsigned char length;
	length=strlen(s); //Lay do dai xau
	while(length!=0)
	{
		LCD_Write_One_Char(*s); //Ghi ra LCD gia tri duoc tro boi con tro
		s++; //Tang con tro
		length--;	  		 
	}
}

//Ham xu ly ngat, doc va ghi du lieu len LCD
void serial_IT(void) interrupt 4
{
  if (RI == 1)
  { 
    RI = 0; 			/* prepare for next reception */
    uart_data = SBUF; 	/* Read receive data */	
    SBUF = uart_data; 	/* Send back same data on uart*/  
	isPlay = 1;		 
  }
  else {
    TI = 0; 			/* if emission occur */
	isPlay = 0;
	}
}
	 
void delay(unsigned int time)
{
	while(time--);
}

void play_one_note(unsigned char c){
	note_index=0;
	
	switch(c){
	   case 'q': 
	   		note_index = 0;
			strcpy(note_name,"C4");
			break;	 
	   case 'w': 
	   		note_index = 1;
			strcpy(note_name,"D4");
			break;
	   case 'e': 
	   		note_index = 2;	
			strcpy(note_name,"E4");
			break;
	   case 'r': 
	   		note_index = 3;
			strcpy(note_name,"F4");
			break;
	   case 't': 
	   		note_index = 4;
			strcpy(note_name,"G4");
			break;
	   case 'y': 
	   		note_index = 5;
			strcpy(note_name,"A4");
			break;
	   case 'u': 
	   		note_index = 6;
			strcpy(note_name,"B4");
			break;
		case 'a': 
	   		note_index = 7;
			strcpy(note_name,"C5");
			break;	 
	   case 's': 
	   		note_index = 8;
			strcpy(note_name,"D5");
			break;
	   case 'd': 
	   		note_index = 9;
			strcpy(note_name,"E5");
			break;
	   case 'f': 
	   		note_index = 10;
			strcpy(note_name,"F5");
			break;
	   case 'g': 
	   		note_index = 11;	
			strcpy(note_name,"G5");
			break;
	   case 'h': 
	   		note_index = 12;
			strcpy(note_name,"A5");
			break;
	   case 'j': 
	   		note_index = 13;
			strcpy(note_name,"B5");
			break;
		case 'z': 
	   		note_index = 14;
			strcpy(note_name,"C6");
			break;	 
	   case 'x': 
	   		note_index = 15;
			strcpy(note_name,"D6");
			break;
	   case 'c': 
	   		note_index = 16;
			strcpy(note_name,"E6");
			break;
	   case 'v': 
	   		note_index = 17;
			strcpy(note_name,"F6");
			break;
	   case 'b': 
	   		note_index = 18;	
			strcpy(note_name,"G6");
			break;
	   case 'n': 
	   		note_index = 19;
			strcpy(note_name,"A6");
			break;
	   case 'm': 
	   		note_index = 20;
			strcpy(note_name,"B6");
			break;
		default:  
	   		note_index = 0;
			strcpy(note_name,"C4");
			break;
			 
	}
	
			
	TH0=note_table[note_index*2];
	TL0=note_table[note_index*2+1];			
	TR0=1;
	delay(30000);
	TR0=0;
	SPK=1;	
}

void timer0() interrupt 1
{
	TH0=note_table[note_index*2];
	TL0=note_table[note_index*2+1];
	SPK=~SPK;
}

void play_intro_music(){
	// Bat doan nhac happy birthday 
	char intro[50] = "tt y t a u  tt y t s a  tt g d au y  dds a s a";	
	unsigned int i;

	for (i=0; i < strlen(intro); i++) {
		if (intro[i] == ' '){
			delay(15000);
			continue;
		}
		play_one_note(intro[i]);
		delay(10000);
	}
}