### External Dependencies

In order to build **Blob** you'll need:

- a working C compiler like, for example, [GCC][1].
- the [PostgreSQL][3] database and it's [C Library][4];

I've been asking myself if I really should write any distro specific commands
down here since **Blob** isn't distro oriented and not everyone uses the same
distro anyway. Although I'd rather not, doing so might help someone out there.
So please take this section as an example of how I got set up with [Debian
GNU/Linux][5], which is my Linux distro of choice.

##### GCC

Install it with

```Shell
sudo apt install glibc-doc glibc-doc-reference build-essential
```

This will install a bunch of stuff into your system, like man pages for various
C libraries, GCC itself, the [GNU Make][2] and many, many others but not before
asking for your permission.

##### PostgreSQL

Install it with

```Shell
sudo apt install postgresql postgresq-client
```

In case you need some help on getting your database up and running, take a look
at [this][6] page. Again, if you're running an OS other that Debian, then you
should look up for an appropriate reference.

Finally, install PostgreSQL's C Library with

```Shell
sudo apt install libpq-dev
```

[1]: https://gcc.gnu.org
[2]: https://gnu.org/software/make
[3]: https://postgresql.org
[4]: https://www.postgresql.org/docs/current/libpq.html
[5]: https://debian.org
[6]: https://wiki.debian.org/PostgreSql
