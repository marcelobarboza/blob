# Deployment Instructions

After installing dependencies (see [External Dependencies][1]) and configuring
your database (see [Database Configuring][2]) it's time to download, configure,
build and run **Blob**.

### Download

To download it type

```Shell
git clone https://github.com/marcelobarboza/blob ~/Projects/blob
```

on the command line.

### Configure

Get into the project's folder

```Shell
cd ~/Projects/blob
```

and have a look at the holidays list within `main.c`. Despite its name, holidays
is a list of non working days that **Blob** will totally skip.

**Blob**'s default PostgreSQL database is called teaching. You can change it to
your liking in the scope of the cron function in `src/blob.c`.

### Build

Build instructions can be found in the `makefile`. If you have the [GNU Make][3]
at your disposal, just type

```Shell
make
```

at the command prompt.

### Run

Schedule classes like this:

```Shell
./blob.o -t TABLE -y YEAR -m MONTH -d DAY -b BLOB
```

where

1. TABLE is a table from **Blob**'s PostgreSQL database;
2. YEAR is an integer, 1 <= YEAR <= 58795 (due to the word size implementation);
3. MONTH is an integer, 1 <= MONTH <= 12;
4. DAY is an integer, 1 <= DAY <= 31;
5. BLOB is an integer, 1 <= BLOB <= 7.

Also, date `YEAR/MONTH/DAY` must be a valid date since it's meant to be the
first day of classes. **Blob** will then prompt you for blob data (see
[Project's Name][1]). That's it, your schedule is in `cron.md`.

[1]: blob.md
[2]: database.md
[3]: https://www.gnu.org/software/make/
