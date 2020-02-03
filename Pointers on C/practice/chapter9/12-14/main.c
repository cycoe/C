#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_char(const char *string, const char *stop, char chr) {
  while (string < stop) {
    if (toupper(*string++) == toupper(chr)) {
      return 1;
    }
  }

  return 0;
}

int prepare_key(char *key) {
  if (key == NULL)
    return 0;

  char *fast = key, *slow = key;
  while (*fast) {
    if (toupper(*fast) < 'A' || toupper(*fast) > 'Z')
      return 0;
    if (check_char(key, slow, *fast)) {
      fast++;
    } else {
      *slow++ = toupper(*fast++);
    }
   }

   int alphas[27];
   for (int chr = 'A'; chr <= 'Z'; chr++) {
     if (!(check_char(key, slow, chr))) {
       *slow++ = chr;
     }
   }

   return 1;
}

void encrypt(char *data, char const *key) {
  while (*data) {
    if (isalpha(*data)) {
      if (isupper(*data)) {
        *data = key[*data - 'A'];
      } else {
        *data = tolower(key[toupper(*data) - 'A']);
      }
    }
    data++;
  }
}

int get_index(char const *key, char const ch) {
  for (unsigned i = 0; key[i]; i++) {
    if (toupper(key[i]) == toupper(ch)) {
      return i;
    }
  }
  return -1;
}

void decrypt(char *data, char const *key) {
  while (*data) {
    if (isalpha(*data)) {
      if (isupper(*data)) {
        *data = 'A' + get_index(key, *data);
      } else {
        *data = 'a' + get_index(key, *data);
      }
    }
    data++;
  }
}

int main(int argc, char *argv[])
{
  char key[27] = "TRAILBLAZERS";
  char data[] = "ATTACK at DAWN";
  if (prepare_key(key)) {
    printf("Key is '%s'\n", key);
    printf("Original string is '%s'.\n", data);
    encrypt(data, key);
    printf("Encrypted string is '%s'.\n", data);
    decrypt(data, key);
    printf("Decrypted string is '%s'.\n", data);
  }
  return 0;
}
