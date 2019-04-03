/* Proj 2019 */
/* By hxdyxd */

#include "stm32f10x.h"
#include "soft_timer.h"
#include "app_debug.h"
#include "type.h"
#include "lora_net.h"

//hal
#include "data_interface_hal.h"


void led_proc(void)
{
    led_rev(LED_R);
    led_off(LED_B);
    char *strt = "hello world \r\n";
    lora_net_write_no_block( (uint8_t *)strt, strlen(strt) );
    APP_DEBUG("rev leds \r\n");
}


void key_press_proc(int8_t id)
{
    led_rev(LED_R);
    led_rev(LED_B);
    APP_DEBUG("key press \r\n");
}

void lora_receive_proc(uint8_t *buf, uint16_t len)
{
    if(len != 0)
        APP_DEBUG("%.*s (%d)\r\n", len, (char *)buf, len);
}


int main(void)
{
    data_interface_hal_init();
    PRINTF("\r\n\r\n Build , %s %s \r\n", __DATE__, __TIME__);
    
    soft_timer_init();
    
    soft_timer_create(SOFT_TIMER_LED, 1, 1, led_proc, 500);
    
    lora_net_init();
    
    APP_DEBUG("init success \r\n");
    
    while(1)
    {
        soft_timer_proc();   //timer
        //keys_proc(key_press_proc);  //key
        lora_net_proc(lora_receive_proc);
    }
    
}

/******************* (C) COPYRIGHT 2018 hxdyxd *****END OF FILE****/
