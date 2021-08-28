# Database Configuration

**Blob** needs a [PostgreSQL][1] database filled up with tables of class topics,
one for each course that you teach. Every such table should look like this:

```PostgreSQL
 Column |     Type     | Collation | Nullable | Default
--------+--------------+-----------+----------+---------
 no     | integer      |           | not null |
 topic  | character(L) |           | not null |
 qty    | integer      |           | not null |
```

where

- *no* is the ordinal number (**primary key**) used to identify *topic*;
- *topic* is a short description of the class topic itself;
- *qty* is the number of classes that you'll spend with *topic*.

[1]: https://postgresql.org
