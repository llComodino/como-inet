/*
 * inet4 header - contains the ipv4 declaration and it's header
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
#ifndef INET4_H
#define INET4_H

// Includind cstdint for uint_x types
#include <stdint.h>


#define INET4_V       0b0100 // inet4 version
#define INET4_BYTES   4


// Using a union to have both full 32 bit value and
// the single bytes values is the same memory location
typedef union {
  uint32_t ip;                // The 32 bit representetion
  uint8_t data[INET4_BYTES];  // This data array shares
                              // memory with the uint_32
} IPv4;


// Define the header
typedef struct {
  uint8_t  inet_v;          // Version (4 bits)
                            // + Internet Header Length (3 bits)
  uint8_t  tos;             // Type of Service
  uint16_t total_length;    // Total Length
  uint16_t identification;  // Identification
  uint16_t flags_fragment;  // Flags (3 bits) + Fragment Offset (13 bits)
  uint8_t  ttl;             // Time to Live
  uint8_t  protocol;        // Protocol
  uint16_t checksum;        // Header Checksum
  uint32_t src_ip;          // Source IP Address
  uint32_t dest_ip;         // Destination IP Address
} IPv4Header;


IPv4* inet4_addr(uint8_t octet_one, uint8_t octet_two, uint8_t octet_three, uint8_t octet_four);
IPv4Header* inet4_header(IPv4 *src_addr, IPv4 *dst_addr, uint64_t *data);
void print_header(IPv4Header *header);
 

#endif // INET4_H
