/*
 * Copyright © 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Ted Gould <ted@canonical.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define BUFFER_SIZE  256

int
main (int argc, char * argv[])
{
	int socket_fd = 0;
	int servlen = 0;
	struct sockaddr_un serv_addr;

	bzero((char *)&serv_addr, sizeof(serv_addr));

	const char * home = getenv("HOME");
	if (home == NULL) {
		return -1;
	}

	serv_addr.sun_family = AF_UNIX;
	snprintf(serv_addr.sun_path, sizeof(serv_addr.sun_path), "%s/%s", home, ".freerdp-socket");
	servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

	if ((socket_fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		return -1;
	}

	if (connect(socket_fd, (struct sockaddr *)&serv_addr, servlen) < 0) {
		return -1;
	}

	char buffer[BUFFER_SIZE + 2];
	int in = 0;
	int out = 0;

	in = read(socket_fd, buffer, BUFFER_SIZE);
	out = write(1, buffer, in);

	close(socket_fd);

	if (in == 0) {
		return 0;
	} else {
		return -1;
	}
}

