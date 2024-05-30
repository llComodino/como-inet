/*
 * inet6 src - contains the ipv4 definition along with it's header
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
#include "../../lib/inet6.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

IPv6* inet6_addr(uint16_t *hextets) {

  IPv6 *addr = NULL;

  if ( (addr = (IPv6 *) malloc(sizeof(IPv6)) ) == NULL ) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  for (size_t i = 0; i < INET6_HEXTETS; i++) {
    addr->words[i] = *(hextets + i);
  }

  return addr;

}

IPv6Header* inet6_header(IPv6 *src_addr, IPv6 *dst_addr, uint64_t *data) {

  IPv6Header *header = NULL;

  if ( (header = (IPv6Header *) malloc(sizeof(IPv6Header)) ) == NULL) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  header->inet_v                = INET6_V;
  header->hop_limit             = 104;

  for (size_t i = 0; i < INET6_HEXTETS; i++) {
    header->src_ip[i] = src_addr->words[i];
    header->dest_ip[i] = dst_addr->words[i];
  }

  header->next_header           = 0x0;
  header->payload_length        = sizeof(*data);
  header->version_traffic_flow  = 0x68;

  return header;
}

void print_inet6_header(IPv6Header *header) {
  printf(
      "version: %d\n" 
      "hop limit: %d\n"
      "src: %x:%x:%x:%x:%x:%x:%x:%x\n"
      "src: %x:%x:%x:%x:%x:%x:%x:%x\n"
      "next header: %x\n"
      "payload len: %d\n"
      "vtf: %d\n\n",

          header->inet_v,
          header->hop_limit,
          *(header->src_ip + 0),
          *(header->src_ip + 1),
          *(header->src_ip + 2),
          *(header->src_ip + 3),
          *(header->src_ip + 4),
          *(header->src_ip + 5),
          *(header->src_ip + 6),
          *(header->src_ip + 7),
          *(header->dest_ip + 0),
          *(header->dest_ip + 1),
          *(header->dest_ip + 2),
          *(header->dest_ip + 3),
          *(header->dest_ip + 4),
          *(header->dest_ip + 5),
          *(header->dest_ip + 6),
          *(header->dest_ip + 7),
          header->next_header,
          header->payload_length,
          header->version_traffic_flow
    );

  return;
}
