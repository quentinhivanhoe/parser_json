/*
** EPITECH PROJECT, 2024
** json parser
** File description:
** simple json parser in c
*/

#ifndef JSON_H_
    #define JSON_H_

typedef enum node_type {
    JSON,
    ARRAY,
    STR,
    INT,
    BOOL,
}node_t;

typedef struct array_s {
    node_t type;
    long int int_value;
    char *str_value;
    bool bool_value;
} array_t;

typedef struct json_s {
    node_t type;
    long int int_value;
    char *str_value;
    bool bool_value;
    array_t *array_value;
    json_t *json_value;
} json_t;


#endif /* !JSON_H_ */
