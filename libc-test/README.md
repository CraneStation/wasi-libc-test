This is an adaption of the [libc-test] testsuite for use in testing
WASI libc.

This code is based on libc-test revision
b55b931794bff9e88a3443daa8404c74f7f1d17c from
git://repo.or.cz/libc-test.

Changes to upstream code are wrapped in preprocessor directives controlled
by the macro `__wasilibc_unmodified_upstream`.

There is a simple test.sh file for running the tests and comparing
the results with expected outcomes.

[libc-test]: https://wiki.musl-libc.org/libc-test.html
