/**************************************************************************************************

    Phyplus Microelectronics Limited confidential and proprietary.
    All rights reserved.

    IMPORTANT: All rights of this software belong to Phyplus Microelectronics
    Limited ("Phyplus"). Your use of this Software is limited to those
    specific rights granted under  the terms of the business contract, the
    confidential agreement, the non-disclosure agreement and any other forms
    of agreements as a customer or a partner of Phyplus. You may not use this
    Software unless you agree to abide by the terms of these agreements.
    You acknowledge that the Software may not be modified, copied,
    distributed or disclosed unless embedded on a Phyplus Bluetooth Low Energy
    (BLE) integrated circuit, either as a product or is integrated into your
    products.  Other than for the aforementioned purposes, you may not use,
    reproduce, copy, prepare derivative works of, modify, distribute, perform,
    display or sell this Software and/or its documentation for any purposes.

    YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
    PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
    INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
    NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
    PHYPLUS OR ITS SUBSIDIARIES BE LIABLE OR OBLIGATED UNDER CONTRACT,
    NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
    LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
    OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
    OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

**************************************************************************************************/

/**************************************************************************************************
    Filename:       simpleBLECentral.h
    Revised:        $Date: 2011-03-03 15:46:41 -0800 (Thu, 03 Mar 2011) $
    Revision:       $Revision: 12 $

    Description:    This file contains the Simple BLE Central sample application
                  definitions and prototypes.

**************************************************************************************************/

#ifndef SIMPLEBLECENTRAL_H
#define SIMPLEBLECENTRAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "osal.h"

/*********************************************************************
    INCLUDES
*/

/*********************************************************************
    CONSTANTS
*/


// Simple BLE Central Task Events
#define START_DEVICE_EVT                                0x0001
#define CENTRAL_DISCOVER_DEVDONE_EVT                    0x0002
#define START_DISCOVERY_SERVICE_EVT                     0x0004
#define OTA_DATA_DELAY_WRITE_EVT                        0x0008
#define BLE_CMD_WRITE_OP_TIMEOUT_EVT                    0x0010
#define OTA_APP_DISCONN_DELAY_EVT                       0x0020
#define START_PHY_DEL_MTU_EVT                           0x0040
#define START_UPD_PHY_MODE_EVT                          0x0080
#define ONECLK_OP_TIMEOUT_EVT                           0x0100
#define ONECLK_OP_NEXTDEV_EVT                           0x0200
#define ONECLK_OP_CONN_PARAM_UPDATE                     0x0400
#define ONECLK_OP_OTA_RESUME_EVT                        0x0800
#define ONECLK_OP_OTA_AUTOSCAN_EVT                      0x1000
#define OTA_PROCESS_TIMEOUT_EVT                         0x2000

#define OTAM_MSG_EVENT                                  0xf0        // osal message


#define OTADBG_INFO                                     1
#if(OTADBG_INFO == 1)
#define OTA_LOG(...)  dbg_printf(__VA_ARGS__)
#else
#define OTA_LOG(...)
#endif

enum
{
    OTAC_RUNMODE_UNKNOW = 0,
    OTAC_RUNMODE_APP,
    OTAC_RUNMODE_OTA,
    OTAC_RUNMODE_OTARES     // ota resource mode
};


enum
{
    OTAM_CMD_HELP = 1,
    OTAM_CMD_SCAN,
    OTAM_CMD_SCAN_FAST,
    OTAM_CMD_SCAN_WL,
    OTAM_CMD_CONNECT,
    OTAM_CMD_CONNECT_WL,
    OTAM_CMD_DISCONNECT,
    OTAM_CMD_OTA_MODE,
    OTAM_CMD_OTA_START,
    OTAM_CMD_OTA_STOP,
    OTAM_CMD_OTA_REBOOT,
    OTAM_CMD_ONE_CLK,
    OTAM_CMD_WHITE_LIST,
    OTAM_CMD_ADDR_RANGE
};


typedef enum
{
    OTA_IDLE,
    OTA_SUCCESS,
    OTA_NO_SERVICE,
    OTA_CONNECT_FAIL,
} ota_s_e;


typedef struct
{
    osal_event_hdr_t hdr;
    uint8_t mode;
} otam_cmd_mode_t;

typedef struct
{
    osal_event_hdr_t hdr;
    uint8_t id;
    uint8_t mac[6];
} otam_cmd_conn_t;

extern uint8_t otaMasterTaskId;


/*********************************************************************
    FUNCTIONS
*/

/*
    Task Initialization for the BLE Application
*/
extern void Singlebank_OTAdongle_Init( uint8 task_id );

/*
    Task Event Processor for the BLE Application
*/
extern uint16 Singlebank_OTAdongle_ProcessEvent( uint8 task_id, uint16 events );


bool otaMaster_EstablishLink(uint8_t addr_type, uint8_t* addr);

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* SIMPLEBLECENTRAL_H */
