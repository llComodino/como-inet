/*
 * inet4 src - contains the ipv4 definition along with it's header
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
#include "../../lib/inet4.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

IPv4* inet4_addr(uint8_t *octects) {

  IPv4 *addr = NULL;
  if ( (addr = (IPv4 *) malloc(sizeof(IPv4)) ) == NULL) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  for (size_t i = 0; i < INET4_OCTETS; i++) {
    addr->data[i] = *(octects + i);
  }

  return addr;
}

IPv4Header* inet4_header(IPv4 *src_addr, IPv4 *dst_addr, uint64_t *data) {

  IPv4Header *header = NULL;

  if ( (header = (IPv4Header *) malloc(sizeof(IPv4Header)) ) == NULL) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  header->inet_v          = INET4_V;
  header->tos             = 0x68;
  header->ttl             = 104;
  header->src_ip          = src_addr->ip;
  header->dest_ip         = dst_addr->ip;
  header->checksum        = 0;
  header->protocol        = 0;
  header->total_length    = sizeof(*data);
  header->flags_fragment  = 0;
  header->identification  = 0;

  return header;
}

void print_inet4_header(IPv4Header *header) {

  IPv4 inet4_src;
  inet4_src.ip = header->src_ip;

  IPv4 inet4_dest;
  inet4_dest.ip = header->dest_ip;

  printf(

      "v: %d\n" 
      "tos: %d\n"
      "ttl: %d\n"
      "src: %d.%d.%d.%d\n"
      "dst: %d.%d.%d.%d\n"
      "checksum: %x\n"
      "proto: %x\n"
      "len: %x\n"
      "fl_frag: %x\n"
      "id: %x\n",

          header->inet_v,
          header->tos,
          header->ttl,
          inet4_src.data[0],
          inet4_src.data[1],
          inet4_src.data[2],
          inet4_src.data[3],
          inet4_dest.data[0],
          inet4_dest.data[1],
          inet4_dest.data[2],
          inet4_dest.data[3],
          header->checksum,
          header->protocol,
          header->total_length,
          header->flags_fragment,
          header->identification
    );

  return;
}
