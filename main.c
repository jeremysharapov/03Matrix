#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  struct matrix *edges;

  c.red = 255;
  c.green = 255;
  c.blue = 255;

  
  struct matrix *m = new_matrix(4, 4);

  printf("\nThis is a matrix\n");
  print_matrix(m);

  printf("\nNow I am adding the points (250, 250) and (500, 500) to it\n");
  add_edge(m, 250, 250, 0, 500, 500, 0);
  printf("This is it now:\n");
  print_matrix(m);

  struct matrix *i = new_matrix(4, 4);
  printf("\nHere's a fresh new matrix that I will identitize\n");
  ident(i);
  print_matrix(i);

  printf("\nNow let's multiply them to make sure the identity works\n");
  matrix_mult(i, m);
  print_matrix(m);

  printf("\nLet's use draw_lines to draw that original matrix, going from the origin to the top right\n");
  draw_lines(m, s, c);

  printf("\nFinally, let's change the identity matrix such that the first and second row of the last column are both -250\n");
  i -> m[0][3] = -250;
  i -> m[1][3] = -250;
  print_matrix(i);
  printf("And lets multiply that back to the original one to translate it\n");
  matrix_mult(i, m);
  print_matrix(m);

  printf("\nNow draw_lines will draw the rest of the line from the bottom left to the origin\n");

  draw_lines(m, s, c);
  display(s);
  free_matrix(i);
  free_matrix(m);
}
