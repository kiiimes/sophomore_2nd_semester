#ifndef MY_FUNC_H
#define MY_FUNC_H

#include "my_struct.h"
#include "my_define.h"

void insert(tel **plist,int *cnt,int max_n);
void show(tel **plist,int *cnt) ;
void del(tel **plist,int *cnt);
void find(tel **plist,int *cnt);
void Regfromfile(int *cnt,tel **plist);
void end(tel **plist,int *cnt);
void chofind(tel **plist,int *cnt);

#endif