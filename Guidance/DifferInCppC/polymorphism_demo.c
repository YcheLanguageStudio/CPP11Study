#include "stdio.h"
#include "stdlib.h"
struct Polygon {
  int width_, height_;
  void (*area_ptr_)(struct Polygon *ptr_ploy);
};

struct Polygon *PolygonConstructor(int width, int height) {
  struct Polygon *ppoly = malloc(sizeof(struct Polygon));
  ppoly->width_ = width, ppoly->height_ = height;
  return ppoly;
}

void area_rectangle(struct Polygon *ptr_ploy) {
  printf("Rectangle Width:%d,Height:%d\n", ptr_ploy->width_, ptr_ploy->height_);
  printf("Rectangle Area:%d\n", ptr_ploy->width_ * ptr_ploy->height_);
}

struct Polygon *RectangleConstructor(int width, int height) {
  struct Polygon *ppoly = PolygonConstructor(width, height);
  ppoly->area_ptr_ = area_rectangle;
  return ppoly;
}

void area_triangle(struct Polygon *ptr_ploy) {
  printf("Rectangle Width:%d,Height:%d\n", ptr_ploy->width_, ptr_ploy->height_);
  printf("Rectangle Area:%d\n", ptr_ploy->width_ * ptr_ploy->height_ / 2);
}

struct Polygon *TriangleConstructor(int width, int height) {
  struct Polygon *ppoly = PolygonConstructor(width, height);
  ppoly->area_ptr_ = area_triangle;
  return ppoly;
}

int main() {
  struct Polygon *ppoly_rec = RectangleConstructor(4, 5);
  ppoly_rec->area_ptr_(ppoly_rec);
  free(ppoly_rec);

  printf("\n");

  struct Polygon *ppoly_tri = TriangleConstructor(4, 5);
  ppoly_tri->area_ptr_(ppoly_tri);
  free(ppoly_tri);
}
