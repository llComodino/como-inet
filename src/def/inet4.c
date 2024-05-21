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

IPv4* inet4_addr(uint8_t octet_one, uint8_t octet_two, uint8_t octet_three, uint8_t octet_four) {

  IPv4 *addr = NULL;
  if ( (addr = (IPv4 *) malloc(sizeof(IPv4)) ) == NULL) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  addr->data[0] = octet_one;
  addr->data[1] = octet_two;
  addr->data[2] = octet_three;
  addr->data[3] = octet_four;

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

void print_header(IPv4Header *header) {
  printf(

      "v: %d\n" 
      "tos: %d\n"
      "ttl: %d\n"
      "src: %d\n"
      "dst: %x\n"
      "checksum: %x\n"
      "proto: %x\n"
      "len: %x\n"
      "fl_frag: %x\n"
      "id: %x\n",

          header->inet_v,
          header->tos,
          header->ttl,
          header->src_ip,
          header->dest_ip,
          header->checksum,
          header->protocol,
          header->total_length,
          header->flags_fragment,
          header->identification
    );

  return;
}
