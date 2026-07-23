#include <stddef.h>
#include <stdint.h>

uint32_t chargehash32x1(uint8_t *key, size_t key_length, uint32_t seed) {
  uint8_t key_remainder_length = key_length & 3;
  uint32_t a = seed;
  uint32_t b = 11111111;
  size_t i = 0;

  key_length -= key_remainder_length;

  while (i < key_length) {
    a += key[i]
         | (((uint32_t)key[i + 1]) << 8)
         | (((uint32_t)key[i + 2]) << 16)
         | (((uint32_t)key[i + 3]) << 24);
    b += ((b << 13) | (b >> 19)) + ((a << 17) | (a >> 15));
    a += (a << 3) + b;
    i += 4;
  }

  switch (key_remainder_length) {
    case 3:
      a += key[i]
           | (((uint32_t)key[i + 1]) << 8)
           | (((uint32_t)key[i + 2]) << 16);
      b += 111;
      break;
    case 2:
      a += key[i]
           | (((uint32_t)key[i + 1]) << 8);
      b += 111111;
      break;
    case 1:
      a += key[i];
      b += 111111111;
  }

  b += seed + ((a << 17) | (a >> 15));
  a += key_length + (a << 3) + (b << 2) + b;
  a += (a << 25) | (a >> 7);
  a ^= a >> 5;
  b += seed + a;
  b += (b << 9) | (b >> 23);
  b ^= b >> 7;
  a += (a << 21) | (a >> 11);
  a ^= a >> 13;
  b += (b << 13) | (b >> 19);
  b ^= b >> 17;
  return a ^ b;
}
