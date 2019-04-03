/* LORANET GATEWAY 2018 06 27 END */
/* By hxdyxd */

#ifndef _LORA_NET_H
#define _LORA_NET_H

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sx1276-Fsk.h"
#include "sx1276-FskMisc.h"
#include "type.h"
#include "app_debug.h"




int lora_net_init(void);

#if (_RX_C || _TX_C)
//Continuous mode

#else
//Packet mode
void lora_net_proc( void ( *user_func)(uint8_t *buf, uint16_t len));

int lora_net_write_no_block(uint8_t *buffer, uint16_t len);

void lora_net_debug_hex(uint8_t *p, uint8_t len, uint8_t lf);

#endif


#endif
