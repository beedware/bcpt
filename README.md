# Beed's Competitive Programming Training

This is my personal repository for practicing competitive programming and
maintaining reusable templates for contests. I use it to work through problems,
revisit algorithms and data structures, and refine my contest setup as I learn.

## Supported Languages

The Nix development shell (`nix develop`) provides these languages and toolchains:

| Language    | Toolchain                   | Version-specific documentation                                         |
| ----------- | --------------------------- | ---------------------------------------------------------------------- |
| C23         | GCC 16.2.0 (`-std=gnu23`)   | [C23 reference](https://en.cppreference.com/w/c/23.html)               |
| C++23       | GCC 16.2.0 (`-std=gnu++23`) | [C++23 reference](https://en.cppreference.com/w/cpp/23.html)           |
| Java 21     | JDK 21.0.13.0.2+1           | [Java SE 21 documentation](https://docs.oracle.com/en/java/javase/21/) |
| Python 3.11 | PyPy 7.3.20                 | [Python 3.11 documentation](https://docs.python.org/3.11/)             |

## Running Tests

From a directory using one of the template Makefiles:

- `make run 1` runs the program with `in/1` as input and prints its output.
- `make validate 1` runs the same test and compares its output exactly to `out/1`,
  showing a diff and failing if they differ.
- Both numbered commands save stderr to `err/1`, replacing the previous log.
  `make run` without a number still reads from standard input.

## References

- [KACTL (KTH Algorithm Competition Template Library)](https://github.com/kth-competitive-programming/kactl/blob/main/kactl.pdf)
- [Competitive Programmer's Handbook by Antti Laaksonen](https://cses.fi/book/book.pdf)
