### Days Of The Week

Days of the week are numbered like this:

> sun: 0, mon: 1, tue: 2, wed: 3, thu: 4, fri: 5, sat: 6.

Also, to increase readability the following variable type has been created:

```C
typedef enum {sun, mon, tue, wed, thu, fri, sat} wday_t;
```

### Blob

The concept of a blob is a very simple one. A blob is a variable of type

```C
typedef struct {
  wday_t wday;
  int qty;
} blob_t;
```

A declaration like

```C
blob_t blob = {wed, 2};
```

states that you have 2 classes of something every Wednesday (for how long is
something determined by your databases. See [Database Configuration][1]).
Instead, the blob declaration

```C
blob_t blob[2] = {{tue, 3}, {thu,2}};
```

means that you have 3 classes of something every Tuesday and another 2 of the
same thing every Thursday. The maximum length of an array of blob_t type is, of
course, delimited by the number of days in a week.

### Project's Name

The reason this project was named after variables of type blob_t are:

- we like it;
- it's a compact and easy to remember name;
- the lack of a better name.

[1]: database.md
