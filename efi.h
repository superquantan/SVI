#ifndef EFI_H
#define EFI_H
#include <stdint.h>
typedef char BOOLEAN;
typedef int64_t INTN;
typedef uint64_t UINTN;
typedef int8_t INT8;
typedef uint8_t UINT8;
typedef int16_t INT16;
typedef uint16_t UINT16;
typedef int32_t INT32;
typedef uint32_t UINT32;
typedef int64_t INT64;
typedef uint64_t UINT64;
typedef __int128 INT128;
typedef unsigned __int128 UINT128;
typedef char CHAR8;
typedef uint16_t CHAR16;
typedef void VOID;
typedef struct {
	UINT32 pars1;
	UINT16 pars2;
	UINT16 pars3;
	UINT8 pars4[8];
} EFI_GUID;
typedef UINTN EFI_STATUS;
typedef VOID * EFI_HANDLE;
typedef VOID * EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;
typedef struct {
	UINT8 addr[32];
} EFI_MAC_ADDRESS;
typedef struct {
	UINT8 addr[4];
} EFI_IPv4_ADDRESS;
typedef struct {
	UINT8 addr[16];
} EFI_IPv6_ADDRESS;
typedef struct {
	UINT8 addr1[4];
	UINT8 addr2[4];
	UINT8 addr3[4];
	UINT8 addr4[4];
} EFI_IP_ADDRESS;
typedef struct {
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;
typedef struct {
	UINT16 ScanCode;
	CHAR16 UnicodeChar;
} EFI_INPUT_KEY;
typedef struct {
	INT32 MaxMode;
	INT32 Mode;
	INT32 Attribute;
	INT32 CursorColumn;
	INT32 CursorRow;
	BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;
typedef enum {
	TimerCancel,
	TimerPeriodic,
	TimerRelative
} EFI_TIMER_DELAY;
typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;
typedef VOID (*EFI_EVENT_NOTIFY)(
	EFI_EVENT Event,
	VOID *Context
);
typedef EFI_STATUS (*EFI_INPUT_RESET)(
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
	BOOLEAN ExtendedVerification
);
typedef EFI_STATUS (*EFI_INPUT_READ_KEY)(
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
	EFI_INPUT_KEY *Key);
typedef EFI_STATUS (*EFI_TEXT_RESET)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	BOOLEAN ExtendedVerification
);
typedef EFI_STATUS (*EFI_TEXT_STRING)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	CHAR16 *String
);
typedef EFI_STATUS (*EFI_TEXT_TEST_STRING)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	CHAR16 *String
);
typedef EFI_STATUS (*EFI_TEXT_QUERY_MODE)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	UINTN ModeNumber,
	UINTN *Columns,
	UINTN *Rows
);
typedef EFI_STATUS (*EFI_TEXT_SET_MODE)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	UINTN ModeNumber
);
typedef EFI_STATUS (*EFI_TEXT_SET_ATTRIBUTE)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	UINTN Attribute
);
typedef EFI_STATUS (*EFI_TEXT_CLEAR_SCREEN)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This
);
typedef EFI_STATUS (*EFI_TEXT_SET_CURSOR_POSITION)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	UINTN Column,
	UINTN Row
);
typedef EFI_STATUS (*EFI_TEXT_ENABLE_CURSOR)(
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
	BOOLEAN Visible
);
typedef EFI_STATUS (*EFI_NOTIFY)(
	EFI_EVENT Event,
	VOID *Context
);
typedef EFI_STATUS (*EFI_CREATE_EVENT)(
	UINT32 Type,
	EFI_TPL NotifyTpl,
	EFI_EVENT_NOTIFY NotifyFunction,
	VOID *NotifyContext,
	EFI_EVENT *Event
);
typedef EFI_STATUS (*EFI_CREATE_EVENT_EX)(
	UINT32 Type,
	EFI_TPL NotifyTpl,
	EFI_EVENT_NOTIFY NotifyFunction,
	VOID *NotifyContext,
	EFI_GUID *EventGroup,
	EFI_EVENT *Event
);
typedef EFI_STATUS (*EFI_CLOSE_EVENT)(
	EFI_EVENT Event
);
typedef EFI_STATUS (*EFI_SIGNAL_EVENT)(
	EFI_EVENT Event
);
typedef EFI_STATUS (*EFI_WAIT_FOR_EVENT)(
	UINTN NumberOfEvents,
	EFI_EVENT *Event,
	UINTN *Index
);
typedef EFI_STATUS (*EFI_CHECK_EVENT)(
	EFI_EVENT Event
);
typedef EFI_STATUS (*EFI_SET_TIMER)(
	EFI_EVENT Event,
	EFI_TIMER_DELAY Type,
	UINT64 TriggerTime
);
typedef EFI_TPL (*EFI_RAISE_TPL)(
	EFI_TPL NewTpl
);
typedef VOID (*EFI_RESTORE_TPL)(
	EFI_TPL OldTpl
);
struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
	EFI_INPUT_RESET Reset;
	EFI_INPUT_READ_KEY ReadKeyStroke;
	EFI_EVENT WaitForKey;
};
struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
	EFI_TEXT_RESET Reset;
	EFI_TEXT_STRING OutputString;
	EFI_TEXT_TEST_STRING TestString;
	EFI_TEXT_QUERY_MODE QueryMode;
	EFI_TEXT_SET_MODE SetMode;
	EFI_TEXT_SET_ATTRIBUTE SetAttribute;
	EFI_TEXT_CLEAR_SCREEN ClearScreen;
	EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
	EFI_TEXT_ENABLE_CURSOR EnableCursor;
	SIMPLE_TEXT_OUTPUT_MODE *Mode;
};
typedef struct {
	EFI_TABLE_HEADER Hdr;
	EFI_RAISE_TPL RaiseTPL;
	EFI_RESTORE_TPL RestoreTPL;
	VOID *AllocatePages;
	VOID *FreePages;
	VOID *GetMemoryMap;
	VOID *AllocatePool;
	VOID *FreePool;
	EFI_CREATE_EVENT CreateEvent; 
	EFI_SET_TIMER SetTimer; 
	EFI_WAIT_FOR_EVENT WaitForEvent; 
	EFI_SIGNAL_EVENT SignalEvent; 
	EFI_CLOSE_EVENT CloseEvent; 
	EFI_CHECK_EVENT CheckEvent; 
	VOID *InstallProtocolInterface; 
	VOID *ReinstallProtocolInterface; 
	VOID *UninstallProtocolInterface; 
	VOID *HandleProtocol; 
	VOID *Reserved; 
	VOID *RegisterProtocolNotify; 
	VOID *LocateHandle; 
	VOID *LocateDevicePath; 
	VOID *InstallConfigurationTable; 
	VOID *LoadImage; 
	VOID *StartImage; 
	VOID *Exit; 
	VOID *UnloadImage; 
	VOID *ExitBootServices; 
	VOID *GetNextMonotonicCount; 
	VOID *Stall; 
	VOID *SetWatchdogTimer; 
	VOID *ConnectController; 
	VOID *DisconnectController; 
} EFI_BOOT_SERVICES;
typedef struct {
	EFI_TABLE_HEADER Hdr;
	CHAR16 *FirmwareVendor;
	UINT32 FirmwareRevision;
	EFI_HANDLE ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
	EFI_HANDLE ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
	EFI_HANDLE StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
	VOID *RuntimeServices;
	EFI_BOOT_SERVICES *BootServices;
	UINTN NumberOfTableEntries;
	VOID *ConfigurationTable;
} EFI_SYSTEM_TABLE;
#endif
