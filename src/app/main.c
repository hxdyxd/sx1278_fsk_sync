/* Proj 2019 */
/* By hxdyxd */

#include "stm32f10x.h"
#include "soft_timer.h"
#include "app_debug.h"
#include "type.h"
#include "lora_net.h"

//hal
#include "data_interface_hal.h"

char *strt = "t\r\n";
uint8_t gu8_status = 0;

void led_proc(void)
{
    if(gu8_status)
        led_on(LED_R);
    else
        led_off(LED_R);
    
#if (_RX_C || _TX_C)
    //Continuous mode, lora_net_write_no_block can not be used
#else
    lora_net_write_no_block( &gu8_status, 1);
#endif
    
    APP_DEBUG("status: %d\r\n", gu8_status);
    gu8_status = !gu8_status;
}


void key_press_proc(int8_t id)
{
    led_rev(LED_R);
    led_rev(LED_B);
    APP_DEBUG("key press \r\n");
}

void lora_receive_proc(uint8_t *buf, uint16_t len)
{
    if(len == 1) {
        if(*buf)
            led_on(LED_B);
        else
            led_off(LED_B);
    }
    //if(len != 0)
        //APP_DEBUG("%.*s (%d)\r\n", len, (char *)buf, len);
}


int main(void)
{
    data_interface_hal_init();
    PRINTF("\r\n\r\n Build , %s %s \r\n", __DATE__, __TIME__);
    
    soft_timer_init();
    
    //soft_timer_create(SOFT_TIMER_LED, 1, 1, led_proc, 1000);
    
    lora_net_init();
    
    APP_DEBUG("init success \r\n");
    
    while(1)
    {
        soft_timer_proc();   //timer
        //keys_proc(key_press_proc);  //key
#if !(_RX_C || _TX_C)
        lora_net_proc(lora_receive_proc);  //Continuous mode, not used
#endif
    }
    
}

/******************* (C) COPYRIGHT 2018 hxdyxd *****END OF FILE****/
