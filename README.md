# ChargeHash

[![ChargeHash](chargehash.jpg)](https://github.com/eightomic/chargehash)

ChargeHash (as a proprietary, source-available product of [Eightomic](https://eightomic.com)) is the fast constrained 32-bit OAAT (non-cryptographic) that has "one-at-a-time" byte copying with a single byte hashed in each loop iteration, excellent non-cryptographic 32-bit output quality (passed 32-bit SMHasher3 `--extra` tests), excellent non-cryptographic security properties (light resistance against both HashDoS and length-extension attacks), low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators and ultra-fast speed (relative to the aforementioned constraints).

ChargeHash is implemented in C (requiring the `stdint.h` header to define unsigned integral types for both an 8-bit `uint8_t` and a 32-bit `uint32_t`).

[chargehash.c](chargehash.c)

The `chargehash` function uses a `uint32_t` `seed` integer to hash a `key` array of `key_length` `uint8_t` integers and return a `uint32_t` digest.

Each of the following results log the fastest process execution speed (in milliseconds) among several repetitions of a speed benchmark (with `gcc -O0` from an AMD A4-9120C) that hashes 1 million `key_length` pseudorandom keys in a blocking `#pragma GCC unroll 0 loop`.

```
key_length   Elapsed        Elapsed
             (chargehash)   (goodoaat)

1            35ms           49ms
2            48ms           58ms
3            51ms           71ms
4            59ms           84ms
5            66ms           96ms
6            76ms           110ms
7            81ms           123ms
8            88ms           135ms
12           109ms          188ms
16           146ms          238ms
32           254ms          447ms
64           484ms          850ms
128          862ms          1780ms
256          1668ms         3378ms
```
