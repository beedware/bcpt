# Beed's Competitive Programming Training

This is my personal repository for practicing competitive programming and
maintaining reusable templates for contests. I use it to work through problems,
revisit algorithms and data structures, and refine my contest setup as I learn.

## Practice Solutions

Keep solutions under platform or contest folders, such as `cses/1069/` or
`codeforces/<round>/<problem>/`. Outside `cpp/`, Git picks up only `main.cpp`,
`main.py`, `Main.java`, and `main.c` in these folders, even when they are nested.
Build tools live in `cpp/`; local binaries, samples, and scratch files are ignored.

```sh
make -C cses/1069 -f ../../cpp/Makefile build
make -C cses/1069 -f ../../cpp/Makefile run < sample.in
```

To start a new problem, create its directory and copy in `cpp/main.cpp`.

## Supported Languages

The Nix development shell (`nix develop`) provides these languages and toolchains:

| Language    | Toolchain                   | Version-specific documentation                                         |
| ----------- | --------------------------- | ---------------------------------------------------------------------- |
| C23         | GCC 16.2.0 (`-std=gnu23`)   | [C23 reference](https://en.cppreference.com/w/c/23.html)               |
| C++23       | GCC 16.2.0 (`-std=gnu++23`) | [C++23 reference](https://en.cppreference.com/w/cpp/23.html)           |
| Java 21     | JDK 21.0.13.0.2+1           | [Java SE 21 documentation](https://docs.oracle.com/en/java/javase/21/) |
| Python 3.11 | PyPy 7.3.20                 | [Python 3.11 documentation](https://docs.python.org/3.11/)             |

## References

- [KACTL (KTH Algorithm Competition Template Library)](https://github.com/kth-competitive-programming/kactl/blob/main/kactl.pdf)
- [Competitive Programmer's Handbook by Antti Laaksonen](https://cses.fi/book/book.pdf)
