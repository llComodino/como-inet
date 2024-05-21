/*
 * como-inet - (possibly) dumb project to learn inet
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
#include <stdio.h>
#include "../lib/inet4.h"
#include "../lib/inet6.h"
#include "../lib/packet.h"

int main (int argc, char *argv[]) {

  IPv4 *inet4_src = inet4_addr(0x68, 0x68, 0x68, 0x68);
  IPv4 *inet4_dst = inet4_addr(0x69, 0x69, 0x69, 0x69);

  uint64_t data[4] = { 0x100, 0x101, 0x102, 0x103 };

  Packet *packet = new_inet4_packet(inet4_src, inet4_dst, data);

  printf("Inet version: %d\n\n", packet->inet_v);

  for (size_t i = 0; i < 4; i++) {
    printf("%lx", packet->data[i]);
  }

  puts("\nIPv4 Header:");

  print_header(packet->inet4_header);

  return 0;
}
