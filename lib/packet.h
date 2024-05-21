/*
 * packet header - contains the ipv4 declaration and it's header
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
#ifndef PACKET_H
#define PACKET_H

// uint_x types
#include <stdint.h>
// inet definitions
#include "inet4.h"
#include "inet6.h"

// Create an enum to track which inet_v it's used for a packet
enum INET_V {
    INET4 = INET4_V, // inet4.h - 0b0100
    INET6 = INET6_V, // inet6.h - 0b0110
};


typedef struct {
  enum INET_V inet_v;
  uint64_t data[4];
  IPv4Header *inet4_header;
  IPv6Header *inet6_header;
} Packet;


Packet* new_inet4_packet(IPv4 *src_addr, IPv4 *dst_addr, uint64_t* data);
Packet* new_inet6_packet(IPv6 src_addr, IPv6 dst_addr, uint64_t* data);

#endif  // PACKET_H
