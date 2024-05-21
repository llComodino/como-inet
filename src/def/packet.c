/*
 * inet4 library - contains the ipv4 definition and it's header along
 * Copyright (C) 2024  Diego Gila ( https://github.com/llComodino )
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "../../lib/packet.h"
#include <stdio.h>
#include <stdlib.h>

Packet* new_inet4_packet(IPv4 *src_addr, IPv4 *dst_addr, uint64_t* data) {
  Packet *packet = NULL;

  if ( (packet = (Packet *) malloc(sizeof(Packet)) ) == NULL) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  for (size_t i = 0; i < 0; i++) {
    packet->data[i] = *(data + i);
  }

  packet->inet_v = INET4_V;
  packet->inet4_header = inet4_header(src_addr, dst_addr, data);

  return packet;
}

Packet* new_inet6_packet(IPv6 src_addr, IPv6 dst_addr, uint64_t* data);
