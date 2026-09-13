# Crimson

[![Ubuntu](https://github.com/AnmiTaliDev/ruby/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/AnmiTaliDev/ruby/actions/workflows/ubuntu.yml)

## About

Crimson is a fork of Ruby targeting unusual and alternative platforms.

## Dependencies

- C99 compiler (GCC, Clang, or platform C compiler)
- GNU Autoconf 2.67 or later
- GNU Bison 3.0 or later
- Ruby 3.1 or later
- Git 2.32 or later
- Optional: OpenSSL, libyaml, zlib, libffi, GMP

## Build

```sh
./autogen.sh
./configure
make
make test
```

## Platform Support

Crimson targets architectures and operating systems not supported by upstream Ruby.

## Acknowledgments

Crimson is based on the Ruby programming language developed by Yukihiro Matsumoto and the Ruby core team: https://github.com/ruby/ruby.

## Documentation and Contributing

- Documentation: [doc](doc/)
- Contributing guidelines: [CONTRIBUTING.md](CONTRIBUTING.md)
- Upstream documentation: https://docs.ruby-lang.org/

## License

See [COPYING](COPYING) and [BSDL](BSDL) for licensing terms.
