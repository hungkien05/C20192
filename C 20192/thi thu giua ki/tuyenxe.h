#ifndef _TUYENXE_H_
#define _TUYENXE_H_

struct DiemDoNode{
	char id[10];
	int x,y;
	struct DiemDoNode *next;
}; 

struct TuyenXeNode{
	char id[10];
	int soDiemDo;
	struct DiemDoNode* dsDiemDo[10];
};

typedef struct DiemDoNode* DiemDo;
typedef struct DiemDoNode* DiemDoDB;
typedef struct TuyenXeNode* TuyenXe;
typedef struct TuyenXeNode* TuyenXeDB;
int ndd;
DiemDoDB dddb;
TuyenXeDB txdb;

DiemDoDB read_dddb(char *filename);
TuyenXeDB read_txdb(char *filename);

DiemDoDB append_dd(DiemDoDB dddb, DiemDo dd);
TuyenXeDB append_tx(TuyenXeDB txdb, TuyenXe tx);
DiemDo find_dd_by_id(DiemDoDB dddb, char *id);
DiemDo find_dd_by_coord(DiemDoDB dddb, int x, int y);
TuyenXe find_tx_by_id(TuyenXeDB txdb, char *id);
#endif

