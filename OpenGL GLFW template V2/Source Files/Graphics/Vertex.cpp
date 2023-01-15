#include "../../Headers/Graphics/Vertex.h"

jf::Vertex::Vertex()
{
	data[0] = &x;
	data[1] = &y;
	data[2] = &z;
	data[3] = &r;
	data[4] = &g;
	data[5] = &b;
	data[6] = &a;
	data[7] = &texX;
	data[8] = &texY;
	data[9] = &normalX;
	data[10] = &normalY;
	data[11] = &normalZ;
}
