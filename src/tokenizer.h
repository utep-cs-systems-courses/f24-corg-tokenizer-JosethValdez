#ifndef _TOKENIZER_
#define _TOKENIZER_


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
    if ((c == ' ') || (c == '\t'))
        return 1;

    return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
   if ((c != ' ') && (c != '\t'))
        return 1;

    return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */


/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
    while (*token != '\0') {  
        if (*token == ' '){
            token += 1;
            return token;
        }
        token++;  
    }
    *token = 0;
    return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
    int count = 1;
    while (*str != '\0'){
        if (*str == ' ')
            count++;
        str++;
    }
    return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
    char *new_string;
    
    int i;
    for(i=0; i<=len; i++){
        if (i == len){
            *inStr = '\0';
        } else {
            inStr++;
        }
    }
    inStr = inStr - i;
    char *p = inStr;
    return p;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
