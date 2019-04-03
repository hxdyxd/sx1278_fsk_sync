/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND 
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * 
 * Copyright (C) SEMTECH S.A.
 */
/*! 
 * \file       sx1276-Hal.h
 * \brief      SX1276 Hardware Abstraction Layer
 *
 * \version    2.0.B2 
 * \date       May 6 2013
 * \author     Gregory Cristian
 *
 * Last modified by Miguel Luis on Jun 19 2013
 */
#ifndef __SX1276_HAL_H__
#define __SX1276_HAL_H__

#include "data_interface_hal.h"
#include "stdio.h"

/*!
 * DIO state read functions mapping
 */
//#define DIO0                                       GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)//SX1276ReadDio0( )
//#define DIO1                                       GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) //SX1276ReadDio1( )
//#define DIO2                                       GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4) //SX1276ReadDio2( )
//#define DIO3                                       GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) //SX1276ReadDio3( )
//#define DIO4                                       GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2) //SX1276ReadDio4( )
//#define DIO5                                       GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) //SX1276ReadDio5( )

// RXTX pin control see errata note
#define RXTX( txEnable )                            ;//printf("RXTX( %d )\r\n", txEnable);//SX1276WriteRxTx( txEnable );
#define GET_TICK_COUNT() clk_count
#define TICK_RATE_MS(a) (a)

#define SX1276WriteFifo(buffer, size) SX1276WriteBuffer(0, buffer, size)

#define SX1276ReadFifo(buffer, size) SX1276ReadBuffer(0, buffer, size)

#define  MODULE_SX1276RF1IAS  (1)


typedef enum
{
    RADIO_RESET_OFF,
    RADIO_RESET_ON,
}tRadioResetState;




#endif //__SX1276_HAL_H__
