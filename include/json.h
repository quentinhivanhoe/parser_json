/*
** EPITECH PROJECT, 2024
** json parser
** File description:
** simple json parser in c
*/

#ifndef JSON_H_
    #define JSON_H_
    #include <stdbool.h>

typedef enum node_type {
    ERROR = -1,
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
    struct json_s *json_value;
    struct json_s *next;
    struct json_s *prev;
} json_t;

/// @brief get the type of the value of the key
/// @param str the key and the value
/// @return the type
node_t get_value_type(char *str);

/// @brief create node for js object
/// @param str the string of the json
/// @return json object
json_t *create_node(json_t *prev, char *str);

/// @brief if the value is type of `INT` so it will get the value
/// @param node the node to complete
/// @param str the json stringify
/// @return the current node
json_t *get_int_value(json_t *node, char **str);

/// @brief if the value is type of `BOOL` so it will get the value
/// @param node the node to complete
/// @param str the json stringify
/// @return the current node
json_t *get_bool_value(json_t *node, char **str);

/// @brief if the value is type of `STR` so it will get the value
/// @param node the node to complete
/// @param str the json stringify
/// @return the current node
json_t *get_str_value(json_t *node, char **str);

#endif /* !JSON_H_ */
