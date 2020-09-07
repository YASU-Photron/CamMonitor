#pragma once

#define TIMER_ID_UPDATE_IMG		1000
#define UPDATE_IMG_INTERVAL		15 // 30fps

#define TIMER_ID_UPDATE_TEMP	1001
#define UPDATE_TEMP_INTERVAL	1000

#define TIMER_ID_UPDATE_ANALYZE	1002
#define UPDATE_ANALYZE_INTERVAL	500

#define WM_USER_UPDATE_VIEW				(WM_USER + 101)
#define WM_USER_UPDATE_PROGRESS			(WM_USER + 102)

#define REG_CAMPANY						_T("Photron")
#define REG_SECTION_DF					_T("df")
#define REG_KEY_CAMERA_SAVE_FOLDER_PATH	_T("camerasavefolderpath")
#define REG_KEY_CAMERA_SAVE_FILE_NAME	_T("camerasavefilename")
#define REG_KEY_CAMERA_SAVE_FILE_TYPE	_T("camerasavefiletype")
#define REG_KEY_FILE_OPEN_FOLDER_PATH	_T("fileopenfolderpath")
#define REG_KEY_FILE_SAVE_FOLDER_PATH	_T("filesavefolderpath")
#define REG_KEY_FILE_SAVE_FILE_PATH		_T("filesavefilepath")

#define DEFAULT_RING_BUF_COUNT	1024

enum
{
	LIVE_MODE = 0,
	FILE_MODE = 1,
};

typedef enum
{
	ACQUISITION_MODE_SINGLE = 0,
	ACQUISITION_MODE_CONTINUOUS = 1,
} ACQUISITION_MODE;

typedef enum
{
	SAVE_FILE_TYPE_RAW = 0,
	SAVE_FILE_TYPE_CSV = 1,
} SAVE_FILE_TYPE;

typedef enum
{
	IMAGE_QUALITY_NORMAL = 0,
	IMAGE_QUALITY_LOW = 1,
	IMAGE_QUALITY_HIGH = 2,
} IMAGE_QUALITY;

// Macro
#define GET_VIEW() (AfxGetMainWnd() ? ((CFrameWnd*)AfxGetMainWnd())->GetActiveView() : NULL);
#define GET_ACTIVE_TAB() (AfxGetMainWnd() ? ((CMainFrame*)AfxGetMainWnd())->GetActiveTab() : NULL);


// LIST

typedef struct
{
	UINT32 nSize;
	UINT32 items[256];
} ITEM_LIST, *PITEM_LIST;

typedef struct {
	UINT32 nFramerate;
	ITEM_LIST itemList;
} FRAME_RATE_TABLE, *PFRAME_RATE_TABLE;

#define	MAKE_RESO(w, h) (w << 16 | h)
#define RESO_W(r) (r >> 16 & 0x0000ffff)
#define RESO_H(r) (r & 0x0000ffff)

#define MAX_FRAMERATE_COUNT 21

const FRAME_RATE_TABLE FramerateShutterTable[MAX_FRAMERATE_COUNT] =
{
	{ 1,
	{ 22, { 1, 10, 50, 100, 125, 250, 500, 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 10,
	{ 21, { 10, 50, 100, 125, 250, 500, 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 50,
	{ 20, { 50, 100, 125, 250, 500, 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 100,
	{ 19, { 100, 125, 250, 500, 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 125,
	{ 18, { 125, 250, 500, 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 250,
	{ 17, { 250, 500, 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 500,
	{ 16, { 500, 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 950,
	{ 15, { 950, 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 1000,
	{ 14, { 1000, 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 1500,
	{ 13, { 1500, 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 2000,
	{ 12, { 2000, 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 2500,
	{ 11, { 2500, 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 3000,
	{ 10, { 3000, 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 3200,
	{ 9, { 3200, 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 4000,
	{ 8, { 4000, 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 5000,
	{ 7, { 5000, 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 8000,
	{ 6, { 8000, 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 10000,
	{ 5, { 10000, 20000, 25000, 30000, 40000 } },
	},
	{ 20000,
	{ 4, { 20000, 25000, 30000, 40000 } },
	},
	{ 25000,
	{ 3, { 25000, 30000, 40000 } },
	},
	{ 30000,
	{ 2, { 30000, 40000 } },
	},
};
