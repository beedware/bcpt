# Beed's Competitive Programming Training

This is my personal repository for practicing competitive programming and
maintaining reusable templates for contests. I use it to work through problems,
revisit algorithms and data structures, and refine my contest setup as I learn.

## Supported Languages

The Nix development shell (`nix develop`) provides these languages and toolchains:

| Language                                                                                           | Version-specific documentation                                         |
| -------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| [C23](https://gcc.gnu.org/gcc-16/)                                                                 | [C23 reference](https://en.cppreference.com/c)                         |
| [C++23](https://gcc.gnu.org/gcc-16/)                                                               | [C++23 reference](https://en.cppreference.com/cpp)                     |
| [Java 21](https://www.oracle.com/java/technologies/javase/jdk21-0-13-later-archive-downloads.html) | [Java SE 21 documentation](https://docs.oracle.com/en/java/javase/21/) |
| [Python 3.11](https://buildbot.pypy.org/pypy/)                                                     | [Python 3.11 documentation](https://docs.python.org/3.11/)             |

## Running Tests

From a directory using one of the template Makefiles:

- `make build` builds the program or checks Python syntax.
- `make run 1` reads from `in/1`. If `out/1` exists, it compares the output exactly,
  showing a highlighted diff and failing on a mismatch. Otherwise, it prints the
  program's output. Stderr is saved to `err/1`, replacing the previous log.
- `make run` without a number reads from standard input.

## References

- [KACTL (KTH Algorithm Competition Template Library)](https://github.com/kth-competitive-programming/kactl/blob/main/kactl.pdf)
- [Competitive Programmer's Handbook by Antti Laaksonen](https://cses.fi/book/book.pdf)
