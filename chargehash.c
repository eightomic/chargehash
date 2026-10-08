#include <stddef.h>
#include <stdint.h>

uint32_t chargehash(uint8_t *key, size_t key_length, uint32_t seed) {
  uint32_t a = seed ^ 111111;
  uint32_t b = seed;
  size_t i = 0;

  while (i < key_length) {
    a = ((a << 13) | (a >> 19)) + b + key[i];
    b += a;
    i++;
  }

  a = ((a << 17) | (a >> 15)) + b;
  a += a << 7;
  b += a ^ (a >> 13);
  a += b ^ (b >> 5);
  b += (a + (a << 17)) ^ (a >> 9);
  return a + ((b + (b << 9)) ^ (b >> 3));
}
