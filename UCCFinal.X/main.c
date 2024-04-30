/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q10
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include "mcc_generated_files/i2c1_master.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "mcc_generated_files/spi2.h"
#include <stdio.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart2.h"
#include "mcc_generated_files/i2c1_master.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"




// Addresses for the Humidity Sensor
uint16_t humidVal = 0;
uint8_t addH = 0x44;
uint8_t dataH = 0xFD;



//Addresses for Temp
#define TempVal 0x4C
#define Zero 0x00
uint16_t tempR = 0;

//Timer Vals
uint16_t dStart = 0;
uint16_t dc;
uint16_t timeS = 0;
uint16_t timeMs = 0;
int Humid = 10;
int Temp = 76;
int rand1;
int rand2;
int rand3;
int rand4;
int MotOn = 0;
int MotTime = 0;
int MotEffect = 0;
//Timer Interrupts
void timerCall (void){
    timeMs = timeMs+1;
    
    if(timeMs == 1000){
        timeS = timeS+1;
        timeMs = 0;
        LED2_SetHigh();
        
        //motor code
        if(MotOn == 1){
            LED_SetHigh();
            MotTime++;
            MotEffect++;
            if(MotEffect == 2 || MotEffect == 4){
            Temp = Temp-1;
            }
            if(MotEffect == 4){
            Humid = Humid-1;
            MotEffect = 0;
            }
            
        }
        
        
        
        
        rand1 = rand() % 20;
        rand2 = rand() % 2;
        if (rand1 <= 10 && MotOn == 0){
            Humid = Humid + rand2;
        }
             
        rand3 = rand() % 20;
        rand4 = rand() % 3;
        if (rand3 >= 10 && MotOn == 0){
            Temp = Temp + rand4;
            
        }
        if (rand3 < 10){
            Temp = Temp;
        }
        // Set ii to zero if it's greater than or equal to 100
        if (Humid > 13){
            Humid = 13;
        }
        if (Temp > 180){
            Temp = 180;
        }
        if (Humid < 7){
            Humid = 7;
        }
        if (Temp < 70){
            Temp = 70;
        }
        if(Temp >= 86 && MotOn == 0){
            MotOn = 1;
        }
        
        if(MotTime >= 20){
            MotOn = 0;
            MotTime=0;
            LED_SetLow();
        }
        
        
        //Get Temp & Humidity each second
        //humidVal = I2C1_Read1ByteRegister(addH,dataH);
        //printf("Humidity: %u%% || Temp: %u F\r", humidVal, 12);

        printf("Humidity: %d%% || Temp: %d F\r", Humid, Temp);
       
        //increment time motor has been on
        
    }
    if(timeMs == 50){
      
        LED2_SetLow();
        
    }
    //turn on motor under certain circumstances

    
    
}

//Function to initialize SPI communication
////void SPI_Init() {
////    //SSP1CON1 = 0b00100000; // Enable SPI Master mode, clock = FOSC/4
////    //SSP1STAT = 0;
////    TRISCbits.TRISC5 = 0; // Set SS pin (RC5) as output
////    LATCbits.LATC5 = 1;   // Set SS pin high initially
////}





/*
                         Main application
 */


   
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    TMR2_Initialize();
    PIN_MANAGER_Initialize();
    INTERRUPT_Initialize();
    I2C1_Initialize();
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    TMR2_SetInterruptHandler (timerCall);
    TMR2_Start();
    
    
    while (1)
    {
        //Turn motor on if need be
        
        
      
        
        
        
        //tempR = I2C1_Read1ByteRegister(TempVal, Zero);
        // Print formatted string
       
        // Print formatted string
       
        
        
        //Set bounds for Humidity and Temperature
      
       
 
   
        
    }
}
/**
 End of File
*/