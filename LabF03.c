/***********************************************+**************************+**
* Pontificia Universidad Javeriana
* Docente: J.Corredor
* Autor: Karol Torres
* Sistemas Operativos
*
*
******************************************************************************/
/* Librerías */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdlib.h>

int main () {
	int er;
	/* Arreglos de tipo char para almacenar la dirección, el fichero...  */
	char nomdir[100], nomfich[100], resp[30];
	struct stat atr;
	DIR *d;
	struct dirent *rd1;
	time_t fecha;
	
	printf ("Nombre directorio\n");
	fgets (nomdir, sizeof (nomdir), stdin);
	/* hay que quitar el \n del nombre del directorio*/
	nomdir[strlen(nomdir) - 1] ='\0';
	fecha=time(&fecha);
	/* Si al abrir la direccion el nombre del directorio es nulo, lanzar mensaje de error  */
	if ((d=opendir(nomdir))==NULL) {
		printf ("No existe ese directorio \n");
		return 1;
	}
	/* Si el directorio existe */
	else {
		/* Seccion de codigo para acceder al fichero y obtener cierta informacion como el nombre */
		while (( rd1 = readdir(d)) != NULL) {
			if ( (strcmp(rd1->d_name, ".")!=0 )&& (strcmp(rd1->d_name, "..")!=0 )){
				strcpy (nomfich, nomdir);
				strcat (nomfich, "/");
				strcat (nomfich, rd1->d_name);
				printf ("fichero :%s:", nomfich);
				er = stat (nomfich, &atr);
				printf ("modo :%#o:", atr.st_mode);
				if ((atr.st_mode & 0400) != 0)
					printf (" permiso R para propietario\n");

				else
					printf (" No permiso R para propietario\n");
				if (S_ISDIR(atr.st_mode)) printf (" Es un directorio \n");
				if (S_ISREG(atr.st_mode))
				/* ficheros modificados en los últimos 10 dias */
					if ( (fecha - 10*24*60*60) < atr.st_mtime) {
						printf ("FICHERO:%s: fecha acceso %s, en sgdos %ld\n", rd1->d_name, ctime (&atr.st_mtime),atr.st_mtime );
					}
			}
		} /* while*/
		closedir (d);
	}
}/* main*/
/* CONCLUSIONES:
	asd
*/
