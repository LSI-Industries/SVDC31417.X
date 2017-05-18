/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - pic24-dspic-pic32mm : v1.25
        Device            :  PIC24FJ256GA106
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.26
        MPLAB             :  MPLAB X 3.45
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */
#include "p24FJ256GA106.h"
#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/mcc.h"


// Timer 2 ISR
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void){
    _T2IE = 0;
    _T2IF = 0;
    _T2IE = 1;
}
/*
                         Main application
 */
int main(void) {
    // initialize the device
    SYSTEM_Initialize();

    int timerVal = 65535; //65535, 65535/2= 32767, 65535/4=16383, 16383/2=8191
    int dutyCycle = 32767; //
    int periodVal = 32767;
    // Setup PWM and UART pins
    __builtin_write_OSCCONL(OSCCON & 0xBF);
    // Configure Input Functions (Table 9-1))
    // UART Settings
    // Assign U1RX To Pin RP11, RD0
    RPINR18bits.U1RXR = 11;
    // Assign U1CTS To Pin RP12, RD11
    RPINR18bits.U1CTSR = 12;
    // Configure Output Functions (Table 9-2)
    // Assign U1TX To Pin RP2, RD8
    RPOR1bits.RP2R = 3;
    // Assign U1RTS To Pin RP3, RD10
    RPOR1bits.RP3R = 4;

    // PWM 1 Output settings OC1 RP11 RD0
    RPOR5bits.RP11R = 18;

    // PWM 1 Output settings OC1 RP13 RB2
    //RPOR6bits.RP13R=18;

    // PWM 2 Output settings OC2 RP24 RD1
    RPOR12bits.RP24R = 19;

    // PWM 3 Output settings OC3 RP23 RD2
    RPOR11bits.RP23R = 20;

    // PWM 4 Output settings OC4 RP22 RD3
    RPOR11bits.RP22R = 21;

    // PWM 5 Output settings OC5 RP25 RD4
    RPOR12bits.RP25R = 22;


    // Lock Registers
    __builtin_write_OSCCONL(OSCCON | 0x40);

    // PWM

    OC1CON1 = 0; // clear
    OC1CON2 = 0; // clear
    OC1CON2bits.SYNCSEL = 0;
    OC1CON2bits.OCTRIG = 0;

    OC1CON1bits.OCTSEL = 0b000; // timer 2
    OC1CON1bits.OCM = 0b110; // edge triggered PWM

    //OC1CON2=0b0000000000000000;
    OC1CON2bits.OCINV = 1; // Invert the PWM signal because of the NPN switch before driver
    // setup timer 2
    T2CONbits.T32 = 0;
    T2CONbits.TON = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.TCKPS = 0b00;
    TMR2 = 0x00;
    PR2 = 32767;
    T2CONbits.TON = 1;
    _T2IF = 0;
    _T2IE = 0;
     _T2IF = 0;
    _T2IE = 1;

    //setup timer 1
    /*
T1CONbits.TCKPS = 0;
T1CONbits.TCS = 0;
T1CONbits.TSIDL = 0;
T1CONbits.TGATE = 0;
T1CONbits.TON = 1; // enable
PR1 = timerVal; // period for timer
_T1IF = 0; // clear int flag
_T1IE = 0; // disable int
     */


    // init PWM
    OC1R = dutyCycle; // 
    OC1RS =periodVal; // 
    while (1) {
        //timerVal = 0;
        //periodVal = 0;
    }

    return -1;
}
/**
 End of File
 */
