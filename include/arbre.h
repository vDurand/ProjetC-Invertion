#ifndef __KDTREE_HH__
#define __KDTREE_HH__

#include "table.h"

typedef struct cutting_plane *cutting_plane;

struct cutting_plane
{
	int position;
	int value;
};

typedef  struct kdtree *kdtree;

struct kdtree
{
	color_table colorTable;
	struct kdtree *left_son, *right_son;
	axis sortAxis;
	cutting_plane cuttingPlane;
};

kdtree create_kdtree(color_table,int);
void   destroy_kdtree(kdtree);
void   kdtree_get_nearest_color(kdtree,color*, color*);

#endif