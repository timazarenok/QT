#ifndef QUERIES_H
#define QUERIES_H

#define Human "CREATE TABLE Human(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
h_name TEXT,\
h_sex INTEGER,\
FOREIGN KEY (h_sex) REFERENCES Sex(s_id)\
)"

#define Sex "CREATE TABLE Sex(\
s_id INTEGER PRIMARY KEY AUTOINCREMENT,\
s_name TEXT\
)"

#endif // QUERIES_H
