#include <stdio.h>

void
print_scrambled(char *message)
{
  int i = 3;
  do {
    printf("%c", (*message)+i);
  } while (*++message);
  printf("\n");
}

int
main()
{
  char *message = NULL;
  char *msg = "Hello, world.";

//corrected joseph Ladino 10/17/2016
  message = msg;  
// added address change of msg so null would be replaced with "hello, world"

  print_scrambled(msg);
  print_scrambled(message);

  return 0;
}

