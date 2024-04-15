#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


int led[60][11]= {{0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   
                  {0,0,0,0,0,1,1,1,1,1,1}, //6
                  {0,0,0,0,0,1,0,0,0,0,0},
				  {0,0,0,0,0,1,0,0,0,0,0},
				  {0,0,0,0,0,1,0,0,0,0,0},
				  {0,0,0,0,0,1,1,1,1,1,1},
                   {0,0,0,0,0,0,0,0,0,0,0},
				   
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,1,1,1,1,1,1},
				   {0,0,0,0,0,1,0,0,0,0,1},
				   {0,0,0,0,0,1,0,0,0,0,1},
				   {0,0,0,0,0,1,0,0,0,0,1}, //1
				  
				  {0,0,0,0,0,1,1,1,1,1,1},
				  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,1,1,1,1,1,1},
				   {0,0,0,0,0,1,0,0,0,0,1},
				   {0,0,0,0,0,1,0,0,0,0,1},
				   
				   {0,0,0,0,0,1,0,0,0,0,1},
				   {0,0,0,0,0,1,0,0,0,0,1},
				   {0,0,0,0,0,0,0,0,0,0,0}, //2
                  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0,0},
				  
				  {0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,1,1,1,1,1,1},
				   {0,0,0,0,0,0,0,0,1,0,1},
				   {0,0,0,0,0,0,0,0,1,0,1},
				   
				   
				   {0,0,0,0,0,0,0,0,1,0,1}, //3
                  {0,0,0,0,0,0,0,0,1,0,1},
				  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,1,1,1,1,1,1},
				   {0,0,0,0,0,1,0,0,0,0,1},
				   
				   {0,0,0,0,0,1,0,0,0,0,1},
				   {0,0,0,0,0,1,0,0,0,0,1}, //1
                  {0,0,0,0,0,1,1,1,1,1,1},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0}, //4
                  {0,0,0,0,0,1,0,0,1,1,1},
				  
				  {0,0,0,0,0,1,0,0,1,0,1},
				  {0,0,0,0,0,1,0,0,1,0,1},
				  {0,0,0,0,0,1,0,1,0,0,1},
                  {0,0,0,0,0,1,1,1,0,0,1},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0,0,0,0}, //5
                  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0,0}}; // matrix for newton colour plate	
				   

				   
int red[10][11]=  {{255,255,255,255,255,255,255,255,255,255,255}, //red
				   
                   {255,255,255,255,255,255,255,255,255,255,255},//orange
				    
				   {255,255,255,255,255,255,255,255,255,255,255}, //yellow
				   
                   {127,127,127,127,127,127,127,127,127,127,127},//green-1				   
				   
				   {0,0,0,0,0,0,0,0,0,0,0}, //green-2
				   
                   {0,0,0,0,0,0,0,0,0,0,0}, //cyan
				   
				   {0,0,0,0,0,0,0,0,0,0,0}, //blue-1

                   {0,0,0,0,0,0,0,0,0,0,0}, //blue-2

                   {127,127,127,127,127,127,127,127,127,127,127}, //purple

                   {255,255,255,255,255,255,255,255,255,255,255}}; //magenta
				   
				   
				   
				   
int green[10][11]={{0,0,0,0,0,0,0,0,0,0,0}, //red
				   
                   {127,127,127,127,127,127,127,127,127,127,127},//orange
				   
				   {255,255,255,255,255,255,255,255,255,255,255}, //yellow

                   {255,255,255,255,255,255,255,255,255,255,255}, //green-1 
				   
				   {255,255,255,255,255,255,255,255,255,255,255}, //green-2
				   
                   {255,255,255,255,255,255,255,255,255,255,255}, //cyan
				   
				   {127,127,127,127,127,127,127,127,127,127,127},//blue-1
				   
                   {0,0,0,0,0,0,0,0,0,0,0}, //blue-2

                   {0,0,0,0,0,0,0,0,0,0,0}, //purple

                   {0,0,0,0,0,0,0,0,0,0,0}}; //magenta
				   
				   
int blue[10][11]= {{0,0,0,0,0,0,0,0,0,0,0}, //red

                   {0,0,0,0,0,0,0,0,0,0,0}, //orange
				   
				   {0,0,0,0,0,0,0,0,0,0,0}, //yellow

                   {0,0,0,0,0,0,0,0,0,0,0}, //green-1
				   
				   {0,0,0,0,0,0,0,0,0,0,0}, //green-2
				   
                   {255,255,255,255,255,255,255,255,255,255,255}, //cyan

				   {255,255,255,255,255,255,255,255,255,255,255}, //blue-1

                   {255,255,255,255,255,255,255,255,255,255,255}, //blue-2

				   {255,255,255,255,255,255,255,255,255,255,255}, //purple

                   {255,255,255,255,255,255,255,255,255,255,255}}; //magenta
				   
			   

volatile unsigned char time_ms=0; 
volatile unsigned char data=0;



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	

int main (void){
    DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0xFB;
	
	void portA_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time);
	void portB_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time);
	void portC_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time);
	void portD_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time);
	void pixel_2(unsigned int x,unsigned int y,unsigned int T);

	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	MCUCR |= 1<<ISC01|1<<ISC00; // MCU Control Register: detect Rising edge for interupt pin 0
    GICR |= 1<<INT0;  // Genaral Interrupt Control Rgister:External interupt pin 0 enable
	
	sei(); // Global Interrupt enable

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
while(1){
    int t= 1000;

	if(data==1){   //if data_1 equals to 1 exicute statements in the loop 
		for(int j=0;j<60;j++){
	        if((0<=j)&&(j<11)){
			    pixel_2(j,2,t);
				j=j+1;
			}
			if((10<j)&&(j<18)){
			    pixel_2(j,9,t);
				j=j+1;
			}
			if((17<j)&&(j<25)){
			    pixel_2(j,2,t);
				j=j+1;
			}
			if((24<j)&&(j<37)){
			    pixel_2(j,9,t);
				j=j+1;
			}
			if((36<j)&&(j<44)){
			    pixel_2(j,2,t);
				j=j+1;
			}
			if((43<j)){
			    pixel_2(j,9,t);
				j=j+1;
			}
		    data=0;
			}
		}
    }
}      



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


ISR(INT0_vect){  //External Interrupt Service rooting 
        data=1;   //data_1 equals to 1
        TCCR0=0;     //stop couner 0 
		TCCR1A=0;
		TCCR1B=0;    //stop couner 1
		TCCR2=0;     //stop couner 2
}	



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void portA_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time){
        TCCR0=0; 
		TCCR1A=0;
		TCCR1B=0;
		TCCR2=0;
	
	
	    TCCR0 = (1<<WGM00)|(1<<COM01)|(1<<CS00);   // counter 0 timer control register set as PWM MOde ; clear OC0 on compare match ; Prescale-1
	    TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM12)|(1<<WGM10);
	    TCCR1B = (1<<CS10);  // counter 1 timer control register set as PWM MOde ; clear OC1A and OC1B on compare match ; Prescale-1
        OCR1AH= 0;
	    TCCR2 = (1<<WGM00)|(1<<COM01)|(1<<CS20);   // counter 2 timer control register set as fast PWM MOde ; clear OC2 on compare match ; Prescale-1
		
                
        if(state==1){   //if state equles to 1 exicute statments in the loop
		    PORTA|=state<<pin;   //'state' is a given 1st parameter and 'pin' is given 2nd parameter
			OCR0= 255-r;  //'r' is a given 3rd parameter
            OCR1AL= 255-g;  //'g' is a given 4th parameter
            OCR2= 255-b;    //'b' is a given 5th parameter 
			if(time!=0){    //if time not eqyals to zero then there is a time delay
			    _delay_us(time);    //'time' is a given 6th parameter
		    }

	    }
		else{
		    PORTA&= ~(1<<pin);  //if state is not equals to 1 then logic zero corresponding pin
		}
		
}

void portB_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time){ 
        TCCR0=0; 
		TCCR1A=0;
		TCCR1B=0;
		TCCR2=0;
	
	    TCCR0 = (1<<WGM00)|(1<<COM01)|(1<<CS00);
	    TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM12)|(1<<WGM10);
	    TCCR1B = (1<<CS10);
        OCR1AH = 0;
	    TCCR2 = (1<<WGM00)|(1<<COM01)|(1<<CS20);
		
		if(state==1){
		    PORTB|=state<<pin;
			OCR0= 255-r;
            OCR1AL= 255-g;
            OCR2= 255-b;
			if(time!=0){
			    _delay_us(time); 
		    }

	    }
		else{
		    PORTB&= ~(1<<pin);
		}  
	
}	

void portC_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time){
        TCCR0=0; 
		TCCR1A=0;
		TCCR1B=0;
		TCCR2=0;
	  	
		TCCR0 = (1<<WGM00)|(1<<COM01)|(1<<CS00);
	    TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM12)|(1<<WGM10);
	    TCCR1B = (1<<CS10);
        OCR1AH= 0;
	    TCCR2 = (1<<WGM00)|(1<<COM01)|(1<<CS20);
		
		if(state==1){
		    PORTC|=state<<pin;
			OCR0= 255-r;
            OCR1AL= 255-g;
            OCR2= 255-b;
			if(time!=0){
			    _delay_us(time); 
		    }

	    }
		else{
		    PORTC&= ~(1<<pin);
		}
    		    
}	

void portD_light(unsigned int state,unsigned int pin,unsigned int r,unsigned int g,unsigned int b,unsigned int time){  
        TCCR0=0; 
		TCCR1A=0;
		TCCR1B=0;
		TCCR2=0;
	
		TCCR0 = (1<<WGM00)|(1<<COM01)|(1<<CS00);
	    TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM12)|(1<<WGM10);
	    TCCR1B = (1<<CS10);
        OCR1AH= 0;
	    TCCR2 = (1<<WGM00)|(1<<COM01)|(1<<CS20);
		
		if(state==1){
		    PORTD|=state<<pin;
			OCR0= 255-r;
            OCR1AL= 255-g;
            OCR2= 255-b;
			if(time!=0){
			    _delay_us(time); 
		    }

	    }
		else{
		    PORTD&= ~(1<<pin);
		}
	
}


void pixel_2(unsigned int x,unsigned int y,unsigned int T){
        portC_light(led[x][0],0,red[y][0],green[y][0],blue[y][0],0);
		portD_light(led[x][1],0,red[y][1],green[y][1],blue[y][1],0);
        portD_light(led[x][2],1,red[y][2],green[y][2],blue[y][2],0); 
		portD_light(led[x][3],3,red[y][3],green[y][3],blue[y][3],0);
		portD_light(led[x][4],6,red[y][4],green[y][4],blue[y][4],0);
		
        portB_light(led[x][5],0,red[y][5],green[y][5],blue[y][5],0);
        portC_light(led[x][6],1,red[y][6],green[y][6],blue[y][6],0);
		portB_light(led[x][7],2,red[y][7],green[y][7],blue[y][7],0);
		portB_light(led[x][8],4,red[y][8],green[y][8],blue[y][8],0);
		portB_light(led[x][9],5,red[y][9],green[y][9],blue[y][9],0);
		portB_light(led[x][10],6,red[y][10],green[y][10],blue[y][10],0);
		
        _delay_us(T);
		
        PORTA=0;
        PORTB=0;
        PORTC=0;
        PORTD=0;		    
}