#include "..\Header\Const.h"
#include "..\Header\Tank.h"

Tank::Tank(void)
{
	direction_index = 0; // in default look up
	coordinate[0] = Height;
	coordinate[1] = Width/2;
}

void Tank::Move(int index)
{
	direction_index = index;
	coordinate[0] = coordinate[0] + direction[index][0];
	coordinate[1] = coordinate[1] + direction[index][1];
}
void Tank::Shoot()
{

}


Tank::~Tank(void)
{
}
