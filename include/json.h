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

/// @brief d
/// @param node d
/// @param type d
void init_value(json_t *node);

/// @brief d
/// @param json d
/// @param path d
/// @return d
json_t *get_key(json_t *json, char *path);

/// @brief get the content of the file
/// @param pathname the path/name of the file
/// @return the content of the file
char *my_getfile(char *pathname);

/// @brief transform a string into a number
/// @param str the string to transform
/// @return the string into a number
int my_atoi(char *str);

    // check if the char is a num
    #define IS_NUM(char) (char > 47 && char < 58) ? (true) : (false)

    // check if the char is a upper letter
    #define IS_UPPER(char) (char > 64 && char < 91) ? (true) : (false)

    // check if the char is a lower letter
    #define IS_LOWER(char) (char > 96 && char < 123) ? (true) : (false)

    // check if the char is a letter
    #define IS_ALPHA(char) (IS_LOWER(char) || IS_UPPER(char)) ? (1) : (0)

    // check if the char is alphanumerique character
    #define IS_ALPHANUM(char) (IS_NUM(char) || IS_ALPHA(char)) ? (1) : (0)

/// @brief count the len of a string
/// @param str the string to be counter
/// @return return the len of the string
int my_strlen(char *str);

/// @brief copy a string into a another
/// @param dest the destination to copy
/// @param src the source to be copied
/// @return the number of bytes copied
/// @note don't forget the null byte in the size of dest
int my_strcpy(char *dest, char *src);

/// @brief compare two strings and chek if there are the same
/// @param s1 the first string to compare
/// @param s2 the second string to compare
/// @param sensitive precise if the case is sensitive or not
/// @return negative number if s1 < s2 and positive number in other case
/// @note if s1 == NULL, INT_MAX is returned and if s2 == NULL, -INT_MAX
/// is returned
int my_strcmp(char *s1, char *s2, bool sensitive);

/// @brief append a new character at the end of string
/// @param str the sting to append a char
/// @param c the char to append
/// @return the string with the char append
char *my_strappend(char *str, char c);

/// @brief compare two strings until nbyte
/// @param s1 the first strings to compare
/// @param s2 the second strings to compare
/// @param nbyte the number of byte to compare
/// @param sensitive precise if the case is sensitive or not
/// @return 0 if the two stings is the same,
///         negative number if s2 > s1
///         positive number if s1 > s2
int my_strncmp(char *s1, char *s2, int nbyte, bool sensitive);

/// @brief count the occurences of a character in a string
/// @param str the string to parse
/// @param c the charactere to count the occurences
/// @return the occurences of c
int my_strocc(char *str, char c);

/// @brief copy a string until a character
/// @param dest the palce to copy the string
/// @param src the string to be copied
/// @param c the character to copy until
/// @return returns the number of byte copied
int my_strcpytil(char *dest, char *src, char c);

/// @brief duplicate a string until a character
/// @param str the string to parse
/// @param c the end character
/// @return a pointer to the new string allocated
char *my_strduptil(char *str, char c);

/// @brief turn an alphanumeric string into upper char
/// @param str the string to change
/// @return returns a new allocated string
char *my_str_upper(char *str);

/// @brief turn an alphanumeric string into lowercase
/// @param str the string to change
/// @return returns a new allocated string
char *my_str_lower(char *str);

/// @brief find a token in a string
/// @param str the string to parse
/// @param tok the token to found
/// @param sensitive sensitive
/// @return true if tok is in, else false
int my_strstr(char *str, char *tok, bool sensitive);

/// @brief clean a string
/// @param str the string to parse
/// @param delim the element to delete
/// @return a cleaned string
char *clean_str(char *str, char delim);

/// @brief duplicate a part of string
/// @param str the string to duplicate
/// @param start the start of the part
/// @param end the end of the part
/// @return the selected part
char *str_select(char *str, char start, char end);

#endif /* !JSON_H_ */
