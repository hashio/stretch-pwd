/* -*-mode:c-*-
 * Copyright 2009 Takahiro Hashimoto
 * All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>

static int DEFAULT_MAX_LENGTH=32;
static char* DEFAULT_CONCAT="...";

void sp_usage(void);
int sp_isdigit(char* num);
char* sp_stretch_directory(const char* dir, int max_length, char* concat);


int main(int argc, char *argv[])
{
	int ch;
	int max_length = DEFAULT_MAX_LENGTH; 
	char* dir;
	char* concat = DEFAULT_CONCAT;

	while((ch = getopt(argc, argv, "l:c:h?")) != -1){
		switch(ch){
		case 'l':
			if(sp_isdigit(optarg)){
				max_length = atoi(optarg);
			}else{
				sp_usage();
			}
			break;
		case 'c':
			concat = optarg;
			break;
		case 'h':
		case '?':
			sp_usage();
		default:
			break;
		}
	}
	argc -= optind;
	argv += optind;

	if(argc > 0){
		dir = argv[0];
	}else{
		dir = getenv("PWD");
	}

	printf("%s\n", sp_stretch_directory(dir, max_length, concat));
	exit(0);
} /* end of main() */



void sp_usage(void){
	printf("Usage: stretch-pwd [-lch?] [directory]\n");
	exit(1);
}

int sp_isdigit(char* num){
	int i;
	int max_length = strlen(num);
	for(i = 0; i < max_length; i++){
		if(!isdigit(num[i])){
			return 0;
		}
	}
	return 1;
}

char* sp_stretch_directory(const char* dir, int max_length, char* concat){
	if(max_length < strlen(concat)){
		max_length = strlen(concat);
	}
	char* stretch_dir = calloc(sizeof(char), max_length + 1);

	if(strlen(dir) >= max_length){
		int max_half_length = (max_length - strlen(concat)) / 2;
		strncat(stretch_dir, dir, max_half_length);
		strcat(stretch_dir, concat);
		char* dir_substring = &dir[strlen(dir) - max_half_length];
		strncat(stretch_dir, dir_substring, max_half_length);
	}else{
		strncpy(stretch_dir,dir, max_length);
	}
	return stretch_dir;
}
