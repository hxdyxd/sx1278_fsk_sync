/* LORANET 2018 06 27 END */
/* By hxdyxd */
#include "lora_net.h"
#include "type.h"


uint8_t gu8_lora_buffer[512];
uint16_t gu16_lora_size = 0;

int lora_net_init(void)
{
#if _RX_C
    //Continuous mode
    SX1276FskInit_Debug();
    SX1276FskSetOpMode( RF_OPMODE_RECEIVER );
#elif _TX_C
    //Continuous mode
    SX1276FskInit_Debug();
    SX1276FskSetOpMode( RF_OPMODE_TRANSMITTER );
#else
    //Packet mode
    SX1276FskInit();
    SX1276FskStartRx();
#endif
    return 0;
}

#if (_RX_C || _TX_C)
//Continuous mode

#else
//Packet mode
void lora_net_proc( void ( *user_func)(uint8_t *buf, uint16_t len))
{
    uint32_t stat;
    int i;
    for(i=0; i<1; i++) {
        stat = SX1276FskProcess();
        switch(stat)
        {
        case RF_BUSY:
            break;
        case RF_RX_DONE:
            SX1276FskGetRxPacket( gu8_lora_buffer, &gu16_lora_size );
            user_func(gu8_lora_buffer, gu16_lora_size);   //User callback function
            break;
        case RF_TX_DONE:
            SX1276FskStartRx();
            break;
        case RF_RX_TIMEOUT:
            //APP_DEBUG("rx timeout \r\n");
            break;
        default:
            APP_ERROR("stat = %d \r\n", stat);
            break;
        }
    }
}


int lora_net_write_no_block(uint8_t *buffer, uint16_t len)
{
    //APP_DEBUG(" test = %d, %d\r\n", netp->RxTimeout, netp->TxTimeout);
    if(len > RF_BUFFER_SIZE - 1) {
        len = RF_BUFFER_SIZE - 1;
    }
    SX1276FskSetTxPacket(buffer, len);
    return len;
}
#endif

void lora_net_debug_hex(uint8_t *p, uint8_t len, uint8_t lf)
{
    int i;
    for(i=0;i<len;i++) {
        printf("%02x", *p );
        p++;
    }
    if(lf) {
        printf("\r\n");
    }
}

