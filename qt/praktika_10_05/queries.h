#ifndef QUERIES_H
#define QUERIES_H

#define SUBJECTS "create table Subjects(\
id integer primary key autoincrement,\
sub_name text unique\
)"

#define QUESTIONS "create table Questions(\
id integer primary key autoincrement,\
content text,\
difficulty_id integer,\
subject_id integer,\
foreign key (subject_id) references Subject(id)\
)"

#define MIN_QUERIES "SELECT min(f1) from (SELECT count(*) as f1 from Questions GROUP by difficulty_id)"


#endif // QUERIES_H
