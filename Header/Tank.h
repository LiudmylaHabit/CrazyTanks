
class Tank
{
public:
	Tank(void);
	~Tank(void);

	int direction_index;
	int coordinate[2];

	void Move(int);
	void Shoot(void);
};
