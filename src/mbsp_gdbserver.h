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
#ifndef MBSP_GDBSERVER_H_
#define MBSP_GDBSERVER_H_

#include <stdint.h>
#include <stdbool.h>

void tcp_send_string(char* msg);
uint32_t tcp_get_num_received_bytes(void);
uint8_t tcp_get_next_received_byte(void);
uint32_t tcp_send_bytes(uint8_t *data, uint32_t length);

#endif /* MBSP_GDBSERVER_H_ */
