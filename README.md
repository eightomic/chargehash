# ChargeHash

[![ChargeHash](chargehash.jpg)](https://github.com/eightomic/chargehash)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [Implementation](README.md?tab=readme-ov-file#implementation)

## Introduction

ChargeHash is the efficient non-cryptographic hash function (for hashing variable-length byte arrays to fixed-length outputs) that has endian-independent byte copying, excellent non-cryptographic output quality (passes SMHasher3 `--extra` tests), excellent non-cryptographic security properties (light resistance against both HashDoS and length-extension attacks), low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators and ultra-fast speed.

## Author

ChargeHash was created by William Stafford Parsons as a product of [Eightomic](https://eightomic.com).

## Implementation

Each mention of ChargeHash refers to each of the 20 following variants individually (`chargehash1x32_oaat`, `chargehash1x32_small`, `chargehash1x32_medium`, `chargehash1x32_large`, `chargehash2x32_oaat`, `chargehash2x32_small`, `chargehash2x32_medium`, `chargehash2x32_large`, `chargehash4x32_small`, `chargehash4x32_medium`, `chargehash4x32_large`, `chargehash1x64_oaat`, `chargehash1x64_small`, `chargehash1x64_medium`, `chargehash1x64_large`, `chargehash2x64_oaat`, `chargehash2x64_small`, `chargehash2x64_medium`, `chargehash2x64_large`, `chargehash4x64_small`, `chargehash4x64_medium` and `chargehash4x64_large`) implemented in C (requiring the `stdint.h` header to define an 8-bit, unsigned integral type for `uint8_t`, a 32-bit, unsigned integral type for `uint32_t` and a 64-bit, unsigned integral type for `uint64_t`).

[chargehash.c](chargehash.c)

The byte-copying method (byte-by-byte, `memcpy` or unaligned pointer casting) in each ChargeHash implementation must be consistent to the byte-copying method in each replaced hash function implementation.

#### 32-Bit

The `chargehash1x32_small` function uses a `uint32_t` `seed` integer to hash a `key` array of `key_length` `uint8_t` integers and return a `uint32_t` digest.

`chargehash1x32_oaat`, `chargehash1x32_medium`, `chargehash1x32_large`, `chargehash2x32_oaat`, `chargehash2x32_small`, `chargehash2x32_medium`, `chargehash2x32_large`, `chargehash4x32_small`, `chargehash4x32_medium` and `chargehash4x32_large` aren't ready to publish yet.

#### 64-Bit

`chargehash1x64_oaat`, `chargehash1x64_small`, `chargehash1x64_medium`, `chargehash1x64_large`, `chargehash2x64_oaat`, `chargehash2x64_small`, `chargehash2x64_medium`, `chargehash2x64_large`, `chargehash4x64_small`, `chargehash4x64_medium` and `chargehash4x64_large` aren't ready to publish yet.
