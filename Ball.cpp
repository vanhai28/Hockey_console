#include "Ball.h"



Ball::Ball()
{
}


Ball::~Ball()
{
}

Ball::Ball(int x, int y) {
	_x = x;
	_y = y;
	_ox = _x;
	_oy = _y;
	_vx = _vy = 0;
}

// Input: h(con tro su dung voi man hinh console)
// Output: Qua bong
// Chuc nang: Ve qua bong
void Ball::Draw(HANDLE& h) {
	SetConsoleTextAttribute(h, 15);
	gotoXY(_ox, _oy,h);

	//Xoa vi tri cu
	cout << ' ';
	//Vi tri moi
	gotoXY(_x, _y, h);
	SetConsoleTextAttribute(h, 6);
	//Ve vi tri moi
	cout <<(char)(233);

	SetConsoleTextAttribute(h, 15);
	//Gan toa do vi tri moi vao _ox _oy de xu ly tiep khi bong di chuyen
	_ox = _x;
	_oy = _y;
}



bool Ball:: checkBallCollideBox(vector<Box>& list, int& score)
{
	int size = list.size();
	char maxBox = 3;//Toi da bong chi cham duoc ba Box
	bool isCollide = false;//kiem tra trang thai va cham
	bool flag = false;//kiem tra neu dong thoi va cham goc va giua thi uu tien va cham giua
	Box* p = NULL;//chua dia chi box xay ra va cham goc

	for (int i = 0; i < size; i++)
	{
		//va cham o giua
		if (!list[i].IsBreak() && ((_y == list[i].Y() + 1 && _vy < 0)
			|| (_y == list[i].Y() - 1 && _vy > 0))
			&& _x < list[i].X() + list[i].Width() && _x >= list[i].X())
		{
			list[i].hideBox();  //xoa box
			score += list[i].Score();  //tang diem
			isCollide = true;  //danh dau co va cham
			_vy *= (- 1);   //doi huong
			flag = true;   //da co va cham khac va cham goc

		}//va cham hai ben
		else if (!list[i].IsBreak() && _y == list[i].Y() && (_x == list[i].X() + list[i].Width() || _x == list[i].X() - 1) && _vx!= 0)
		{
			list[i].hideBox();//xoa box
			score += list[i].Score();//tang diem
			isCollide = true;//danh dau co va cham
			_vx *= -1;//doi huong
			flag = true;//da co va cham khac va cham goc
		}
		//va cham o goc nhon
<<<<<<< Updated upstream
		if (!list[i].IsBreak() && _y - 1 == list[i].Y() && ((_x == list[i].X() + list[i].Width() && _vx < 0) || (_x == list[i].X() - 1 && _vx > 0)))
=======
		if (!list[i].IsBreak() && ((_x == list[i].X() + list[i].Width() && _vx < 0) || (_x == list[i].X() - 1 && _vx > 0)) 
			&&((_y - 1 == list[i].Y() && _vy<0)	||(_y +1 == list[i].Y() && _vy > 0)))
>>>>>>> Stashed changes
		{
			//luu dia chi box bi va cham
			p = &list[i];

		}
		//va vao ben trong box
		if (!list[i].IsBreak() && _y == list[i].Y() && _x < list[i].X() + list[i].Width() && _x >= list[i].X())
		{
			list[i].hideBox();//xoa box
			score += list[i].Score();//tang diem nguoi choi
			isCollide = true;//danh dau box da bi vo
			//doi huong bong
			_vy *= -1;
			_vx *=  -1;
			break;
		}
	}

	if (!flag && p)//neu chi co va cham goc thi xu li
	{
		p->hideBox();//xoa box
		score += p->Score();//tang diem
		isCollide = true;//danh dau da va cham
		//doi huong bong
		_vy *= -1;
		_vx *= -1;
	}

	return isCollide;
}