#ifndef GDBSERVER_CFG_H_
#define GDBSERVER_CFG_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mbsp_gdbserver.h"

#define MAX_LINE_LENGTH    500
#define MAX_REPLY_LENGTH   100

#define DEBUG_LOG                        printf
#define GDBSERVER_SEND_STRING            tcp_send_string
#define GDBSERVER_SEND_BYTES             tcp_send_bytes
#define GDBSERVER_NUM_RECEIVED_BYTES     tcp_get_num_received_bytes
#define GDBSERVER_GET_NEXT_RECEIVED_BYTE tcp_get_next_received_byte

#endif /* GDBSERVER_CFG_H_ */
