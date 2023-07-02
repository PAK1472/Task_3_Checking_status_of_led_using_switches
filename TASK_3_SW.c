/*Maaz khan
 * Reg No : 19jzele0320
 */
#include "F28x_Project.h"

////// MAAZ KHAN  /////////////////////

#define LED1 GpioDataRegs.GPBDAT.bit.GPIO34
#define LED2 GpioDataRegs.GPADAT.bit.GPIO31
#define SWITCH1 GpioDataRegs.GPCDAT.bit.GPIO67
#define SWITCH2 GpioDataRegs.GPADAT.bit.GPIO22
#define SWITCH3 GpioDataRegs.GPADAT.bit.GPIO7

/////// MAAZ KHAN ////////////////////////
void main(){
    //Initialization of System Control
    InitSysCtrl();
    //Initialization of General Purpose Input Output Pins
    InitGpio();

    ////////// MAAZ KHAN ////////////////

    EALLOW;
    //Configure GPIO67 and  GPIO22 as an Input
    GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO67 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO22 = 0;
    //Configure GPIO34 and  GPIO31 as an Output
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    EDIS;
    while(1){

        //////////////// MAAZ KHAN ////////////////

        // if LED1 is on
        if(SWITCH1==1 & LED1==1){
            // LED1 shoukd turn off
            LED1=0;
        }
        // if LED2 is off
        if(SWITCH2==1 & LED2==0){
            // LED2 should turn on
            LED2=1;
        }
    }

}
