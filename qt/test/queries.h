#ifndef QUERIES_H
#define QUERIES_H

#define COUNTRIES_TABLE "create table Countries(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
c_name TEXT UNIQUE\
)"

#define BRAND_TABLE "create table Brand(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
brand_name TEXT UNIQUE\
)"

#define SIZES_TABLE "create table Sizes(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
g_size TEXT UNIQUE\
)"


#define GOODS_TABLE "create table Goods(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
g_name TEXT,\
g_brand INTEGER,\
origin INTEGER,\
price REAL,\
FOREIGN KEY (g_brand) REFERENCES Brand (id),\
FOREIGN KEY (origin) REFERENCES Countries (id)\
)"


#define STORAGE_TABLE "create table Storage(\
id INTEGER PRIMARY KEY AUTOINCREMENT,\
goods INTEGER,\
g_size INTEGER,\
FOREIGN KEY (g_size) REFERENCES Sizes (g_size)\
FOREIGN KEY (goods) REFERENCES Goods (id)\
)"

#define SELECT_ALL_BRANDS "select id, brand_name from Brand"


#endif // QUERIES_H
