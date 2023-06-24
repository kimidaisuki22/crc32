#include "crc32/crc32_helper.h"
#include "crc32/crc32.h"
#include <fstream>
uint32_t crc_file(std::istream &in) {
  uint32_t crc = 0;
  char buf[1024];
  while (in) {
    in.read(buf, sizeof(buf));
    crc = crc32_byte_continue(crc, (uint8_t *)buf, in.gcount());
  }
  return crc;
}