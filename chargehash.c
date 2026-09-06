#include <stddef.h>
#include <stdint.h>

uint32_t chargehash1x32_small(uint8_t *key, size_t key_length, uint32_t seed) {
  uint8_t key_remainder_length = key_length & 3;
  uint32_t a = seed;
  uint32_t b = seed ^ 11111111;
  size_t i = 0;

  key_length -= key_remainder_length;

  while (i < key_length) {
    a += ((a << 15) | (a >> 17)) + b + (
      key[i]
        | (((uint32_t)(key[i + 1])) << 8)
        | (((uint32_t)(key[i + 2])) << 16)
        | (((uint32_t)(key[i + 3])) << 24)
    );
    b += ((b << 13) | (b >> 19)) + a;
    i += 4;
  }

  switch (key_remainder_length) {
    case 3:
      a += (
        key[i]
          | (((uint32_t)(key[i + 1])) << 8)
          | (((uint32_t)(key[i + 2])) << 16)
      ) + 111;
      break;
    case 2:
      a += (
        key[i]
          | (((uint32_t)(key[i + 1])) << 8)
      ) + 111111;
      break;
    case 1:
      a += key[i] + 111111111;
  }

  a += ((a << 17) | (a >> 15)) + (a << 5) + (b ^ (b >> 5));
  a += a << 7;
  b += a ^ (a >> 13);
  a += b ^ (b >> 5);
  b += (a + (a << 17)) ^ (a >> 9);
  return a + ((b + (b << 9)) ^ (b >> 5));
}
