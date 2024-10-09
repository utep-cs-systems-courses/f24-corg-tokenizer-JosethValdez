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
    char new_string[len+1];
    
    int i=0;
    while(i < len){
        new_string[i] = *inStr;
        inStr++;
        i++;
    }
    new_string[len] = '\0';
    
    char *p = new_string;
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
char** tokenize(char* a_str, const char a_delim)
{   
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = '\0';
    }
    return result;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("%d.- %s\n", i+1, *(tokens + i));
            free(*(tokens + i));
        }
        printf("%d.- %s\n", i+1, *(tokens + i));
        free(tokens);
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif
