/********************************************************************************
*
*
*
*
*
************************************************************************************/

#include <stdio.h>
#include <stlib.h>

int main(int argc, char *argv[]){
	char *nombrefichero = "readme.txt";
	FILE *fp = fopen(nombreFichero, "r");
	if(fp=NULL){
		printf("Error: no se puede abrir el fichero \n");
		return 1;
	}
	printf("\n =====================================================\n");
	printf("\n LECTURA DE FICHERO readme.txt\n");
	printf("\n =====================================================\n");
	const unsigned LARGO_MAX_LINEA = 256;
        char buffer[LARGO_MAX_LINEA];
	while(fgets(buffer, LARGO_MAX_LINEA, fp))
		printf("%s",buffer);
	fclose(fp);
	return 0;	
}
