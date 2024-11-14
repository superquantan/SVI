#include "efidefs.h"
#include "efi.h"
#include "efiutil.h"
#include <stddef.h>

EFI_STATUS efi_main(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *Table)
{
	CHAR16 msg[] = u"hello world, enter some characters, the program should terminate on ESC\r\n";
	EFI_INPUT_KEY Key;
	Key.UnicodeChar = 0;
	EFI_STATUS status;
	UINTN KeyEvent = 0;
	CHAR16 chars[2];
	chars[1] = 0;
	status = Table->ConOut->ClearScreen(Table->ConOut);
	if (status) {
		return status;
	}
	status = Print(Table, msg);
	if (status) {
		return status;
	}

	if (status) {
		return status;
	}
	do {
		chars[0] = Key.UnicodeChar;
		Print(Table, chars);
		Table->BootServices->WaitForEvent((UINTN) 1, &Table->ConIn->WaitForKey, &KeyEvent);
		Table->ConIn->ReadKeyStroke(Table->ConIn, &Key);
		Table->ConIn->Reset(Table->ConIn, FALSE);
	} while ((UINTN)Key.ScanCode != 0x17);
	return 0;
}

VOID *memcpy(void *dest, const void *src, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		((char *)dest)[i] = ((char *)src)[i];
	}
}
