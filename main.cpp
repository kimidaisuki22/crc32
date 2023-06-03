#include "crc32.h"
#include "crc32_helper.h"
#include <cassert>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  //   uint32_t poly8[256];
  //   crc32_fill(poly8);
  //   for (int i = 0; i < 256; i++)
  //     printf("%x ", poly8[i]);
  if (argc == 2) {
    std::ifstream in(argv[1]);
    if (!in) {
      std::cerr << "Can't open file " << argv[1] << std::endl;
      return 1;
    }
    uint32_t crc = crc_file(in);
    std::cout << "crc32 of " << argv[1] << " is 0X" << std::hex << crc
              << std::endl;
    return 0;
  }

  std::string s = "hello world";
  uint32_t crc = crc32_byte((uint8_t *)s.c_str(), s.length());
  std::cout << "crc32 of " << s << " is 0X" << std::hex << crc << std::endl;
  std::string s1 = "hello";
  std::string s2 = " world";
  uint32_t crc1 = crc32_byte((uint8_t *)s1.c_str(), s1.length());
  crc1 = crc32_byte_continue(crc1, (uint8_t *)s2.c_str(), s2.length());
  assert(crc == crc1);
  std::cout << "crc32 of " << s << " is 0X" << std::hex << crc1 << std::endl;

  return 0;
}
