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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "gdbserver/gdbserver.h"
#include "mbsp_gdbserver.h"

#define PORT         54321
#define BUFFER_SIZE  256

// target remote :54321
// target extended-remote :54321

static int client_fd;
static uint32_t receivedLength = 0;
static char buffer[BUFFER_SIZE];
static uint32_t recv_pos;

void tcp_send_string(char* msg)
{
    int length = strlen(msg);
    send(client_fd, msg, length, 0);
}

uint32_t tcp_get_num_received_bytes(void)
{
    return receivedLength;
}

uint8_t tcp_get_next_received_byte(void)
{
    if(recv_pos < BUFFER_SIZE)
    {
        uint8_t res = buffer[recv_pos];
        recv_pos++;
        receivedLength--;
        return res;
    }
    else
    {
        return 0;
    }
}

uint32_t tcp_send_bytes(uint8_t *data, uint32_t length)
{
    send(client_fd, data, length, 0);
    return length;
}

void err_exit(char* message)
{
    perror(message);
    exit(1);
}

int main(int argc, char* argv[])
{
    int sock_fd;
    int err;
    int length;
    socklen_t addr_size;
    struct sockaddr_in my_addr;
    struct sockaddr_in client_addr;
    fd_set input_fdset;

    gdbserver_init();

    sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1)
    {
        err_exit("can't create new socket");
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    err = bind(sock_fd, (struct sockaddr*) &my_addr, sizeof(struct sockaddr_in));
    if(err == -1)
    {
        err_exit("bind failed");
    }

    err = listen(sock_fd, 1);
    if(err == -1)
    {
        err_exit("listen failed");
    }
    printf("Listening on port %d\r\n", PORT);

    addr_size = sizeof(struct sockaddr_in);
    client_fd = accept(sock_fd, (struct sockaddr*) &client_fd, &addr_size);
    if(err == -1)
    {
        err_exit("accept failed");
    }

    printf("connected from %s\n", inet_ntoa(client_addr.sin_addr));

    while(1)
    {
        FD_ZERO(&input_fdset);
        FD_SET(STDIN_FILENO, &input_fdset);
        FD_SET(client_fd, &input_fdset);
        if(-1 == select(client_fd + 1, &input_fdset, NULL, NULL, NULL))
        {
            close(client_fd);
            close(sock_fd);
            err_exit("accept failed");
        }
        if(FD_ISSET(STDIN_FILENO, &input_fdset))
        {
            if(fgets(buffer, BUFFER_SIZE, stdin) == NULL)
            {
                printf("\nclosing socket\n");
                break;
            }
            length = strlen(buffer);
            send(client_fd, buffer, length, 0);
        }
        else
        {
            receivedLength = recv(client_fd, buffer, BUFFER_SIZE, 0);
            recv_pos = 0;
            if(receivedLength == 0)
            {
                printf("\nconnection closed by remote host\n");
                break;
            }
            // write(STDOUT_FILENO, buffer, length);
            while(0 != receivedLength)
            {
                gdbserver_tick();
            }
        }
    }

    close(client_fd);
    close(sock_fd);
    printf("\nDone!\n");
	return 0;
}
