#ifndef MBSP_GDBSERVER_H_
#define MBSP_GDBSERVER_H_

#include <stdint.h>
#include <stdbool.h>

void tcp_send_string(char* msg);
uint32_t tcp_get_num_received_bytes(void);
uint8_t tcp_get_next_received_byte(void);
uint32_t tcp_send_bytes(uint8_t *data, uint32_t length);

#endif /* MBSP_GDBSERVER_H_ */
