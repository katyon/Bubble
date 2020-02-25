#pragma once
// ’è” ----------------------------------------------------------------

// ƒNƒ‰ƒX --------------------------------------------------------------
#define SYSTEM (System::getInstance())
class System : public Singleton<System>
{
public:
	void    drawDebugString(void);

private:
	unsigned int cr = 0;
};