/*
  Copyright © 2026 Eightomic <eightomic@proton.me>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <stddef.h>
#include <stdint.h>

uint32_t chargehash32x1x1(uint8_t *key, size_t key_length, uint32_t seed) {
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

uint32_t chargehash32x4x1(uint8_t *key, size_t key_length, uint32_t seed) {
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
