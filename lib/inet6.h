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
#ifndef INET6_H
#define INET6_H

#include <stdint.h>

#define INET6_V       0b0110 // inet6 version
#define INET6_BYTES   16


// Using a union to preserve memory
typedef union {
    uint8_t  data[16];  /* 128-bit IPv6 address represented 
                           as an array of 16 bytes */
    uint16_t words[8];  /* 128-bit IPv6 address represented
                           as an array of 8 16-bit words */
} IPv6;

typedef struct {
    uint32_t version_traffic_flow;  /* Version (4 bits)
                                       + Traffic Class (8 bits)
                                       + Flow Label (20 bits) */
    uint16_t payload_length;        // Payload Length
    uint8_t  next_header;           // Next Header
    uint8_t  hop_limit;             // Hop Limit
    uint8_t  src_ip[16];            // Source IP Address
    uint8_t  dest_ip[16];           // Destination IP Address
} IPv6Header;

#endif  // INET6_H
