#include "efi.h"
#include "efiutil.h"

EFI_STATUS efi_main(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *Table)
{
	CHAR16 msg[] = u"hello world";
	EFI_STATUS status;
	status = Table->ConOut->ClearScreen(Table->ConOut);
	if (status) {
		return status;
	}
	status = Print(Table, msg);
	if (status) {
		return status;
	}
	return 0;
}
