# ChargeHash

[![ChargeHash](chargehash.jpg)](https://github.com/eightomic/chargehash)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Implementation](README.md?tab=readme-ov-file#implementation)
- [Speed](README.md?tab=readme-ov-file#speed)

## Introduction

ChargeHash is the hyper-efficient Murmur3 that has endian-independent memory reading, excellent non-cryptographic output quality, excellent non-cryptographic security properties (light resistance against HashDoS and length-extension attacks), hyper-fast speed and low-footprint implementation.

## Author

ChargeHash was created by William Stafford Parsons as a product of [Eightomic](https://eightomic.com).

## License

ChargeHash uses a [proprietary license](LICENSE).

## Implementation

ChargeHash is implemented in C (requiring the `stdint.h` header to define an 8-bit, unsigned integral type for `uint8_t` and a 32-bit, unsigned integral type for `uint32_t`).

[chargehash.c](chargehash.c)

The `chargehash32x1` function uses a `uint32_t` `seed` integer to hash a `key` array of `key_length` `uint8_t` integers and return a `uint32_t` digest.

## Speed

#### 32-bit

Each of the following results log the fastest process execution speed (in cycles per operation) among several repetitions of the `Init` `std::unordered_map` speed benchmark from SMHasher3 `Hashmap` speed tests (using default `cmake` compiler settings from an AMD A4-9120C).

| Hash Function | Cycles | SMHasher3 `--extra` Failures |
| --- | --- | --- |
| **`chargehash32x1`** | **957.242** | **0** |
| `murmur3a` | 1010.093 | 82 |
