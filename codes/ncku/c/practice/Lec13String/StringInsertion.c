#include <stdio.h>
#include <string.h>
#define MAX_LEN_P 100000
#define MAX_LEN_S 100

void strins(char *P, char *s, char *t);

int main() {
    char P[MAX_LEN_P + 1], s[MAX_LEN_S + 2], t[MAX_LEN_S + 2];
    size_t P_len = 0;
    for (char buf[MAX_LEN_P + 1] = ""; strcmp(buf, "---\n"); fgets(buf, MAX_LEN_P + 1, stdin)) {
        size_t len = strlen(buf);
        if (len + P_len > MAX_LEN_P) {
        fprintf(stderr, "The length of the paragraph exceeds %d\n", MAX_LEN_P);
            return 1;
        }
        strncat(P, buf, len + 1);
        P_len += len;
    }
    fgets(s, MAX_LEN_S + 2, stdin);
    s[strlen(s) - 1] = '\0';  // remove newline
    fgets(t, MAX_LEN_S + 2, stdin);
    t[strlen(t) - 1] = '\0';  // remove newline
    strins(P, s, t);
    printf("%s", P);
    return 0;
}

void strins(char *P, char *s, char *t){
    int count = 0 , pos = 0;
    int pLen = strlen(P), sLen = strlen(s), tLen = strlen(t);
    char temp[MAX_LEN_P];
    
    // loop all char in p
    for(int i=0; i<= pLen ;i++){        
        temp[pos++] =* (P+i);
        // count when P[] = S[]
        if (*(P+i) == *( s + count)){
            
            // printf("%c == %c\n", *(P+i), *(s + count));
            
            
            count++;

            if(count == sLen){
                strcat(temp, t);
                pos += tLen;
                count=0;
            }
        }
        else{
            // printf("%c != %c\n", *(P+i), *(s + count));
            count = 0;
            if (*(P+i) == *(s+count)){
                count++;
            }
        }                 
    }

    strcpy(P, temp);
}