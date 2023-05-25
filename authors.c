#include <stdio.h>

int main()
{
	FILE *file;
	file = fopen("authors.txt", "w");

	if (file == NULL)
	{
		printf("Unable to create file\n");
		return (1);
	}

	fprintf(file, "Emmy Kenduiwa\n");
	fprintf(file, "Richard Orido\n");

	fclose(file);

	printf("Author file created successfully.\n");
	return (0);
}
