#include <SPI.h>

#define register_Digit(x) (0x1+(x))  //address D15-D8 HEX CODE
#define register_DecodeMode 0x09
#define register_intensity 0x0A
#define register_Scanlimit 0x0B
#define register_Shutdown 0x0C
#define register_Displaytest 0x0F
#define CS 0x0A
#define MOSI 0x0B
#define CLK 0x0D

void senddata(uint8_t address, uint8_t data){  //Serial-data(16bit)
digitalWrite(CS, LOW);
SPI.transfer(address);//D15-D8  //SPI.transfer(val)
SPI.transfer(data);//D7-D0
digitalWrite(CS, HIGH);
}
void gost(){
  Serial.begin(57600);//debug
  pinMode(CS, OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV2);//88
  SPI.setDataMode(SPI_MODE0);
  senddata(register_Shutdown, 0x00);
  senddata(register_DecodeMode, 0x00);
  senddata(register_intensity, 0x01);
  senddata(register_Scanlimit, 0x07);
  senddata(register_Displaytest, 0x00);
  senddata(register_Shutdown, 0x01);
}
const byte c[]={0,0,0,0,0,0,0,0};
const byte tri[]={0x80,0xC0,0xA0,0x90,0x88,0x84,0x82,0xFF};

const byte PIC[5][9]={
  {//0
  B11000111,
  B10001001,
  B00001001,
  B00001110,
  B01111110,
  B10011001,
  B10011001,
  B11100111},
  {//1
  B00011000,
  B00100100,
  B01000010,
  B10011001,
  B10011001,
  B01000010,
  B00100100,
  B00011000},
  {//2
  B11111000,
  B11110000,
  B11110000,
  B11111000,
  B10011100,
  B00001110,
  B00000111,
  B00000010},
  {//3
  B11000011,
  B10001001,
  B00011000,
  B01111000,
  0,
  B10000011,
  B11000011},
  {//4
  0376,
  B10000000,
  B10100000,
  B10010010,
  B10001011,
  B10000111,
  B10011111,
  B00001111
  }
};
const byte Char[27][9]={
 /*
  {//
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000}, */
  {//A
  B00111100,
  B01111110,
  B01100110,
  B01100110,
  B01111110,
  B01111110,
  B01100110,
  B01100110},

  {//B
  B01111100,
  B01100110,
  B01100110,
  B01111110,
  B01111110,
  B01100110,
  B01100110,
  B01111100},

  {//C
  B00011100,
  B00111110,
  B01100110,
  B01100000,
  B01100000,
  B01100110,
  B00111110,
  B00011100},

  {//D
  B01111100,
  B01111110,
  B01100111,
  B01100011,
  B01100011,
  B01100111,
  B01111110,
  B01111100},

  {//E
  B01111110,
  B01111110,
  B01100000,
  B01111110,
  B01111110,
  B01100000,
  B01111110,
  B01111110},

  {//F
  B01111110,
  B01111110,
  B01100000,
  B01111100,
  B01111100,
  B01100000,
  B01100000,
  B01100000},

  {//G
  B00011100,
  B00111110,
  B01100110,
  B01100000,
  B01100000,
  B01100111,
  B00111111,
  B00011101},


  {//H
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01111110,
  B01100110,
  B01100110,
  B01100110},

  {//I
  B00111100,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100,
  B00111100},

  {//J
  B00011110,
  B00011110,
  B00001100,
  B00001100,
  B00001100,
  B01101100,
  B01111100,
  B00111000},

  {//K
  B01100011,
  B01100110,
  B01101100,
  B01111000,
  B01111000,
  B01101100,
  B01100110,
  B01100011},

  {//L
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00110000,
  B00111110,
  B00111110},

  {//M
  B01111110,
  0377,
  B11011011,
  B11011011,
  B11011011,
  B11011011,
  B11011011,
  B11011011},

  {//N
  
  B11000011,
  B11100011,
  B11110011,
  B11011011,
  B11001111,
  B11000111,
  B11000011,
  B11000001},

  {//O
  B00111100,
  B01111110,
  B11100111,
  B11000011,
  B11000011,
  B11100111,
  B01111110,
  B00111100},

  {//P
  B01111100,
  B01111110,
  B01100011,
  B01100011,
  B01111110,
  B01111100,
  B01100000,
  B01100000},

  {//Q
  B00111100,
  B01111110,
  B11100111,
  B11000011,
  B11001011,
  B11100111,
  B01111110,
  B00111101},

  {//R
  B01111100,
  B01111110,
  B01100110,
  B01100110,
  B01111100,
  B01111000,
  B01101100,
  B01100110},

  
  {//S
  B00111100,
  B01100110,
  B01110010,
  B00111000,
  B00011100,
  B01001110,
  B01100110,
  B00111100},

  {//T
  B01111110,
  B01111110,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000},

  {//U
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B00111100},

  {//V
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B01100110,
  B00111100,
  B00011000},

  {//W
  B11000011,
  B11000011,
  B11000011,
  B11011011,
  B11011011,
  B11011011,
  B11111111,
  B0111110},

  {//X
  B01000010,
  B01100110,
  B00111100,
  B00011000,
  B00011000,
  B00111100,
  B01100110,
  B01000010},

  {//Y
  B01100110,
  B01100110,
  B01111110,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000},

  {//Z
  B01111110,
  B01111110,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111110,
  B01111110}
};

const byte NUM[][9]={
  {//0
    B00111100,
    B01111110,
    B01100110,
    B01100110,
    B01100110,
    B01100110,
    B01111110,
    B00111100},
   {//1
    B00011000,
    B00111000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00111100,
    B00111100},
   {//2
    B00111100,
    B01100110,
    B01000110,
    B00001100,
    B00011000,
    B00110000,
    B01111110,
    B01111110},
   {//3
    B00111100,
    B01111110,
    B01000110,
    B00001100,
    B00001100,
    B01000110,
    B01111110,
    B00111100},
   {//4
    B00000100,
    B00001100,
    B00010100,
    B00100100,
    B01111110,
    B01111110,
    B00000100,
    B00000100},
   {//5
    B01111110,
    B01111110,
    B01100000,
    B01111100,
    B01111110,
    B00000110,
    B01100110,
    B00111100},
   {//6
    B00111100,
    B01100110,
    B01100000,
    B01111100,
    B01111110,
    B01100110,
    B01100110,
    B00111100},
   {//7
    B01111110,
    B01111110,
    B00000110,
    B00001100,
    B00001100,
    B00011000,
    B00011000,
    B00011000},
   {//8
    B00111100,
    B01100110,
    B01100110,
    B00111100,
    B00111100,
    B01100110,
    B01100110,
    B00111100},
   {//9
    B00111100,
    B01100110,
    B01100110,
    B01111110,
    B00111110,
    B00000110,
    B01100110,
    B00111100}
};
int str_length(char str[]) {
  int count; 
  for (count = 0; str[count] != '\0'; ++count);
  return count; 
}
void Clear(int TimeDelay){
  for (int j=0;j<8;j++){
      senddata(j+1, c[j]);
    }
    delay(TimeDelay);
}
void Blend285(int TimeDelay){
  for (int j=0;j<8;j++){
      senddata(j+1, tri[j]);
    }
    delay(TimeDelay);
}

void CaptainMorgan(char text[],int TimeDelay){//text,time
  for(int i=0;i<str_length(text);i++){//loop word
    Serial.print(i);
    for (int j=0;j<8;j++){
      if(text[i]>90)text[i]-=32;
      senddata(j+1, Char[text[i]-65][j]);
      
      
    }
    delay(TimeDelay);
    Clear(5);
  }
}


 void JohnnyWalker(int number,int TimeDelay){//number
  char cstr[4];
  sprintf(cstr, "%04d", number);
  for(int i=0;i<4;i++){//loop word
    
    for (int j=0;j<8;j++) senddata(j+1, NUM[cstr[i]-'0'][j]);
    delay(TimeDelay);
    Clear(5);
  }
  for (int j=0;j<8;j++) senddata(j+1, PIC[(cstr[3]-'0')%5][j]);
  delay(TimeDelay);
 }
void SoSad(char Name[],int pa){
    Blend285(1000);
    Clear(5);
    CaptainMorgan(Name,1000);
    JohnnyWalker(pa,1000);
}

void CheckCharAll(){
  for(int i=0;i<27;i++){//loop word
    
    for (int j=0;j<8;j++){
      senddata(j+1, Char[i][j]);
    }
    delay(1000);
    Clear(5);
  }
}

void CheckChar(int index){
  
    
    for (int j=0;j<8;j++){
      senddata(j+1, Char[index-1][j]);
    }
    delay(1000);
    
  
}
void CheckNumberAll(){
  for(int i=0;i<10;i++){//loop word
    
    for (int j=0;j<8;j++){
      senddata(j+1, NUM[i][j]);
    }
    delay(1000);
    Clear(5);
  }
}
void CheckNumber(int index){
  
    
    for (int j=0;j<8;j++){
      senddata(j+1, NUM[index][j]);
    }
    delay(1000);
    Clear(5);
  
}

void CheckPic(int index){
  if(index<5){
    for (int j=0;j<8;j++){
      senddata(j+1, PIC[index][j]);
    }
    delay(1000);
  }
  else{
  for(int i=0;i<5;i++){//loop word
    
    for (int j=0;j<8;j++){
      senddata(j+1, PIC[i][j]);
    }
    delay(1000);
    
  }
  }
}
  
