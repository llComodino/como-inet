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
#include "../lib/inet4.h"
#include "../lib/inet6.h"
#include "../lib/packet.h"

int main (int argc, char *argv[]) {

  // inet4 addresses initialized with hex values
  uint8_t inet4_src_octects[INET4_OCTETS] = { 0x68, 0x68, 0x68, 0x68 };
  uint8_t inet4_dst_octets[INET4_OCTETS] = { 0x69, 0x69, 0x69, 0x69 };
  
  // inet6 addresses initialized with hex values
  uint16_t inet6_src_hextets[INET6_HEXTETS] = { 0x68AB, 0x68AB, 0x68AB, 0x68AB,
                                                0x68AB, 0x68AB, 0x68AB, 0x68AB };

  uint16_t inet6_dst_hextets[INET6_HEXTETS] = { 0x68CD, 0x68CD, 0x68CD, 0x68CD,
                                                0x68CD, 0x68CD, 0x68CD, 0x68CD };

  IPv4 *inet4_src = inet4_addr(inet4_src_octects);
  IPv4 *inet4_dst = inet4_addr(inet4_dst_octets);

  IPv6 *inet6_src = inet6_addr(inet6_src_hextets);
  IPv6 *inet6_dst = inet6_addr(inet6_dst_hextets);

  uint64_t data[MAX_DATA_SEGMENTS] = { 0x100, 0x101, 0x102, 0x103 };

  Packet *inet4_packet = new_inet4_packet(inet4_src, inet4_dst, data);
  Packet *inet6_packet = new_inet6_packet(inet6_src, inet6_dst, data);

  print_inet6_header(inet6_packet->inet6_header);
  print_inet4_header(inet4_packet->inet4_header);

  return 0;
}
