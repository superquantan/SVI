#include "efidefs.h"
#include "efi.h"
#include "efiutil.h"

EFI_STATUS efi_main(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *Table)
{
	CHAR16 msg[] = u"hello world";
	EFI_STATUS status;
	UINTN KeyEvent = 0;
	status = Table->ConOut->ClearScreen(Table->ConOut);
	if (status) {
		return status;
	}
	status = Print(Table, msg);
	if (status) {
		return status;
	}

	status = Table->ConIn->Reset(Table->ConIn, FALSE);
	if (status) {
		return status;
	}
	status = Table->BootServices->WaitForEvent((UINTN) 1, &Table->ConIn->WaitForKey, &KeyEvent);
	return 0;
}
