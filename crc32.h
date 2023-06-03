#include<stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// calculate a checksum on a buffer -- start address = p, length = bytelength
extern uint32_t crc32_byte(uint8_t *p, uint32_t bytelength);
extern uint32_t crc32_byte_continue(uint32_t prev, uint8_t *p, uint32_t bytelength);

//Fill the lookup table -- table = the lookup table base address
extern void crc32_fill(uint32_t *table);

extern uint32_t poly8_lookup[256];

#ifdef __cplusplus
}
#endif
