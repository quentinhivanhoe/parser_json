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
    int int_value;
    char *str_value;
    bool bool_value;
} array_t;

typedef struct json_s {
    int depth;
    char *key;
    node_t type;
    long int int_value;
    char *str_value;
    bool bool_value;
    array_t **array_value;
    struct json_s *json_value;
    struct json_s *next;
    struct json_s *prev;
} json_t;

typedef struct get_value_s {
    node_t type;
    json_t *(*get_func) (json_t *, char **);
} get_value_t;

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

/// @brief if the value is type of `ARRAY` so it will get the value
/// @param node the nod eto complete
/// @param str the json stringify
/// @return the current node
json_t *get_array_value(json_t *node, char **str);

/// @brief nklsqcnl c
/// @param str c,ncsn,;cdns
/// @param nb_value ,klcldq,ldc
/// @param index njljqcnckl
/// @return nknlcdnlkcds,
array_t *create_array(char **str, int nb_value, int index);

/// @brief ahjajhjdnjnjkns
/// @param json ,qdcsncdslkndcsjkndscjk
void pretty_printer_test(json_t *json);

/// @brief d
/// @param node d
/// @param str d
/// @return d
json_t *get_json_value(json_t *node, char **str);

/// @brief print info about the json object
/// @param json the json object
void print_info(json_t *json);

/// @brief print the json object
/// @param json the json object
void print_json(json_t *json);


/// @brief print value of the json object
/// @param json the json object
void print_value(json_t *json);

#endif /* !JSON_H_ */
