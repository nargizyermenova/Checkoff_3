#include <stdio.h>

int encode(unsigned char img[8][8], int by_col, FILE *out) {
  int value = img[0][0];
  int count = 0;
  int bytes = 0;

  for (int i = 0; i < 64; i++) {
      int r = i / 8, c = i % 8;

      // Swap the indices to read down the column
      int pixel = by_col ? img[c][r] : img[r][c];

      if (pixel != value) {
          fputc(count, out);
          fputc(value, out);
          bytes += 2;
          value = pixel;
          count = 0;
      }
      count++;
  }

  // Write the last run after the loops ends
  fputc(count, out);
  fputc(value, out);
  return bytes + 2;
}

int main(void) {
  unsigned char [8][8];

  // Make alternating black and white rows
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
          img[r][c] = (r % 2 == 0) ? 0x00 : 0xFF;
      }
  }

  FILE *out = tmpfile();
  if (out == NULL) {
      perror("tmpfile");
      return 1;
  }

  printf("Across rows: %d bytes\n", encode(img, 0, out));
  printf("Down columns: %d bytes\n", encode(img, 1, out));

  fclose(out);
  return 0;
}
      
