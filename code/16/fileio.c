#include <stdio.h>

int main()
{
	const char *FILENAME = "test";
	const int WRITTEN_INT = 43;
	int read_int = 0;
	FILE *fw, *fr;
	char msg[20];

	/* write */
	fw = fopen(FILENAME, "w");

	if (fw == NULL) {
		printf("Write error\n");
		return 1;
	}

	fprintf(fw, "hello_drive ");
	fwrite(&WRITTEN_INT, sizeof(WRITTEN_INT), 1, fw);
	fclose(fw);

	/* read */
	fr = fopen(FILENAME, "r");

	if (fr == NULL) {
		printf("Read error\n");
		return 1;
	}

	fscanf(fr, "%s ", msg);
	fread(&read_int, sizeof(read_int), 1, fr);
	printf("Message from drive: %s\n"
	       "Int from drive: %i\n",
	       msg, read_int);
	fclose(fr);

	return 0;
}
