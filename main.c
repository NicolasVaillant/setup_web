#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <unistd.h> 
#include <time.h>

#include <sys/stat.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>

#define SIZE 100
#define SIZE_AT 5000
#define BUFFER_SIZE 1000

// Function Calls
int createChild(char *pathCreated, char *name, bool php);
void replaceAll(char *str, const char *oldWord, const char *newWord);
int newFunction(char *pathres, char *name);

void changeName(char *pathToChange, char *pathInit, char *name, bool test);

int main(int argc, char *argv[])
{
	char s[100];
	int check;
	int sizes[3];
	char path[] = "C:\\Users\\vnico\\OneDrive\\Documents\\web\\created\\";
    char dirname[SIZE];
	char *result[SIZE];
	
	char *arr[SIZE_AT];

    chdir(path);

	if(argc >= 2){

		// for(int i = 0 ; i < argc ; i++){
		// 	arr[i] = argv[i];
		// 	printf("\n----------\n");
		// 	printf("%d\n", i);
		// 	printf("%s\n", arr[i]);
		// 	printf("----------\n");

		// 	if(strstr(arr[i], "-s")){
		// 		printf("-s present.\n");
		// 	}else if(strstr(arr[i], "-h")){
		// 		printf("-h present.\n");
		// 	}else if(strstr(arr[i], "-p")){
		// 		printf("-p present.\n");
		// 	}else{
		// 		printf("nothing.\n");
		// 	}
		// }
		
		// exit(EXIT_SUCCESS);

		if (strstr(argv[1], "-") != NULL){
			if(strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-h") == 0 ) {
				printf("\n----------\n");
				printf("HELP");
				printf("\n----------\n");
				printf("*Folder name does not support space\n");
				printf("*Add -php to allows php in your project\n");
				printf("*Add ups to 3 parameters -size for mediaqueries\n");
				printf("> Sort the values by ascending order\n");
				printf("> By default 2000px / 1200px / 500px\n");
				printf("----------\n");
				exit(EXIT_SUCCESS);
			}else if(strcmp(argv[1], "-size") == 0 || strcmp(argv[1], "-s") == 0){
				//argv[2] = size_1				
				//argv[3] = size_2		
				//argv[4] = size_3	
				printf("%s\n", path);	
			}else{
				exit(EXIT_FAILURE);
			}
			// ADD PARAMETERS HERE
		}else{
			printf("\n----------\n");
				
			strcat(path,argv[1]);
			check = mkdir(argv[1]);
				
			if (!check){
				printf("Directory created at %s\n", path);
				printf("----------\n");
				createChild(path, argv[1], false);
			}
			else{
				printf("Already existing\n");
				printf("----------\n");
				exit(EXIT_FAILURE);  
			} 
		}
	}else{
		printf("\n----------\n");
		printf("Project name : ");
		gets(dirname);
		printf("----------\n");
		strcat(path,dirname);
		check = mkdir(dirname);
				
		if (!check){
			printf("Directory created at %s\n", path);
			printf("----------\n");
			createChild(path, dirname, false);
		}
		else{
			printf("Already existing\n");
			printf("----------\n");
			exit(1);  
		} 
	}	
	return 0;
}

int createChild(char *pathCreated, char *name, bool php){
	char s[SIZE], newpath[SIZE], newpathMedia[SIZE], newpathPHP[SIZE];
	char pathCSS[SIZE],pathHTML[SIZE];

	int clr_end = 0;

	// ----------------------- Create folders
	chdir(pathCreated);
	mkdir("js");
	mkdir("css");
	mkdir("ressources");
	// -----------------------

	strcpy(newpathPHP,pathCreated);
	
	// ----------------------- HTML FILE
	FILE *fpHTML;
	FILE *fpTEMP_HTML;
    char ch_HTML;
	fpHTML = fopen("index.html", "w");
	fpTEMP_HTML = fopen("C:\\Users\\vnico\\OneDrive\\Documents\\web\\created\\setup\\html\\temp_html.txt", "r");
	// ------------ ADD fpTEMP_HTML in fpHTML
    while((ch_HTML = getc(fpTEMP_HTML)) != EOF){
        putc(ch_HTML, fpHTML);
	}
  	// ----------------------- ADD WORD IN fpHTML FILE
	
    fclose(fpTEMP_HTML);
	fclose(fpHTML);
	//------------------------------CSS
	strcpy(pathHTML,pathCreated);
	strcpy(newpath,pathCreated);
	strcat(newpath,"\\css");
	chdir(newpath);
	mkdir("mediaqueries");

	// printf("%s\n", getcwd(s, 100));

	FILE *fpCSS, *fpCSS_anim,*fpCSS_root;
	FILE *fpCSS_Media_web, *fpCSS_Media_mob, *fpCSS_Media_alt;
	fpCSS = fopen("style.css", "w");
	fpCSS_anim = fopen("anim.css", "w");
	fpCSS_root = fopen("root.css", "w");

	FILE *fpTEMP_CSS, *fpTEMP_ANIM, *fpTEMP_ROOT, *fpTEMP_MEDIA;
    char cSTYLE, cANIM, cROOT, cMEDIA;
  
    // ouvrir le fichier en lecture
    fpTEMP_CSS = fopen("C:\\Users\\vnico\\OneDrive\\Documents\\web\\created\\setup\\css\\temp_style.txt", "r");
    fpTEMP_ANIM = fopen("C:\\Users\\vnico\\OneDrive\\Documents\\web\\created\\setup\\css\\temp_anim.txt", "r");
    fpTEMP_ROOT = fopen("C:\\Users\\vnico\\OneDrive\\Documents\\web\\created\\setup\\css\\temp_root.txt", "r");
    fpTEMP_MEDIA = fopen("C:\\Users\\vnico\\OneDrive\\Documents\\web\\created\\setup\\css\\temp_mediaqueries.txt", "r");
  
	// -------------------------------------------------
    // Lire le contenu du fichier STYLE.CSS
    while((cSTYLE = getc(fpTEMP_CSS)) != EOF)
        putc(cSTYLE, fpCSS);
  
    fclose(fpTEMP_CSS);
	fclose(fpCSS);
	// -------------------------------------------------
	// Lire le contenu du fichier ANIM.CSS
    while((cANIM = getc(fpTEMP_ANIM)) != EOF)
        putc(cANIM, fpCSS_anim);
  
    fclose(fpTEMP_ANIM);
	fclose(fpCSS_anim);
	// -------------------------------------------------
	// Lire le contenu du fichier ROOT.CSS
    while((cROOT = getc(fpTEMP_ROOT)) != EOF)
        putc(cROOT, fpCSS_root);
  
    fclose(fpTEMP_ROOT);
	fclose(fpCSS_root);

	strcpy(pathCSS,newpath);
	strcat(newpath,"\\mediaqueries");
	chdir(newpath);

	fpCSS_Media_web = fopen("style_media_web.css", "w");
	fpCSS_Media_mob = fopen("style_media_mob.css", "w");
	fpCSS_Media_alt = fopen("style_media_alt.css", "w");

	//------------------------------CSS
	chdir("..");		
	//------------------------------JS
	strcat(pathCreated,"\\js");
	chdir(pathCreated);

	FILE *fpJS;
	fpJS = fopen("script.js", "a+");
	fprintf(fpJS, "//JS FILE");
	fclose(fpJS);
	//------------------------------JS
	chdir("..");		
	//------------------------------JS


	if(php){
		mkdir("php");
		strcat(newpathPHP,"\\php");
		chdir(newpathPHP);
		FILE *fpPHP;
		fpPHP = fopen("file.php", "a+");
		fprintf(fpPHP, "//PHP FILE");
		fclose(fpPHP);
	}else{}


	clr_end = newFunction(pathHTML, name);
	clr_end = newFunction(pathCSS, name);

	if (clr_end = 1){
		printf("Script successfully completed\n");
		printf("----------\n");
		exit(EXIT_SUCCESS);
	}else{
		printf("Script error. Retry.\n");
		printf("----------\n");
		exit(EXIT_FAILURE);
	}
}

int newFunction(char *pathres, char *name){
	
    char path[100], path_init[100];
    
	if (strstr(pathres, "css") != NULL) {
    	strcpy(path,pathres);
    	strcpy(path_init,pathres);
		strcat(path,"\\root.css");

		changeName(path, path_init, name, false);

	}else{
		strcpy(path,pathres);
		strcpy(path_init,pathres);
		strcat(path,"\\index.html");

		changeName(path, path_init, name, true);
	}
	return 1;
}

void changeName(char *pathToChange, char *pathInit, char *name, bool test){
	// true = html
	// false = css

	FILE * fPtr;
    FILE * fTemp;
	char oldWord[] = "created";
    char buffer[BUFFER_SIZE];
    char newWord[100];

	fPtr  = fopen(pathToChange, "r");

	if (test){
 		fTemp = fopen("replace.tmp", "w"); 
	}else{
		chdir(pathInit);
 		fTemp = fopen("replace.tmp", "w"); 
	}

	if (fPtr == NULL || fTemp == NULL){
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

	while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL){
        replaceAll(buffer, oldWord, name);
        fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
    remove(pathToChange);

	if (test){
 		rename("replace.tmp", "index.html");
	}else{
		chdir(pathInit);
		rename("replace.tmp", "root.css");
	}
}

void replaceAll(char *str, const char *oldWord, const char *newWord){
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    if (!strcmp(oldWord, newWord)) {
        return;
    }
    while ((pos = strstr(str, oldWord)) != NULL){
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
		strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}