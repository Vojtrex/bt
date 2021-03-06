/*******************************************************************************
  XDMAC PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_xdmac.h

  Summary:
    XDMAC PLIB Header File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/

#ifndef PLIB_XDMAC_H
#define PLIB_XDMAC_H

#include <stddef.h>
#include <stdbool.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Interface
// *****************************************************************************
// *****************************************************************************

/****************************** XDMAC Data Types ******************************/
/* Peripheral address macros for DMA */
#define I2SC1_RECEIVE_LEFT_ADDRESS  (&I2SC0_REGS->I2SC_RHR)
#define I2SC1_TRANSMIT_LEFT_ADDRESS  (&I2SC0_REGS->I2SC_THR)

/* XDMAC Channels */
typedef enum {
    XDMAC_CHANNEL_0,
    XDMAC_CHANNEL_1,
    XDMAC_CHANNELS_NUMBER

} XDMAC_CHANNEL;


/* XDMAC Transfer Events */
typedef enum
{
    /* Data was transferred successfully. */
    XDMAC_TRANSFER_COMPLETE,

    /* Error while processing the request */
    XDMAC_TRANSFER_ERROR

} XDMAC_TRANSFER_EVENT;

/* XDMAC Channel Config Type */
typedef uint32_t XDMAC_CHANNEL_CONFIG;


typedef void (*XDMAC_CHANNEL_CALLBACK)( XDMAC_TRANSFER_EVENT event, uintptr_t contextHandle );


/****************************** XDMAC API *********************************/

void XDMAC_Initialize( void );

void XDMAC_ChannelCallbackRegister( XDMAC_CHANNEL channel, const XDMAC_CHANNEL_CALLBACK eventHandler, const uintptr_t contextHandle );

void XDMAC_ChannelTransfer( XDMAC_CHANNEL channel, const void *srcAddr, const void *destAddr, size_t blockSize );

bool XDMAC_ChannelIsBusy (XDMAC_CHANNEL channel);

void XDMAC_ChannelDisable (XDMAC_CHANNEL channel);

XDMAC_CHANNEL_CONFIG XDMAC_ChannelSettingsGet (XDMAC_CHANNEL channel);

bool XDMAC_ChannelSettingsSet (XDMAC_CHANNEL channel, XDMAC_CHANNEL_CONFIG setting);

void XDMAC_ChannelBlockLengthSet (XDMAC_CHANNEL channel, uint16_t length);
// *****************************************************************************
// *****************************************************************************
// Section: Local: **** Do Not Use ****
// *****************************************************************************
// *****************************************************************************

void XDMAC_InterruptHandler(void);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_XDMAC_H
