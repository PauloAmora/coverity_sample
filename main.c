#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa Pessoa;

struct pessoa
{
    int id;
    char fname[20];
    char lname[20];
    Pessoa* next;
};


int saveFile ()
{
	FILE *outfile;
	
	// open file for writing
	outfile = fopen ("pessoas.dat", "w");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	Pessoa input1 = {1, "paulopaulopaulopaulopaulo", "amora"};
	
	// write struct to file
	fwrite (&input1, sizeof(Pessoa), 1, outfile);
	
	if(fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");

	// close file
	fclose (outfile);

	return 0;
}

int readFile ()
{
	FILE *infile;
	Pessoa input;
	
	// Open person.dat for reading
	infile = fopen ("pessoas.dat", "r");
	if (infile == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit (1);
	}
	
	// read file contents till end of file
	while(fread(&input, sizeof(Pessoa), 1, infile))
		printf ("id = %d name = %s %s\n", input.id,
		input.fname, input.lname);

	// close file
	fclose (infile);

	return 0;
}

Pessoa* inserePessoa(Pessoa* first, int id, char* fname, char* lname){
    Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));
    p->id = id;
    memcpy(p->fname, fname, 20);
    memcpy(p->lname, lname, 20);
    p->next = first;
    return p;
}

void imprimePessoa (Pessoa* p){
    printf ("id = %d name = %s %s\n", p->id, p->fname, p->lname);
}

int main(){
    Pessoa* pessoas;
    pessoas = NULL;
    pessoas = (Pessoa*)malloc(sizeof(Pessoa));
    pessoas = inserePessoa(pessoas, 1, "Paulo", "Amora");
    pessoas = inserePessoa(pessoas, 2, "Ana", "Buosi");
    imprimePessoa(pessoas);
    imprimePessoa(pessoas->next);
    //saveFile();
    //readFile();

}