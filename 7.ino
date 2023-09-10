#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);
const byte rows=4;
const byte cols=4;
char keys[rows][cols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
char k;
byte row_pins[]={2,3,4,5};
byte col_pins[]={6,7,8,9};
Keypad keypad = Keypad (makeKeymap(keys),row_pins,col_pins,rows,cols);
char check[]={"785219"};
byte counter=0,i=0,num=sizeof(check)-1;
char pass[sizeof(check)-1];
#define led 13
void start(){
  lcd.clear();
        digitalWrite(led,LOW);
        lcd.print("Wrong pass  ");
        delay(2000);
        i=0,counter=0;
        lcd.setCursor(0,0);
        lcd.print("Enter Pass  ");
        lcd.setCursor(0,1);
}
void setup() {
  lcd.init();
  lcd.backlight();
  //start();
  lcd.print("Enter Pass  ");
  lcd.setCursor(0,1);
  pinMode(led,OUTPUT);

}

void loop() {
  k = keypad.getKey();
  if(k>'0'&&k!='D'){
    lcd.print('*');
    pass[i]=k;
    i++;
  }else if(k=='D'){
    if(i==num){
      for(byte j=0;j<num;j++){
        if(pass[j]==check[j])counter++;
      }if(counter==num){
        lcd.clear();
        digitalWrite(led,HIGH);
        lcd.print("Correct pass  ");
        delay(2000);
        i=0,counter=0;
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
        lcd.print("Enter Pass  ");
        lcd.setCursor(0,1);
      
    }else{
      start();
    }
    }else{
      start();
    }
  }if(k=='A'){
    lcd.clear();
        digitalWrite(led,LOW);
        delay(2000);
        i=0,counter=0;
        lcd.setCursor(0,0);
        lcd.print("Enter Pass  ");
        lcd.setCursor(0,1);
  }
  }
