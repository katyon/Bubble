#pragma once

// íËêî ----------------------------------------------------------------

// ÉNÉâÉX --------------------------------------------------------------
#define SYSTEM (System::getInstance())
class System
{
public:
	System(const System&) = delete;
	System& operator=(const System&) = delete;
	System(System&&) = delete;
	System& operator=(System&&) = delete;
	static System& getInstance()
	{
		static System instance;
		return instance;
	}

    void    drawDebugString();

private:
	System() = default;
	~System() = default;

    unsigned int cr = 0;

};