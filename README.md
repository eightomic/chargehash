# ChargeHash

[![ChargeHash](chargehash.jpg)](https://github.com/eightomic/chargehash)

ChargeHash (as a proprietary, source-available product of [Eightomic](https://eightomic.com)) is the fast efficient string hash (non-cryptographic) that has excellent non-cryptographic output quality (passed SMHasher3 `--extra` tests), excellent non-cryptographic security properties (light resistance against both HashDoS and length-extension attacks), low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators and ultra-fast speed (relative to the aforementioned constraints).

Each mention of ChargeHash refers to each of the following 30 variants individually (`chargehash32x1x1`, `chargehash32x4x1`, `chargehash32x8x1`, `chargehash32x12x1`, `chargehash32x16x1`, `chargehash32x1x2`, `chargehash32x4x2`, `chargehash32x8x2`, `chargehash32x12x2`, `chargehash32x16x2`, `chargehash32x1x4`, `chargehash32x4x4`, `chargehash32x8x4`, `chargehash32x12x4`, `chargehash32x16x4`, `chargehash64x1x1`, `chargehash64x4x1`, `chargehash64x8x1`, `chargehash64x12x1`, `chargehash64x16x1`, `chargehash64x1x2`, `chargehash64x4x2`, `chargehash64x8x2`, `chargehash64x12x2`, `chargehash64x16x2`, `chargehash64x1x4`, `chargehash64x4x4`, `chargehash64x8x4`, `chargehash64x12x4` and `chargehash64x16x4`) implemented in C (requiring the `stdint.h` header to define unsigned integral types for an 8-bit `uint8_t`, a 32-bit `uint32_t` and a 64-bit `uint64_t`).

The byte-copying alignment in each ChargeHash implementation must be consistent to the byte-copying alignment in each replaced hash function implementation.

[chargehash.c](chargehash.c)

Each of the following speed benchmark results (with `gcc` from an AMD A4-9120C) log the fastest process execution speed (in milliseconds) among several repetitions of hashing 1 million `key_length` pseudorandom keys in a blocking loop.

The `chargehash32x1x1` function uses a `uint32_t` `seed` integer to hash a `key` array of `key_length` `uint8_t` integers (with a `uint8_t` byte hashed in each loop iteration) and return a `uint32_t` digest.

```
key_length   Elapsed              Elapsed
             (chargehash32x1x1)   (goodoaat)

1            35ms                 49ms
2            48ms                 58ms
3            51ms                 71ms
4            59ms                 84ms
5            66ms                 96ms
6            76ms                 110ms
7            81ms                 123ms
8            88ms                 135ms
12           109ms                188ms
16           146ms                238ms
32           254ms                447ms
64           484ms                850ms
128          862ms                1780ms
256          1668ms               3378ms
```

The `chargehash32x4x1` function uses a `uint32_t` `seed` integer to hash a `key` array of `key_length` `uint8_t` integers (with 4 `uint8_t` bytes hashed in each loop iteration) and return a `uint32_t` digest.

```
key_length   Elapsed              Elapsed
             (chargehash32x4x1)   (murmur3a)

1            34ms                 40ms
2            37ms                 40ms
3            38ms                 46ms
4            48ms                 48ms
5            48ms                 56ms
6            51ms                 51ms
7            49ms                 51ms
8            53ms                 75ms
12           62ms                 85ms
16           71ms                 91ms
32           107ms                126ms
64           181ms                196ms
128          322ms                354ms
256          626ms                784ms
```

`chargehash32x8x1`, `chargehash32x12x1`, `chargehash32x16x1`, `chargehash32x1x2`, `chargehash32x4x2`, `chargehash32x8x2`, `chargehash32x12x2`, `chargehash32x16x2`, `chargehash32x1x4`, `chargehash32x4x4`, `chargehash32x8x4`, `chargehash32x12x4`, `chargehash32x16x4`, `chargehash64x1x1`, `chargehash64x4x1`, `chargehash64x8x1`, `chargehash64x12x1`, `chargehash64x16x1`, `chargehash64x1x2`, `chargehash64x4x2`, `chargehash64x8x2`, `chargehash64x12x2`, `chargehash64x16x2`, `chargehash64x1x4`, `chargehash64x4x4`, `chargehash64x8x4`, `chargehash64x12x4` and `chargehash64x16x4` aren't ready to publish yet.
