/*
 * inet6 header - contains the ipv4 declaration and it's header
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
#ifndef INET6_H
#define INET6_H

#include <stdint.h>

#define INET6_V         0b0110 // inet6 version
#define INET6_HEXTETS   8
#define INET6_BYTES     16


// Using a union to preserve memory
typedef union {
    uint8_t  data[INET6_BYTES];   /* 128-bit IPv6 address represented 
                                     as an array of 16 bytes */
    uint16_t words[INET6_HEXTETS];            /* 128-bit IPv6 address represented
                                     as an array of 8 16-bit words */
} IPv6;

typedef struct {
    uint32_t version_traffic_flow;      /* Version (4 bits)
                                           + Traffic Class (8 bits)
                                           + Flow Label (20 bits) */
    uint8_t  inet_v;                    // inet version
    uint16_t payload_length;            // Payload Length
    uint8_t  next_header;               // Next Header
    uint8_t  hop_limit;                 // Hop Limit
    uint16_t src_ip[INET6_HEXTETS];     // Source IP Address
    uint16_t dest_ip[INET6_HEXTETS];    // Destination IP Address
} IPv6Header;


IPv6* inet6_addr(uint16_t *hextets);
IPv6Header *inet6_header(IPv6 *src_addr, IPv6 *dst_addr, uint64_t *data);
void print_inet6_header(IPv6Header *header);

#endif  // INET6_H
