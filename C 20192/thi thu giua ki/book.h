#ifndef _BOOK_H_
#define _BOOK_H_

struct BookNode {
	char id[10];
	char title[50];
	char author[20];
	int year;
	struct BookNode *next;
};
typedef struct BookNode *BookDB;
typedef struct BookNode *book;
int n;
BookDB db;

BookDB read_db(char* filename);

BookDB write_db(char* filename);

struct BookNode* make_node(char *id, char *title, char *author, int year);

BookDB append(BookDB db, struct BookNode *b);

struct BookNode *find_by_id(BookDB db, char *id);

BookDB removeBook(BookDB db, char *id);

BookDB swap(BookDB db, struct BookNode *b1, struct BookNode *b2);

book last(BookDB db);
/* In thông tin cu?n sách */
void print_book(struct BookNode *b);
/* In danh sách các cu?n sách */
#endif
