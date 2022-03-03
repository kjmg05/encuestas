/*
ProyectoFinal
Kenia Martinez
Andrea Maria Ramos
Alanis Espinoza
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define user "programacion"
#define password "estructurada"
#define lenght 12

FILE *encuesta;
struct dato
	{
		int numero;
		char name [30];
		int age;
		char obsAge[30];
		double weight;
		double height;
		double imc;
		char obsImc[30];
		char genero;
		char civil;
	};

void pword() 
	{
	    char usuario[lenght + 1];
	    char clave[lenght + 1];
	    int tries = 0;
	    int entry = 0;
	    char c;
	    int i = 0;
	    
	    do {
	        i = 0;
	        system("cls");
	        
	        printf("\n\t\tINICIAR SESION");
			printf("\n\t\t******* ******\n");
				
			printf(" Intento N. [%d]", tries+1);
	        printf("\n\tUsuario: ");
	        gets(usuario); //presionar enter para ingresar
	        printf("\tContrase%ca: ", 164);
	        
	        while (c = getch()) 
			{
	            if (c == 13) {
	                clave[i] = '\0';
	                break;
	            } 
				else if (c == 8) 
				{
	                if (i > 0) 
					{
	                    i--;
	                    printf("\b \b");
	                }
	            } 
				else 
				{
	                if (i < lenght) 
					{
	                    printf("*");
	                    clave[i] = c;
	                    i++;
	                }
	            }
	        } //presionar enter para ingresar
	        
	        if (strcmp(usuario, user) == 0 && strcmp(clave, password) == 0) 
			{
	            entry = 1;
	            
	        } 
			else 
			{
	           	printf("\n----USUARIO O CONTRASE%cA INCORRECTO.----\n", 165);
	            tries++;
	            getch();
	        }
	        
	    } while (tries < 3 && entry == 0);
	    
	    if (entry == 1) 
		{
	        printf("\n\t\tINICIO DE SESION EXITOSO.\n\n");
			system("pause");
			system("cls");
	        
	    } 
		else 
		{
	        printf("\n\t\tEXCEDIO EL NUMERO DE INTENTOS.\n\n");
			exit(0);
	    }
	}

main ()
	{
		char resp, depto[30], respFile, *msj;
		int numPersonas, i, c = 0, s = 0, v = 0, noSalud = 0;
		int bp = 0, sp = 0, pn = 0, voteF = 0, voteM = 0, vote = 0, noVote = 0; 
		int kid = 0, teen = 0, adult = 0, old = 0;
		double avgSalud, avgNoSalud, avgCasada, avgSingle;
		srand(time(NULL));
		
		pword();
		
		do
		{
			printf("\n\t\tBIENVENIDO AL SISTEMA DE ENCUESTAS");
			printf("\n\t\t********** ** ******* ** *********\n\n");
			
			printf("\tDesea crear el archivo [S/N]: ");
			scanf("%s", &respFile);
			respFile = toupper(respFile);
			switch(respFile)
			{
				case'S':
					encuesta = fopen("encuestaDepartamentos.txt", "r");
					if(encuesta != NULL)
					{
						printf("\n\tEl archivo ya existe.\n");
					}
					else
					{
						encuesta = fopen("encuestaDepartamentos.txt", "w");
						printf("\n\tEl archivo ha sido creado correctamente.\n");
					}
					fclose (encuesta);
					system("pause");
					system("cls");
					break;
				case'N':
					encuesta = fopen("encuestaDepartamentos.txt", "r");
					if(encuesta == NULL)
					{
						printf("----Lo sentimos no existe el archivo. No puede continuar sin crearlo.----\n");
						printf("\tDesea crear el archivo [S/N]: ");
						scanf("%s", &respFile);
						respFile = toupper(respFile);
						if(respFile == 'S')
						{
							encuesta = fopen("encuestaDepartamentos.txt", "w");
							printf("\n\tEl archivo ha sido creado correctamente.\n");
						}
						else
						{
							printf("\n\tLo sentimos. No puede continuar sin crear el archivo.\n");
							exit(0);
						}
					}
					else
					{
						printf("\nEl archivo ha sido creado anteriormente. Puede continuar.\n");
					}
					fclose (encuesta);
					system("pause");
					system("cls");	
					break;		
			}
		}while(respFile != 'S' && respFile != 'N');

		do
		{
			system("cls");
			encuesta = fopen("encuestaDepartamentos.txt", "a");
			printf("\n\t\tENCUESTA EN DEPARTAMENTOS DE HONDURAS");
			printf("\n\t\t******** ** ************* ** ********\n\n");
			
			printf(" Departamento: ");
			scanf("%s", &depto[30]);
	
			//Validacion cantidad de votantes
			do
			{
				printf(" Numero de encuestados: ");
				scanf("%d", &numPersonas);
				if(numPersonas < 5 || numPersonas >50)
					printf(" ERROR. Ingrese un dato valido.\n");
			}while(numPersonas < 5 || numPersonas >50);
			
			struct dato per[numPersonas];
			
			for(i = 0; i < numPersonas; i++)
			{
				per[i].numero = i+1;
				printf("\n Persona encuestada N. [%d]\n", per[i].numero);
				printf(" Ingrese el nombre: ");
				scanf("%s", &per[i].name);
				
				//Edades
				per[i].age = rand()%46 +5;
				if(per[i].age < 13)
				{
					kid++;
					strcpy (per[i].obsAge, "Niño");
				}
				else if(per[i].age > 13 && per[i].age < 19)
				{
					teen++;
					strcpy (per[i].obsAge, "Adolescente");
				}
				else if(per[i].age > 20 && per[i].age < 59)
				{
					adult++;
					strcpy (per[i].obsAge, "Adulto");
				}
				else 
				{
					old++;
					strcpy (per[i].obsAge, "Adulto Mayor");
				}
					
				//Cantidad de votantes
				if(per[i].age > 18) 
					vote++;
				else
					noVote++;
			
				//Validacion Peso
				do
				{
					printf(" Ingrese el peso: ");
					scanf("%lf", &per[i].weight);
					if(per[i].weight < 10 || per[i].weight > 90)
						printf(" ERROR. Ingrese un dato valido.\n");
				}while(per[i].weight < 10 || per[i].weight > 90);
				
				//Validacion Estatura
				do
				{
					printf(" Ingrese la estatura: ");
					scanf("%lf", &per[i].height);
					if(per[i].height < 1.00 || per[i].height > 2.20)
						printf(" ERROR. Ingrese un dato valido.\n");
				}while(per[i].height < 1.00 || per[i].height > 2.20);
					
				//Calculo IMC
				per[i].imc = ((per[i].weight) / (per[i].height*per[i].height)); 
				if(per[i].imc < 18)
				{
					strcpy (per[i].obsImc, "Bajo Peso");
					bp++;
				}
				else if(per[i].imc > 18 && per[i].imc < 25)
				{
					strcpy (per[i].obsImc, "Peso Normal");
					pn++;
				}	
				else
				{
					strcpy (per[i].obsImc, "Sobre Peso");
					sp++;
				} 
				noSalud = bp + sp;
				
				//Validacion genero
				do
				{
					printf(" Ingrese el genero [F/M]: ");
					scanf("%s", &per[i].genero);
					per[i].genero = toupper(per[i].genero);
					if(per[i].genero != 'F' && per[i].genero != 'M')
						printf(" ERROR. Ingrese un dato valido.\n");
				}while(per[i].genero != 'F' && per[i].genero != 'M');
					
				//Tipo de votantes
				if(per[i].genero == 'F')
				{
					voteF++;
				}
				else
				{
					voteM++;
				}
				
				//Validacion Estado Civil
				do
				{
					printf(" Ingrese el estado civil [S/C/V]: ");
					scanf("%s", &per[i].civil);
					per[i].civil = toupper(per[i].civil);
					if(per[i].civil != 'S' && per[i].civil != 'C' && per[i].civil != 'V')
						printf(" ERROR. Ingrese un dato valido.\n");
				}while(per[i].civil != 'S' && per[i].civil != 'C' && per[i].civil != 'V');
				
				//Tipo de estado civil
				switch(per[i].civil)
				{
					case 'S':
						s++;
						break;
					case 'C':
						c++;
						break;
					default:
						v++;
						break;
				}
				
			}
			
			fprintf(encuesta, "\n\t\tENCUESTA EN DEPARTAMENTOS DE HONDURAS");
			fprintf(encuesta, "\n\t\t******** ** ************* ** ********");
			fprintf(encuesta, "\n Departamento: ");
			fprintf(encuesta, "%s", depto);
			fprintf(encuesta, "\n Numero de encuestados: ");
			fprintf(encuesta, "%d", numPersonas);
			
			for(i = 0; i < numPersonas; i++)
			{
				
				fprintf(encuesta, "\n\n Numero de encuestado: ");
				fprintf(encuesta, "[%d]", per[i].numero);
				
				fprintf(encuesta, "\n Nombre de la persona: ");
				fprintf(encuesta, "[%s]", per[i].name);
				
				fprintf(encuesta, "\n Edad de la persona: ");
				fprintf(encuesta, "[%d]", per[i].age);
				
				fprintf(encuesta, "\n Observacion Edad: ");
				fprintf(encuesta, "[%s]", per[i].obsAge);
				
				fprintf(encuesta, "\n Peso en kilos: ");
				fprintf(encuesta, "[%.2lf]", per[i].weight);
				
				fprintf(encuesta, "\n Estatura en metros: ");
				fprintf(encuesta, "[%.2lf]", per[i].height);
				
				fprintf(encuesta, "\n Indice de Masa Corporal: ");
				fprintf(encuesta, "[%.2lf]", per[i].imc);
				
				fprintf(encuesta, "\n Observacion IMC: ");
				fprintf(encuesta, "[%s]", per[i].obsImc);
				
				fprintf(encuesta, "\n Genero: ");
				fprintf(encuesta, "[%c]", per[i].genero);
				
				fprintf(encuesta, "\n Estado Civil: ");
				fprintf(encuesta, "[%c]", per[i].civil);
			}
			
			printf("\n\n");
			system("pause");
			system("cls");
			
			printf("\n\t\tH I S T O G R A M A");
			
			printf("\n\tNi%cos [%d]: ", 164, kid);
			for(i = 1; i <= kid; i++)
				printf("*");
			
			printf("\n\tAdolescentes [%d]: ", teen);
			for(i = 1; i <= teen; i++)
				printf("*");
				
			printf("\n\tAdultos [%d]: ", adult);
			for(i = 1; i <= adult; i++)
				printf("*");
				
			printf("\n\tAdultos Mayores [%d]: ", old);
			for(i = 1; i <= old; i++)
				printf("*");
			
			avgSalud = ((double)pn*100/numPersonas);
			avgNoSalud = ((double)noSalud*100/numPersonas);
			avgCasada = ((double)c*100/numPersonas);
			avgSingle = ((double)s*100/numPersonas);
			
			printf("\n\n\tCantidad de Votantes Femeninos: [%d]", voteF);
			printf("\n\tCantidad de Votantes Masculinos: [%d]", voteM);
			printf("\n\tTotal de Votantes (mayores de 18 a%cos): [%d]", 164, vote);
			printf("\n\tTotal de NO Votantes (menores de 18 a%cos): [%d]", 164, noVote);
			printf("\n\tPorcentaje de personas saludables: [%.2lf %%]", avgSalud);	
			printf("\n\tPorcentaje de personas NO saludables: [%.2lf %%]", avgNoSalud);		
			printf("\n\tPorcentaje de personas casadas: [%.2lf %%]", avgCasada);
			printf("\n\tPorcentaje de personas solteras: [%.2lf %%]", avgSingle);
			printf("\n\tCantidad de personas viudas: [%d]", v);
			
			fclose (encuesta);
			printf("\n\n");
			system("pause");
			system("cls");
			
		//Reinicio de variables
		numPersonas = 0, i = 0, c = 0, s = 0, v = 0, noSalud = 0;
		bp = 0, sp = 0, pn = 0, voteF = 0, voteM = 0, vote = 0, noVote = 0; 
		kid = 0, teen = 0, adult = 0, old = 0;
		avgSalud = 0, avgNoSalud = 0, avgCasada = 0, avgSingle = 0;
			
			printf("\nDesea continuar con otro departamento [S/N]: ");
			scanf("%s", &resp);
			resp = toupper(resp);
			if(resp == 'N')
				printf("\n\n\tGRACIAS POR USAR EL SISTEMA.");
		}while (resp == 'S');	
		
		return 0;
	}
