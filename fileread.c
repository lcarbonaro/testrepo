#include <stdio.h>

int main(void) 
{
    FILE *fp;  // declare a file pointer
    
    char line[255];  // set this to (arbitrary) maximum line length  
    
    fp = fopen("myfile.txt","r");   // open file for reading
    
    fgets(line,sizeof(line),fp);  // read in a line of text from file
    
    printf("%s",line);  // output the line
    
    fclose(fp);  // close the file
    
    return 0;
}

// ref: 
// http://www.cprogramming.com/tutorial/cfileio.html
// http://www.mathworks.com/help/matlab/low-level-file-i-o.html
