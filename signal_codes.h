// Authored by Mark Tomczak (iam@fixermark.com).
// Signal codes for various TV remote commands.


// TV power signal
int TVPowerToggle[] = {
// ON, OFF (in 10's of microseconds)
	884, 436,
	60, 50,
	60, 162,
	60, 160,
	62, 50,
	60, 50,
	62, 50,
	60, 50,
	60, 162,
	60, 160,
	62, 50,
	60, 160,
	62, 50,
	60, 50,
	60, 52,
	60, 50,
	60, 52,
	60, 160,
	62, 160,
	60, 160,
	60, 162,
	60, 50,
	60, 52,
	60, 50,
	60, 52,
	60, 50,
	60, 52,
	60, 50,
	60, 52,
	60, 160,
	60, 162,
	60, 160,
	60, 162,
	60, 4156,
	880, 216,
	62, 2820,
	882, 216,
	60, 2822,
	882, 216,
	60, 2822,
	882, 216,
	60, 2822,
	880, 216,
	62, 2822,
	880, 216,
	62, 0,
	62, 0,
	0, 0};

// TV input select
int TVInput[] = {
// ON, OFF (in 10's of microseconds)
884, 436,
	60, 52,
	60, 160,
	60, 162,
	60, 50,
	62, 50,
	60, 50,
	60, 52,
	60, 160,
	60, 162,
	60, 50,
	60, 162,
	60, 50,
	62, 50,
	60, 50,
	60, 52,
	60, 50,
	60, 162,
	60, 50,
	62, 160,
	60, 160,
	60, 162,
	60, 50,
	60, 52,
	60, 50,
	60, 52,
	60, 160,
	62, 50,
	60, 50,
	60, 52,
	60, 160,
	60, 162,
	60, 160,
	62, 4154,
	882, 216,
	60, 2822,
	882, 216,
	60, 2824,
	880, 216,
	60, 2824,
	880, 218,
	60, 2822,
	880, 218,
	60, 2822,
	882, 216,
	60, 2822,
	882, 216,
	60, 2824,
	880, 216,
	60, 2824,
	880, 216,
	62, 2822,
	880, 218,
	60, 2822,
	882, 216,
	60, 2822,
	882, 216,
	60, 2824,
	880, 216,
	60, 1786,
	10, 0,
	10, 0,
	0, 0};

//TV up arrow
int TVUpArrow[] = {
// ON, OFF (in 10's of microseconds)
	884, 436,
	60, 52,
	60, 160,
	60, 160,
	62, 50,
	60, 50,
	62, 50,
	60, 52,
	60, 160,
	60, 160,
	62, 50,
	60, 160,
	62, 50,
	60, 50,
	62, 50,
	60, 52,
	60, 50,
	60, 50,
	62, 160,
	60, 50,
	62, 50,
	60, 50,
	62, 50,
	60, 162,
	60, 50,
	60, 160,
	62, 50,
	60, 160,
	60, 162,
	60, 162,
	60, 160,
	60, 50,
	62, 160,
	60, 4156,
	880, 216,
	62, 2822,
	880, 216,
	62, 2822,
	880, 216,
	62, 2822,
	880, 216,
	60, 2824,
	880, 216,
	60, 2824,
	880, 216,
	62, 2822,
	880, 216,
	60, 0,
	60, 0,
	0, 0};


// TV down arrow
int TVDownArrow[] = {
// ON, OFF (in 10's of microseconds)
	12, 3653,
	882, 438,
	58, 54,
	58, 162,
	58, 164,
	58, 52,
	58, 54,
	58, 52,
	58, 54,
	58, 162,
	58, 164,
	58, 52,
	58, 164,
	58, 52,
	58, 54,
	56, 54,
	58, 54,
	58, 52,
	58, 164,
	58, 162,
	58, 54,
	58, 52,
	58, 54,
	56, 54,
	58, 164,
	58, 52,
	58, 52,
	60, 52,
	58, 164,
	58, 162,
	58, 164,
	56, 164,
	58, 52,
	60, 162,
	58, 4158,
	878, 218,
	60, 2824,
	878, 220,
	56, 2826,
	878, 218,
	58, 2822,
	882, 218,
	58, 2822,
	880, 220,
	58, 216,
	58, 0,
	0, 0};


// TV Enter
int TVEnter[] = {
// ON, OFF (in 10's of microseconds)
	882, 438,
	60, 50,
	60, 160,
	62, 160,
	60, 50,
	60, 52,
	60, 50,
	62, 50,
	60, 160,
	62, 160,
	60, 50,
	60, 162,
	60, 50,
	62, 50,
	60, 50,
	62, 50,
	60, 50,
	62, 50,
	60, 50,
	60, 52,
	60, 160,
	60, 162,
	60, 50,
	62, 50,
	60, 50,
	62, 160,
	60, 160,
	60, 162,
	60, 50,
	62, 50,
	60, 160,
	62, 160,
	60, 160,
	60, 4158,
	880, 216,
	60, 2822,
	882, 216,
	60, 2822,
	882, 216,
	60, 2822,
	882, 216,
	60, 2824,
	880, 216,
	60, 220,
	60, 0,
	0, 0};

// Cable "D" button, STB
int CableD[] = {
// ON, OFF (in 10's of microseconds)
	882, 438,
	50, 440,
	48, 218,
	50, 218,
	50, 438,
	50, 216,
	50, 438,
	50, 218,
	50, 216,
	50, 218,
	50, 216,
	50, 218,
	50, 218,
	48, 440,
	50, 216,
	50, 438,
	50, 218,
	50, 3016,
	882, 216,
	50, 2072,
	882, 216,
	50, 2072,
	880, 218,
	50, 2072,
	880, 218,
	50, 2070,
	882, 218,
	48, 2072,
	882, 216,
	50, 0,
	50, 0,
0, 0};

// Aux configured for Microsoft (code 1999 on Philips RC 1445302 and RC 1445301,
// Motorola DRC800, and Scientific-Atlanta AT8550 AllTouch remote controls)
// Note: These codes have been manually trimmed and are intended to be used for
// matching, not transmission (they lack repetition of the code word for
// reliable reception).

// OK button
int MicrosoftOK[] = {
// ON, OFF (in 10's of microseconds)
	262, 88,
	44, 42,
	44, 42,
	44, 86,
	44, 86,
	130, 86,
	44, 42,
	46, 42,
	44, 42,
	44, 42,
	44, 44,
	44, 42,
	44, 42,
	44, 42,
	44, 42,
	46, 42,
	84, 44,
	44, 42,
	44, 42,
	46, 88,
	44, 42,
	44, 42,
	44, 42,
	44, 44,
	84, 88,
	44, 44,
	44, 42,
	44, 42,
	84, 90,
	44, 42,
	44, 44,
	84, 88,
	46, 208,
	260, 0};


// Left Arrow
int MicrosoftLeftArrow[] = {
// ON, OFF (in 10's of microseconds)
	262, 86,
	44, 44,
	44, 42,
	44, 86,
	44, 84,
	132, 86,
	44, 42,
	44, 42,
	44, 44,
	44, 42,
	44, 42,
	44, 42,
	46, 42,
	44, 42,
	44, 42,
	44, 44,
	84, 44,
	44, 42,
	44, 42,
	44, 44,
	42, 88,
	44, 44,
	44, 42,
	44, 42,
	86, 88,
	44, 42,
	44, 44,
	44, 42,
	84, 90,
	44, 42,
	44, 42,
	44, 42,
	46, 42,
	44, 210,
	260, 0};

// Right arrow
int MicrosoftRightArrow[] = {
// ON, OFF (in 10's of microseconds)
	262, 86,
	44, 42,
	44, 42,
	46, 84,
	44, 86,
	130, 86,
	44, 44,
	44, 42,
	44, 42,
	44, 42,
	44, 44,
	44, 42,
	44, 42,
	44, 46,
	42, 42,
	44, 42,
	84, 44,
	44, 42,
	44, 44,
	44, 88,
	44, 42,
	44, 42,
	44, 44,
	42, 44,
	84, 84,
	44, 44,
	42, 42,
	44, 42,
	86, 88,
	44, 42,
	44, 44,
	44, 42,
	84, 210,
	260, 0};

// Aux configured for Apex Digital (code 3858 on Philips RC 1445302 and RC 1445301,
// Motorola DRC800, and Scientific-Atlanta AT8550 AllTouch remote controls)
// Note: These codes have been manually trimmed and are intended to be used for
// matching, not transmission (they lack repetition of the code word for
// reliable reception).
int ApexLeftArrow[] = {
  // ON, OFF (in 10's of microseconds)
	888, 438,
	56, 164,
	56, 54,
	56, 54,
	54, 54,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	56, 164,
	54, 166,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 54,
	56, 164,
	56, 164,
	56, 54,
	56, 164,
	56, 54,
	56, 54,
	56, 54,
	54, 166,
	56, 52,
	56, 54,
	56, 164,
	56, 54,
	56, 164,
	56, 164,
	56, 164,
	56, 0};

int ApexOK[] = {
  // ON, OFF (in 10's of microseconds)
	888, 438,
	56, 164,
	56, 52,
	58, 52,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	54, 54,
	56, 164,
	56, 166,
	54, 166,
	54, 166,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 54,
	56, 54,
	56, 164,
	56, 54,
	56, 52,
	58, 52,
	56, 54,
	56, 54,
	56, 164,
	56, 164,
	56, 54,
	56, 164,
	56, 164,
	56, 164,
	56, 0};

int ApexRightArrow[] = {
  // ON, OFF (in 10's of microseconds)
	888, 438,
	56, 164,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	54, 54,
	56, 54,
	56, 54,
	56, 54,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 164,
	56, 166,
	54, 166,
	54, 166,
	56, 54,
	54, 164,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	56, 54,
	54, 166,
	58, 50,
	56, 164,
	58, 164,
	56, 164,
	56, 0};

