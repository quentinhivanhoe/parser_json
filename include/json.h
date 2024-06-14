/*
** EPITECH PROJECT, 2024
** json parser
** File description:
** simple json parser in c
*/

#ifndef JSON_H_
    #define JSON_H_
    #include <stdbool.h>

    // the size of the buffer for my_getfile
    #define BUFFER_SIZE 8192

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

///////////////////////////////////////////////////////////////////////////////
/// @brief take a string and returns the type of the string
/// @return returns a type between INT, STR, BOOL, JSON and ARRAY
///////////////////////////////////////////////////////////////////////////////
node_t get_value_type(char *str);

///////////////////////////////////////////////////////////////////////////////
/// @brief create a simple node of the total json
/// @param str the json file stringify
/// @return returns the json object or NULL in error case
///////////////////////////////////////////////////////////////////////////////
json_t *create_node(json_t *prev, char *str);

///////////////////////////////////////////////////////////////////////////////
/// @brief take a node of a json object, and the addresse of the json file
/// stingified. get the value of type `INT` in the json stringify
/// @return returns the current node
///////////////////////////////////////////////////////////////////////////////
json_t *get_int_value(json_t *node, char **str);

///////////////////////////////////////////////////////////////////////////////
/// @brief take a node of a json object, and the addresse of the json file
/// stingified. get the value of type `BOOL` in the json stringify
/// @return returns the current node
///////////////////////////////////////////////////////////////////////////////
json_t *get_bool_value(json_t *node, char **str);

///////////////////////////////////////////////////////////////////////////////
/// @brief take a node of a json object, and the addresse of the json file
/// stingified. get the value of type `STR` in the json stringify
/// @return returns the current node
///////////////////////////////////////////////////////////////////////////////
json_t *get_str_value(json_t *node, char **str);

///////////////////////////////////////////////////////////////////////////////
/// @brief take a node of a json object, and the addresse of the json file
/// stingified. get the value of type `ARRAY` in the json stringify
/// @return returns the current node
///////////////////////////////////////////////////////////////////////////////
json_t *get_array_value(json_t *node, char **str);

///////////////////////////////////////////////////////////////////////////////
/// @brief take a node of a json object, and the addresse of the json file
/// stingified. get the value of type `JSON` in the json stringify
/// @return returns the current node
///////////////////////////////////////////////////////////////////////////////
json_t *get_json_value(json_t *node, char **str);

///////////////////////////////////////////////////////////////////////////////
/// @brief create an array object
/// @param str the value in of the array in the json file stringified
/// @return returns an array object
///////////////////////////////////////////////////////////////////////////////
array_t *create_array(char **str);

///////////////////////////////////////////////////////////////////////////////
/// @brief print all key and they type, also indentation is equal at their
/// depth (2 space = depth 0)
///////////////////////////////////////////////////////////////////////////////
void print_info(json_t *json);

///////////////////////////////////////////////////////////////////////////////
/// @brief print all of the json object in the json file format
///////////////////////////////////////////////////////////////////////////////
void print_json(json_t *json);


///////////////////////////////////////////////////////////////////////////////
/// @brief print the value of a json node
///////////////////////////////////////////////////////////////////////////////
void print_value(json_t *json);

///////////////////////////////////////////////////////////////////////////////
/// @brief initialize the value of the json nod egivane in arguments
///////////////////////////////////////////////////////////////////////////////
void init_value(json_t *node);

///////////////////////////////////////////////////////////////////////////////
/// @brief get the value of a key in the json object
/// @param path the path to tha value, imagine we have json like that
/// `"toto" : { "tutu" : "titi"`...  the path will be `toto:tutu`
/// @return returns a the node of the json object that link with the path
/// @note it's just copy the node returnd is not linked at another node
/// of the main json object
///////////////////////////////////////////////////////////////////////////////
json_t *get_key(json_t *json, char *path);


///////////////////////////////////////////////////////////////////////////////
/// @brief get the content of the file
/// @param pathname the path/name of the file
/// @return returns the content of the file into a string
///////////////////////////////////////////////////////////////////////////////
char *my_getfile(char *pathname);

///////////////////////////////////////////////////////////////////////////////
/// @brief transform a string into a number
/// @return returns the string into a number, if the string is NULL
/// -INT_MAX is returned
///////////////////////////////////////////////////////////////////////////////
int my_atoi(char *str);

///////////////////////////////////////////////////////////////////////////////
/// @brief count the len of a string
/// @return return the len of the string, if the string is NULL 0 is returned
///////////////////////////////////////////////////////////////////////////////
int my_strlen(char *str);

///////////////////////////////////////////////////////////////////////////////
/// @brief copy the a string (src) into antother (dest)
/// @param dest the place to copy in
/// @param src the string to copy
/// @return returns the number of byte copied
/// @note `dest` should have the suffisant place to copy in
///////////////////////////////////////////////////////////////////////////////
int my_strcpy(char *dest, char *src);

///////////////////////////////////////////////////////////////////////////////
/// @brief  compare two strings character by character
/// @param sensitive active the sensitive case if it's true, if it's false
/// capitalize the two strings and compare them
/// @return returns 0 if the two strings are equal
/// a negative number if s2 > s1 and a positive number if s1 > s2
/// @note if s1 is NULL INT_MAX is returned else if s2 is NULL -INT_MAX is
/// returned
///////////////////////////////////////////////////////////////////////////////
int my_strcmp(char *s1, char *s2, bool sensitive);

///////////////////////////////////////////////////////////////////////////////
/// @brief  compare n character of two strings character by character
/// @param nbyte the number of character to compare
/// @param sensitive active the sensitive case if its true, if it's false
/// capitalize the two strings and do a simple my_strcmp
/// @return returns 0 if the two strings are equal
/// a negative number if s2 > s1 and a positive number if s1 > s2
/// @note if s1 is NULL INT_MAX is returned else if s2 is NULL -INT_MAX is
/// returned
///////////////////////////////////////////////////////////////////////////////
int my_strncmp(char *s1, char *s2, int nbyte, bool sensitive);


///////////////////////////////////////////////////////////////////////////////
/// @brief count the occurences of a character in a string
/// @return returns the occurences the character
///////////////////////////////////////////////////////////////////////////////
int my_strocc(char *str, char c);

///////////////////////////////////////////////////////////////////////////////
/// @brief copy a string (src) into antother (dest) until he finds
/// character c
/// @param dest the place to copy in
/// @param src the string to copy
/// @return returns the number of byte copied
/// @note `dest` should have the suffisant place to copy in
///////////////////////////////////////////////////////////////////////////////
int my_strcpytil(char *dest, char *src, char c);

///////////////////////////////////////////////////////////////////////////////
/// @brief duplicate a string until a character
/// @return returns a pointer to the new string allocated
///////////////////////////////////////////////////////////////////////////////
char *my_strduptil(char *str, char c);


///////////////////////////////////////////////////////////////////////////////
/// @brief turn an alphanumeric string into upper char
/// @return returns a pointer to the new allocated string
///////////////////////////////////////////////////////////////////////////////
char *my_str_upper(char *str);

///////////////////////////////////////////////////////////////////////////////
/// @brief find a token in a string
/// @param sensitive active the sensitive case if it's true, if it's false
/// capitalize the two strings
/// @return returns the index of the token, returns -1 in error case
///////////////////////////////////////////////////////////////////////////////
int my_strstr(char *str, char *tok, bool sensitive);

///////////////////////////////////////////////////////////////////////////////
/// @brief duplicate the string without delim
/// @return returns a pointer to the new string
///////////////////////////////////////////////////////////////////////////////
char *clean_str(char *str, char delim);


///////////////////////////////////////////////////////////////////////////////
/// @brief duplicate a part of string
/// @param start the start of the part
/// @param end the end of the part
/// @return returns a pointer to the new string
/// @note if start is not in the string it will start a the begining of the
/// string. If end is not in it will duplicate until the null byte
///////////////////////////////////////////////////////////////////////////////
char *str_select(char *str, char start, char end);


///////////////////////////////////////////////////////////////////////////////
/// @brief free the json object
///////////////////////////////////////////////////////////////////////////////
void free_json(json_t *json);

///////////////////////////////////////////////////////////////////////////////
/// @brief create a json object
/// @param pathname the path to the file
/// @return returns a json object
///////////////////////////////////////////////////////////////////////////////
json_t *create_json(char *pathname);

///////////////////////////////////////////////////////////////////////////////
/// @brief alloc a new string and concatenate s1 and s2 in it
/// @return returns the pointer to the new strings
///////////////////////////////////////////////////////////////////////////////
char *my_strconcat(char *s1, char *s2);


///////////////////////////////////////////////////////////////////////////////
/// @brief concatenate s1 and s2 in dest
/// @note dest must have the place to concatenate s1 and s2
///////////////////////////////////////////////////////////////////////////////
void my_strcat(char *dest, char *s1, char *s2);

#endif /* !JSON_H_ */
