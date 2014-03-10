#ifndef TASK3_7_FUNCS_H
#define TASK3_7_FUNCS_H

#ifndef __cplusplus
typedef unsigned char bool;
#define true ((bool)1)
#define false ((bool)0)
#endif /* __cplusplus */

#ifndef NULL
#define NULL (void*)0
#endif /* NULL */

#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned long long int    size_t;
#else
typedef unsigned int   size_t;
#endif
#define _SIZE_T_DEFINED
#endif

/**
 * @brief Find a character in a buffer.
 * @param [in] buf Pointer to buffer.
 * @param [in] c Character to look for.
 * @param [in] count Number of characters to check.
 * @return Returns a pointer to the first occurrence of c in str, or NULL if c is not found.
 */
char* MemChr( const void* buf, char c, size_t count );

/**
 * @brief Get the length of a string.
 * @param [in] str Null-terminated source string.
 * @return Returns the number of characters in str, excluding the terminal NULL.
 */
size_t StrLen( const char* str );

/**
 * @brief Determines whether an character represents a decimal-digit character.
 * @param [in] chr Character to test.
 * @return Returns nonzero if chr is a particular representation of a decimal-digit character.
 */
bool IsDigit( char chr );

/**
 * @brief Determines whether an character represents a uppercase character.
 * @param [in] chr Character to test.
 * @return Returns nonzero if chr is a particular representation an uppercase letter.
 */
bool IsUpper( char chr );

/**
 * @brief Determines whether an character represents a lowercase character.
 * @param [in] chr Character to test.
 * @return Returns nonzero if chr is a particular representation an lowercase letter.
 */
bool IsLower( char chr );

/**
 * @brief Determines whether an character represents a alphabetic character.
 * @param [in] chr Character to test.
 * @return Returns nonzero if chr is a particular representation an alphabetic letter.
 */
bool IsAlpha( char chr );

/**
 * @brief Determines whether an character represents a alphanumeric character.
 * @param [in] chr Character to test.
 * @return Returns nonzero if chr is a particular representation an alphanumeric letter.
 */
bool IsAlnum( char chr );

/**
 * @brief Read from stdin string of any length.
 * @return Returns a pointer to the entered string, or NULL if there is insufficient memory available.
 */
char* Input( void );
/**
* @brief Remove word in str, that have position num.
* @param [in, out] str Null-terminated source string.
* @param [in] num Number of word to remove.
*/
void removeWord(char * str, size_t num);

#endif /* TASK3_7_FUNCS_H */