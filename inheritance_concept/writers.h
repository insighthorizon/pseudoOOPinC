#define INHERIT_WRITERS__(X) \
  BUILDER_MACROS__(X)

#define BUILDER_WRITERS__(MORPH)		\
  INHERIT_WRITERS__(MORPH) \
  MORPH( i, j) \
  MORPH( k, l)