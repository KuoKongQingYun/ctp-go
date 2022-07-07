typedef struct { 
    char** pArray; 
    int nSize; 
} StringArray;
StringArray *newStringArray(int size);
void setStringArray(StringArray *stringArray, int index, char *s);
void deleteStringArray(StringArray *stringArray);