/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 */
#ifndef GDBSERVER_CFG_H_
#define GDBSERVER_CFG_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hal/debug_uart.h"
#include "mbsp_gdbserver.h"

#define MAX_COMMAND_LENGTH    1025
#define MAX_REPLY_LENGTH      2000

#define GDBSERVER_SEND_STRING            tcp_send_string
#define GDBSERVER_SEND_BYTES             tcp_send_bytes
#define GDBSERVER_NUM_RECEIVED_BYTES     tcp_get_num_received_bytes
#define GDBSERVER_GET_NEXT_RECEIVED_BYTE tcp_get_next_received_byte

#endif /* GDBSERVER_CFG_H_ */
