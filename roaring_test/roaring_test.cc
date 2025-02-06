#include <roaring/roaring.h>

#include <iostream>

int main(int argc, char const* argv[]) {
  roaring_bitmap_t* r1 = roaring_bitmap_create();
  roaring_bitmap_t* r2 = roaring_bitmap_create();

  // 向第一个集合中添加整数
  roaring_bitmap_add(r1, 1);
  roaring_bitmap_add(r1, 2);
  roaring_bitmap_add(r1, 3);

  // 显示 r1 结构
  roaring_bitmap_printf_describe(r1);
  printf("\n");

  roaring_bitmap_printf(r1);
  printf("\n");

  // 向第二个集合中添加整数
  roaring_bitmap_add(r2, 3);
  roaring_bitmap_add(r2, 4);
  roaring_bitmap_add(r2, 5);

  // 显示 r2 结构
  roaring_bitmap_printf_describe(r2);
  printf("\n");

  roaring_bitmap_printf(r2);
  printf("\n");

  // 计算并集
  roaring_bitmap_t* union_bitmap = roaring_bitmap_or(r1, r2);

  // 打印并集的元素
  roaring_uint32_iterator_t* iter = roaring_create_iterator(union_bitmap);
  while (iter->has_value) {
    printf("%u\n", iter->current_value);
    roaring_advance_uint32_iterator(iter);
  }

  // 清理资源
  roaring_free_uint32_iterator(iter);
  roaring_bitmap_free(r1);
  roaring_bitmap_free(r2);
  roaring_bitmap_free(union_bitmap);

  return 0;
}
