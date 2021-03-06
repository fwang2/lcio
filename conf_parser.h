//
// Created by Matthew Bachstein on 5/23/18.
//

#ifndef LCIO_CONF_PARSER_H
#define LCIO_CONF_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

struct attr {
    char* key;
    char* val;
};

struct section {
    int num;
    char* key;
    struct attr **attrs;
};

struct conf {
    int num;
    char* file_name;
    struct section** sections;
};


struct conf* parse_conf_file(char *);
void print_cfg(struct conf*);
struct section* get_section(char*, struct conf*);
char* get_attr(char* key, struct section* sec);
char** get_keys(struct section* sec);

#endif //LCIO_CONF_PARSER_H
